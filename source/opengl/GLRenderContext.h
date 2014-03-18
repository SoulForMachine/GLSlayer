
#ifndef _GL_RENDER_CONTEXT_H_
#define _GL_RENDER_CONTEXT_H_

#include "GLCommon.h"
#include "GLSlayer/RenderContext.h"
#include "GLFramebuffer.h"
#include "GLBuffer.h"
#include "GLVertexFormat.h"
#include "GLShader.h"
#include "GLTexture.h"
#include "GLSamplerState.h"
#include "GLQuery.h"
#include "GLTransformFeedback.h"
#include "GLContextInfo.h"
#include "GLSlayerMessages.h"



#define LOAD_EXTENSION(ext, flag) \
	_info.flag = IsExtSupported(#ext); \
	if(_info.flag){ \
		_info.flag = glextLoad_##ext(); \
		if(!_info.flag) DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_EXTENSION_MISSING_ENTRIES, #ext); } \
		else { DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_UNSUPPORTED_EXTENSION, #ext); }

#define LOAD_EXTENSION_REQ(ext, flag) \
	_info.flag = IsExtSupported(#ext); \
	if(_info.flag){ \
		_info.flag = glextLoad_##ext(); \
		if(!_info.flag){ \
			DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_EXTENSION_MISSING_ENTRIES, #ext); \
			result = false; } } \
	else{ \
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_UNSUPPORTED_EXTENSION, #ext); \
		result = false; }

#define CHECK_EXTENSION(ext, flag) \
	_info.flag = IsExtSupported(#ext); \
	if(!_info.flag) \
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_UNSUPPORTED_EXTENSION, #ext);

#define CHECK_EXTENSION_REQ(ext, flag) \
	_info.flag = IsExtSupported(#ext); \
	if(!_info.flag){ \
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_UNSUPPORTED_EXTENSION, #ext); \
		result = false; }

#define LOAD_VERSION(ext, flag) \
	_info.flag = glextLoad_##ext(); \
	if(!_info.flag) \
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_EXTENSION_MISSING_ENTRIES, #ext);

#define LOAD_VERSION_REQ(ext, flag) \
	_info.flag = glextLoad_##ext(); \
	if(!_info.flag){ \
		DebugMessage(DEBUG_SOURCE_THIRD_PARTY, DEBUG_TYPE_ERROR, DEBUG_SEVERITY_NOTIFICATION, MESSAGE_ERROR_EXTENSION_MISSING_ENTRIES, #ext); \
		result = false; }


class GLRenderContext : public gls::IRenderContext
{
public:
	GLRenderContext(gls::IDebugLogger* logger);
	~GLRenderContext();

#if defined(_WIN32)
	bool Create(gls::uint version, HINSTANCE instance_handle, HWND window_handle, const gls::FramebufferFormat& format, bool debug_context);
#elif defined(__linux__)
	bool Create(gls::uint version, Display* display, Window window, const gls::FramebufferFormat& format, bool debug_context);
#endif

	void Destroy();

	bool SetCurrentContext();
	const gls::ContextInfo& GetInfo() const
		{ return _info; }

	// vertex stream
	void VertexSource(int stream, gls::IBuffer* buffer, size_t stride, size_t offset);
	void IndexSource(gls::IBuffer* buffer, gls::DataType index_type);
	void ActiveVertexFormat(gls::IVertexFormat* format);
	void EnablePrimitiveRestart(bool enable);
	void EnablePrimitiveRestartFixedIndex(bool enable);
	void PrimitiveRestartIndex(gls::uint index);
	void ProvokingVertex(gls::VertexConvention vertex_convention);

	// tessellation
	void PatchVertexCount(int count);
	void PatchDefaultOuterLevels(float values[4]);
	void PatchDefaultInnerLevels(float values[2]);

	// conditional render
	void BeginConditionalRender(gls::IQuery* query, gls::ConditionalRenderMode mode);
	void EndConditionalRender();

	// transform feedback
	void BeginTransformFeedback(gls::PrimitiveType primitive, gls::ITransformFeedback* transform_feedback);
	void EndTransformFeedback();
	void PauseTransformFeedback();
	void ResumeTransformFeedback();

	// viewport transform
	void Viewport(int x, int y, int width, int height);
	void ViewportIndexed(gls::uint index, float x, float y, float width, float height);

	// back face culling
	void EnableFaceCulling(bool enable);
	void CullFace(gls::PolygonFace face);
	void FrontFace(gls::VertexOrder orient);

	// rasterization
	void RasterizationMode(gls::RasterMode mode);
	void EnableRasterizerDiscard(bool enable);

	// multisampling
	void EnableMultisampling(bool enable);
	void EnableSampleAlphaToCoverage(bool enable);
	void EnableSampleAlphaToOne(bool enable);
	void EnableSampleCoverage(bool enable);
	void EnableSampleShading(bool enable);
	void SampleCoverage(float value, bool invert);
	void SampleMask(gls::uint index, gls::uint mask);
	void GetSamplePosition(gls::uint index, float position[2]);
	void MinSampleShading(float value);

	// scissor test
	void EnableScissorTest(bool enable);
	void EnableScissorTestIndexed(gls::uint index, bool enable);
	void Scissor(int x, int y, int width, int height);
	void ScissorIndexed(gls::uint index, int x, int y, int width, int height);

	// depth test
	void EnableDepthTest(bool enable);
	void DepthTestFunc(gls::CompareFunc func);
	void DepthRange(float dnear, float dfar);
	void DepthRangeIndexed(gls::uint index, float dnear, float dfar);
	void DepthOffset(float factor, float units);
	void EnableDepthClamp(bool enable);

	// stencil test
	void EnableStencilTest(bool enable);
	void StencilFunc(gls::PolygonFace face, gls::CompareFunc func, int ref, gls::uint mask);
	void StencilOperation(gls::PolygonFace face, gls::StencilOp stencil_fail, gls::StencilOp depth_fail, gls::StencilOp depth_pass);

	// blending
	void EnableBlending(bool enable);
	void EnableBlending(gls::uint buffer, bool enable);
	void BlendingColor(float color[4]);
	void BlendingFunc(gls::BlendFunc src_factor, gls::BlendFunc dest_factor);
	void BlendingFunc(gls::BlendFunc src_rgb_factor, gls::BlendFunc dest_rgb_factor, gls::BlendFunc src_alpha_factor, gls::BlendFunc dest_alpha_factor);
	void BlendingFunc(gls::uint buffer, gls::BlendFunc src_factor, gls::BlendFunc dest_factor);
	void BlendingFunc(gls::uint buffer, gls::BlendFunc src_rgb_factor, gls::BlendFunc dest_rgb_factor, gls::BlendFunc src_alpha_factor, gls::BlendFunc dest_alpha_factor);
	void BlendingOperation(gls::BlendOp op);
	void BlendingOperation(gls::BlendOp op_rgb, gls::BlendOp op_alpha);
	void BlendingOperation(gls::uint buffer, gls::BlendOp op);
	void BlendingOperation(gls::uint buffer, gls::BlendOp op_rgb, gls::BlendOp op_alpha);

	// logic operation
	void EnableLogicOperation(bool enable);
	void LogicOperation(gls::LogicOp op);

	// framebuffer
	void SetFramebuffer(gls::IFramebuffer* fbuf);
	void ActiveColorBuffers(gls::IFramebuffer* fbuf, size_t count, const gls::ColorBuffer* buffers);
	void EnableFramebufferSRGB(bool enable);
	void EnableColorWrite(bool r, bool g, bool b, bool a);
	void EnableColorWrite(gls::uint buffer, bool r, bool g, bool b, bool a);
	void EnableDepthWrite(bool enable);
	void EnableStencilWrite(gls::PolygonFace face, gls::uint mask);
	void ClearColorBuffer(gls::IFramebuffer* fbuf, gls::uint buffer, float color[4]);
	void ClearColorBuffer(gls::IFramebuffer* fbuf, gls::uint buffer, int color[4]);
	void ClearColorBuffer(gls::IFramebuffer* fbuf, gls::uint buffer, gls::uint color[4]);
	void ClearDepthBuffer(gls::IFramebuffer* fbuf, float depth);
	void ClearStencilBuffer(gls::IFramebuffer* fbuf, int stencil);
	void ClearDepthStencilBuffer(gls::IFramebuffer* fbuf, float depth, int stencil);
	void ReadPixels(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, gls::ColorReadClamp color_clamp, int x, int y, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* buffer);
	void ReadPixels(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, gls::ColorReadClamp color_clamp, int x, int y, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void BlitFramebuffer(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int src_x0, int src_y0, int src_x1, int src_y1, gls::IFramebuffer* dest_fbuf, int dest_x0, int dest_y0, int dest_x1, int dest_y1, gls::uint buffers, gls::TexFilter filter);
	void SwapBuffers();
	void SwapInterval(int interval);

	// shaders
	void SetVertexShader(gls::IVertexShader* shader);
	void SetTessControlShader(gls::ITessControlShader* shader);
	void SetTessEvaluationShader(gls::ITessEvaluationShader* shader);
	void SetGeometryShader(gls::IGeometryShader* shader);
	void SetFragmentShader(gls::IFragmentShader* shader);
	void SetComputeShader(gls::IComputeShader* shader);
	void SetUniformBuffer(gls::uint index, gls::IBuffer* buffer);
	void SetUniformBuffer(gls::uint index, gls::IBuffer* buffer, size_t offset, size_t size);
	void SetAtomicCounterBuffer(gls::uint index, gls::IBuffer* buffer);
	void SetAtomicCounterBuffer(gls::uint index, gls::IBuffer* buffer, size_t offset, size_t size);
	void SetStorageBuffer(gls::uint index, gls::IBuffer* buffer);
	void SetStorageBuffer(gls::uint index, gls::IBuffer* buffer, size_t offset, size_t size);
	void UniformSubroutine(gls::ShaderType shader_type, size_t count, const gls::uint* indices);
	void SetImageTexture(gls::uint image_unit, gls::ITexture* texture, int level, bool layered, int layer, gls::BufferAccess access, gls::PixelFormat format);
	bool ValidateShaderPipeline();

	// textures and samplers
	void SetSamplerTexture(int sampler, gls::ITexture* texture);
	void SetSamplerState(int sampler, gls::ISamplerState* state);
	void EnableSeamlessCubeMap(bool enable);

	// drawing commands
	void Draw(gls::PrimitiveType prim, int first, size_t count);
	void DrawInstanced(gls::PrimitiveType prim, int first, size_t count, gls::uint base_inst, size_t inst_count);
	void DrawIndirect(gls::PrimitiveType prim, gls::IBuffer* buffer, size_t offset);
	void MultiDrawIndirect(gls::PrimitiveType prim, gls::IBuffer* buffer, size_t offset, size_t count, size_t stride);
	void DrawIndexed(gls::PrimitiveType prim, size_t index_start, int base_vertex, size_t count);
	void DrawIndexed(gls::PrimitiveType prim, size_t start, size_t end, size_t index_start, int base_vertex, size_t count);
	void DrawIndexedInstanced(gls::PrimitiveType prim, size_t index_start, int base_vertex, size_t count, gls::uint base_inst, size_t inst_count);
	void DrawIndexedIndirect(gls::PrimitiveType prim, gls::IBuffer* buffer, size_t offset);
	void MultiDrawIndexedIndirect(gls::PrimitiveType prim, gls::IBuffer* buffer, size_t offset, size_t count, size_t stride);
	void DrawTransformFeedback(gls::PrimitiveType prim, gls::ITransformFeedback* transform_feedback, gls::uint stream);
	void DrawTransformFeedbackInstanced(gls::PrimitiveType prim, gls::ITransformFeedback* transform_feedback, gls::uint stream, size_t inst_count);

	// compute commands
	virtual void DispatchCompute(gls::uint num_groups_x, gls::uint num_groups_y, gls::uint num_groups_z);
	virtual void DispatchComputeIndirect(gls::IBuffer* buffer, size_t offset);

	// synchronization
	void Flush();
	void Finish();
	gls::SyncObject InsertFenceSync(gls::FenceSyncCondition condition, gls::uint flags);
	void DeleteSync(gls::SyncObject sync);
	gls::SyncWaitStatus ClientWaitSync(gls::SyncObject sync, gls::uint flags, gls::uint64 timeout);
	void Wait(gls::SyncObject sync, gls::uint flags, gls::uint64 timeout);
	void MemoryBarrier(gls::uint flags);

	// buffer and image copying
	void CopyBufferData(gls::IBuffer* source, size_t source_offset, gls::IBuffer* dest, size_t dest_offset, size_t size);
	void CopyTextureData(
		gls::ITexture* source, int source_level, int source_x, int source_y, int source_z, int width, int height, int depth,
		gls::ITexture* dest, int dest_level, int dest_x, int dest_y, int dest_z);
	void CopyRenderbufferData(gls::IRenderbuffer* source, int source_x, int source_y, int width, int height, gls::IRenderbuffer* dest, int dest_x, int dest_y);

	// state queries
	void GetViewport(int viewport[4]);
	void GetViewport(float viewport[4]);
	void GetViewportIndexed(gls::uint index, float viewport[4]);
	gls::int64 GetGPUTimestamp();
	bool GetTextureInternalFormatInfo(gls::TextureType type, gls::PixelFormat internal_format, gls::InternalFormatInfo& info);
	bool GetRenderbufferInternalFormatInfo(gls::PixelFormat internal_format, gls::InternalFormatInfo& info);
	gls::ErrorCode GetLastError();

	// object creation

	gls::IVertexFormat* CreateVertexFormat(int count, const gls::VertexAttribDesc* descriptors);
	void DestroyVertexFormat(gls::IVertexFormat* vert_fmt);

	gls::ISamplerState* CreateSamplerState(const gls::SamplerStateDesc& descriptor);
	void DestroySamplerState(gls::ISamplerState* samp_state);

	gls::ITexture1D* CreateTexture1D(size_t levels, gls::PixelFormat internal_format, int width);
	gls::ITexture1D* CreateTexture1DView(gls::ITexture1D* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);
	gls::ITexture1D* CreateTexture1DView(gls::ITexture1DArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint layer);

	gls::ITexture1DArray* CreateTexture1DArray(size_t levels, gls::PixelFormat internal_format, int width, int height);
	gls::ITexture1DArray* CreateTexture1DArrayView(gls::ITexture1D* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);
	gls::ITexture1DArray* CreateTexture1DArrayView(gls::ITexture1DArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	gls::ITexture2D* CreateTexture2D(size_t levels, gls::PixelFormat internal_format, int width, int height);
	gls::ITexture2D* CreateTexture2DView(gls::ITexture2D* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);
	gls::ITexture2D* CreateTexture2DView(gls::ITexture2DArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint layer);
	gls::ITexture2D* CreateTexture2DView(gls::ITextureCube* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint layer);
	gls::ITexture2D* CreateTexture2DView(gls::ITextureCubeArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint layer);

	gls::ITexture2DArray* CreateTexture2DArray(size_t levels, gls::PixelFormat internal_format, int width, int height, int depth);
	gls::ITexture2DArray* CreateTexture2DArrayView(gls::ITexture2D* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);
	gls::ITexture2DArray* CreateTexture2DArrayView(gls::ITexture2DArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);
	gls::ITexture2DArray* CreateTexture2DArrayView(gls::ITextureCube* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);
	gls::ITexture2DArray* CreateTexture2DArrayView(gls::ITextureCubeArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	gls::ITexture2DMultisample* CreateTexture2DMultisample(int samples, gls::PixelFormat internal_format, int width, int height, bool fixed_sample_locations);
	gls::ITexture2DMultisample* CreateTexture2DMultisampleView(gls::ITexture2DMultisample* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);
	gls::ITexture2DMultisample* CreateTexture2DMultisampleView(gls::ITexture2DMultisampleArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);

	gls::ITexture2DMultisampleArray* CreateTexture2DMultisampleArray(int samples, gls::PixelFormat internal_format, int width, int height, int depth, bool fixed_sample_locations);
	gls::ITexture2DMultisampleArray* CreateTexture2DMultisampleArrayView(gls::ITexture2DMultisample* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);
	gls::ITexture2DMultisampleArray* CreateTexture2DMultisampleArrayView(gls::ITexture2DMultisampleArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	gls::ITexture3D* CreateTexture3D(size_t levels, gls::PixelFormat internal_format, int width, int height, int depth);
	gls::ITexture3D* CreateTexture3DView(gls::ITexture3D* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);

	gls::ITextureCube* CreateTextureCube(size_t levels, gls::PixelFormat internal_format, int width);
	gls::ITextureCube* CreateTextureCubeView(gls::ITextureCube* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);
	gls::ITextureCube* CreateTextureCubeView(gls::ITextureCubeArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);
	gls::ITextureCube* CreateTextureCubeView(gls::ITexture2DArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	gls::ITextureCubeArray* CreateTextureCubeArray(size_t levels, gls::PixelFormat internal_format, int width, int depth);
	gls::ITextureCubeArray* CreateTextureCubeArrayView(gls::ITextureCube* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);
	gls::ITextureCubeArray* CreateTextureCubeArrayView(gls::ITextureCubeArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);
	gls::ITextureCubeArray* CreateTextureCubeArrayView(gls::ITexture2DArray* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	gls::ITextureBuffer* CreateTextureBuffer();

	gls::ITextureRectangle* CreateTextureRectangle(size_t levels, gls::PixelFormat internal_format, int width, int height);
	gls::ITextureRectangle* CreateTextureRectangleView(gls::ITextureRectangle* orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);

	void DestroyTexture(gls::ITexture* texture);

	gls::IBuffer* CreateBuffer(gls::BufferType type, size_t size, const void* data, gls::BufferUsage usage);
	void DestroyBuffer(gls::IBuffer* buffer);

	gls::IFramebuffer* CreateFramebuffer();
	gls::IFramebuffer* CreateFramebufferWithoutAttachments(const gls::FramebufferParams& params);
	void DestroyFramebuffer(gls::IFramebuffer* framebuffer);
	gls::IRenderbuffer* CreateRenderbuffer();
	void DestroyRenderbuffer(gls::IRenderbuffer* renderbuffer);

	gls::IQuery* CreateQuery();
	void DestroyQuery(gls::IQuery* query);

	gls::IVertexShader* CreateVertexShader(size_t count, const char** source, bool& success);
	gls::IVertexShader* CreateVertexShader(size_t size, const void* binary, gls::uint format, bool& success);
	gls::IVertexShader* CreateVertexShaderWithTransformFeedback(size_t count, const char** source, size_t attrib_count, const char** attrib_names, bool& success);
	gls::IVertexShader* CreateVertexShaderWithTransformFeedback(size_t size, const void* binary, gls::uint format, size_t attrib_count, const char** attrib_names, bool& success);

	gls::ITessControlShader* CreateTessControlShader(size_t count, const char** source, bool& success);
	gls::ITessControlShader* CreateTessControlShader(size_t size, const void* binary, gls::uint format, bool& success);
	gls::ITessControlShader* CreateTessControlShaderWithTransformFeedback(size_t count, const char** source, size_t attrib_count, const char** attrib_names, bool& success);
	gls::ITessControlShader* CreateTessControlShaderWithTransformFeedback(size_t size, const void* binary, gls::uint format, size_t attrib_count, const char** attrib_names, bool& success);

	gls::ITessEvaluationShader* CreateTessEvaluationShader(size_t count, const char** source, bool& success);
	gls::ITessEvaluationShader* CreateTessEvaluationShader(size_t size, const void* binary, gls::uint format, bool& success);
	gls::ITessEvaluationShader* CreateTessEvaluationShaderWithTransformFeedback(size_t count, const char** source, size_t attrib_count, const char** attrib_names, bool& success);
	gls::ITessEvaluationShader* CreateTessEvaluationShaderWithTransformFeedback(size_t size, const void* binary, gls::uint format, size_t attrib_count, const char** attrib_names, bool& success);

	gls::IGeometryShader* CreateGeometryShader(size_t count, const char** source, bool& success);
	gls::IGeometryShader* CreateGeometryShader(size_t size, const void* binary, gls::uint format, bool& success);
	gls::IGeometryShader* CreateGeometryShaderWithTransformFeedback(size_t count, const char** source, size_t attrib_count, const char** attrib_names, bool& success);
	gls::IGeometryShader* CreateGeometryShaderWithTransformFeedback(size_t size, const void* binary, gls::uint format, size_t attrib_count, const char** attrib_names, bool& success);

	gls::IFragmentShader* CreateFragmentShader(size_t count, const char** source, bool& success);
	gls::IFragmentShader* CreateFragmentShader(size_t size, const void* binary, gls::uint format, bool& success);

	gls::IComputeShader* CreateComputeShader(size_t count, const char** source, bool& success);
	gls::IComputeShader* CreateComputeShader(size_t size, const void* binary, gls::uint format, bool& success);
	
	void DestroyShader(gls::IShader* shader);

	gls::ITransformFeedback* CreateTransformFeedback();
	void DestroyTransformFeedback(gls::ITransformFeedback* transform_feedback);

	// debugging
	void EnableDebugOutput(bool enable, bool synchronous);
	void EnableDebugMessages(gls::DebugMessageSource source, gls::DebugMessageType type, gls::DebugMessageSeverity severity, bool enable);
	void EnableDebugMessages(gls::DebugMessageSource source, gls::DebugMessageType type, gls::uint id_count, uint* ids, bool enable);
	void EnableDebugMessage(gls::DebugMessageSource source, gls::DebugMessageType type, gls::uint id, bool enable);
	void InsertDebugMessage(gls::DebugMessageSource source, gls::DebugMessageType type, gls::uint id, gls::DebugMessageSeverity severity, const char* message);
	void PushDebugGroup(gls::DebugMessageSource source, gls::uint id, const char* message);
	void PopDebugGroup();
	int GetDebugGroupStackDepth();
	void ResourceDebugLabel(gls::IResource* resource, const char* label);
	void SyncObjectDebugLabel(gls::SyncObject sync_object, const char* label);

private:
	GLRenderContext(const GLRenderContext&);

	bool InitCommon(gls::uint version);
	void DeinitCommon();
	bool CreateContext(gls::uint version, const gls::FramebufferFormat& format, bool debug_context);
	void GetContextInfo();
	bool LoadOpenGLExtensions(gls::uint version);
	bool LoadPlatformOpenGLExtensions();
	bool IsExtSupported(const char* extension);
	void Clear();
	void SetupDrawingState();
	bool GetInternalFormatInfo(GLenum type, GLenum internal_format, gls::InternalFormatInfo& info);
	void DebugMessage(gls::DebugMessageSource source, gls::DebugMessageType type, gls::DebugMessageSeverity severity, ErrorMessageId message_id, ...);

#if defined(_WIN32)

	HWND _hwnd;
	HGLRC _hglrc;
	HDC _hdc;
	HINSTANCE _instanceHandle;

#elif defined(__linux__)

	Display* _display;
	Window _window;
	GLXContext _context;

#endif

	GLContextInfo _info;
	bool _initialized;

	struct VertexStream
	{
		GLBuffer* buffer;
		size_t stride;
		size_t offset;
	};

	struct VertexAttrib
	{
		GLBuffer* buffer;
		size_t stride;
		size_t bufferBase;
		int numComponents;
		gls::DataType type;
		bool integer;
		bool normalized;
		size_t offset;
		gls::uint divisor;
		bool enabled;
	};

	struct ImageUnit
	{
		GLSamplerState* sampler;
		GLTexture* texture;
		bool texRemoved;
		GLenum removedTexTarget;
	};

	class NullLogger : public gls::IDebugLogger
	{
	public:
		void DebugMessage(gls::DebugMessageSource source, gls::DebugMessageType type, gls::uint id, gls::DebugMessageSeverity severity, const char* message) { }
	};

	// current state
	GLState _glState;
	VertexStream* _vertexStreams;
	GLVertexFormat* _vertexFormat;
	VertexAttrib* _vertexAttribs;
	int* _enabledVertexAttribs;
	GLBuffer* _indexBuffer;
	gls::DataType _indexType;
	GLFramebuffer* _framebuffer;
	ImageUnit* _imageUnits;
	int _highImageUnit;
	GLuint _pipeline;
	gls::IDebugLogger* _logger;
	NullLogger _nullLogger;
};


#endif // _GL_RENDER_CONTEXT_H_
