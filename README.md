# GLSlayer

OpenGL Sanity Layer is an object-oriented 3D graphics API on top of OpenGL written in C++. It is designed not just to provide an encapsulation of OpenGL objects, but to provide a cleaner and more streamlined interface similar to Direct3D and hide some of OpenGL's weak spots such as bind-to-edit semantics, multiple stage object creation, unavailability of platform independent initialization and loading of extensions to expose features. With GLSlayer it is easy to create a rendering context just by filling a structure and calling a function. All extensions needed to expose features for requested OpenGL version are loaded automatically. The code needed to create, setup and use objects is reduced and made intuitive. It supports only forward compatible contexts, version 3.3 and up. However, it requires some of the extensions to always be present, such as:

* GL_ARB_separate_shader_objects
* GL_ARB_viewport_array
* GL_ARB_base_instance
* GL_ARB_texture_storage
* GL_ARB_explicit_uniform_location
* GL_KHR_debug
* GL_ARB_buffer_storage

## Building

##### On Linux

- With CMake:
```
$ cd GLSlayer
$ mkdir build
$ cd build
$ cmake ..
$ make
```
  The output will be in GLSlayer/build/bin directory.
- With Qt Creator: there is a Qt Creator project file in projects/qtcreator directory.

##### On Windows

- With Visual Studio 2015: there is a solution file in projects/vs2015 directory.
- CMake: if you want to generate a solution for an older version of VS.

Qt projects currently need to be fixed for Windows.

## Usage Example

This is a simplified example of rendering (only GLSlayer calls and no error checking). If you want to see full example, check out the samples directory.

```
// --- Creating a rendering context ---

// Fill framebuffer format structure.
gls::FramebufferFormat format;
format.colorBits = 32;
format.colorBufferType = gls::COLOR_BUFFER_TYPE_RGBA;
format.depthBits = 0;
format.stencilBits = 0;
format.doubleBuffer = true;
format.multisampleSamples = 0;
format.sRGB = false;
format.swapMethod = gls::SWAP_EXCHANGE;

// On Linux, we need to get XVisualInfo for given display and framebuffer format
// so we can use it to create the window.
#if defined (__linux__)
gls::XGetVisualInfo(_display, format, visualInfo);
#endif

// Create the window here
// ...

// Fill context info struct and create the context.
gls::CreateContextInfo info;
info.version = 430;     // Request OpenGL 4.3
info.debugContext = false;
info.format = &format;
#if defined (_WIN32)
info.instanceHandle = _hinstance;   // HINSTANCE
info.windowHandle = _hwnd;          // HWND
#elif defined (__linux__)
info.display = _display;    // pointer ot X Display struct
info.window = _window;      // X Window handle
#endif
info.logger = nullptr;

_context = CreateRenderContext(info);

// --- Rendering ---

// Create resources.
gls::VertexShader* vs = _context->CreateVertexShader(1, vsSources, success);
gls::FragmentShader* fs = _context->CreateFragmentShader(1, fsSources, success);

Vertex vertices[] = { /* ... */ };
gls::Buffer* vertBuf = _context->CreateBuffer(gls::VERTEX_BUFFER, sizeof(vertices), vertices, 0);
gls::Buffer* vsUniforms = _context->CreateBuffer(gls::UNIFORM_BUFFER, sizeof(mat4f), nullptr, gls::BUFFER_DYNAMIC_STORAGE_BIT);

gls::VertexAttribDesc vertDesc[] = {
	{ 0, 0, 3, gls::TYPE_FLOAT, false, false, 0, 0 },     // position
	{ 0, 1, 4, gls::TYPE_FLOAT, false, false, 12, 0 },    // color
};
gls::VertexFormat* vertFmt = _context->CreateVertexFormat(2, vertDesc);

// Render.
_context->Viewport(0, 0, width, height);                // Set viewport transform
float color[] = { 0.0f, 0.0f, 0.0f, 0.0f };
_context->ClearColorBuffer(nullptr, 0, color);          // Clear default framebuffer's color buffer
_context->VertexSource(0, vertBuf, sizeof(Vertex), 0);  // We are taking vertices from this buffer...
_context->ActiveVertexFormat(vertFmt);                  // ... and this is their format
_context->SetVertexShader(vs);                          // Set current vertex shader
_context->SetFragmentShader(fs);                        // Set current fragment shader
vsUniforms->BufferSubData(0, sizeof(mat4f), _projMat);  // Update shader uniform data
_context->SetUniformBuffer(0, vsUniforms);              // Set uniform buffer at binding 0

_context->Draw(gls::PRIM_TRIANGLES, 0, 3);              // Draw

_context->SwapBuffers();                                // Present backbuffer

// Cleanup.
_context->DestroyShader(vs);
_context->DestroyShader(fs);
_context->DestroyBuffer(vertBuf);
_context->DestroyBuffer(vsUniforms);
_context->DestroyVertexFormat(vertFmt);

gls::DestroyRenderContext(_context);
```
You might have noticed that there is a logger field in CreateContextInfo that we set to null. If you want to get debugging messages or error descriptions from OpenGL or GLSlayer, or even insert your own, you need to define a logger class derived from gls::IDebugLogger, instantiate it and set a pointer to it in CreateContextInfo:

```
class MyLogger : public gls::IDebugLogger
{
public:
  virtual void DebugMessage(gls::DebugMessageSource source,
                            gls::DebugMessageType type,
                            gls::uint id,
                            gls::DebugMessageSeverity severity,
                            const char* message) override
  {
    if (type == gls::DEBUG_SOURCE_THIRD_PARTY)
    {
      // This is a message from GLSlayer.
    }
    
		printf("%s\n", message);
		// ... or log to file, or whatever.
  }
};

MyLogger* loger = new MyLogger;
//...
info.logger = logger;
//...

// Enable debug output.
_context->EnableDebugOutput(true, true);
_context->EnableDebugMessages(gls::DEBUG_SOURCE_ALL, gls::DEBUG_TYPE_ALL, gls::DEBUG_SEVERITY_ALL, true);

// Insert your own messages.
_context->InsertDebugMessage(
          gls::DEBUG_SOURCE_APPLICATION,
          gls::DEBUG_TYPE_ERROR,
          gls::DEBUG_SEVERITY_HIGH,
          "Something bad happened");
```

Also, setting info.debugContext to true will provide additional checking, validation and logging for OpenGL context.
