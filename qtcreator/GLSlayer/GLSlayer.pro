#-------------------------------------------------
#
# Project created by QtCreator 2012-04-22T20:05:42
#
#-------------------------------------------------

QT	-= core gui

TARGET = GLSlayer
TEMPLATE = lib

DEFINES += GLSLAYER_EXPORTS

QMAKE_CXXFLAGS += -std=c++0x -fvisibility=hidden -Wall -Wno-unused-parameter

INCLUDEPATH += \
	../../source/opengl/ \
	../../include/

SOURCES += \
	../../source/opengl/GLVertexFormat.cpp \
	../../source/opengl/GLTransformFeedback.cpp \
	../../source/opengl/GLTexture.cpp \
	../../source/opengl/GLShader.cpp \
	../../source/opengl/GLSamplerState.cpp \
	../../source/opengl/GLRenderContext.cpp \
	../../source/opengl/GLQuery.cpp \
	../../source/opengl/GLFramebuffer.cpp \
	../../source/opengl/GLCommon.cpp \
	../../source/opengl/GLBuffer.cpp \
	../../source/opengl/GLSlayerMessages.cpp \
	../../source/opengl/GLRenderContext_Linux.cpp \
	../../source/opengl/extensions/h_glext.cpp

HEADERS +=\
	../../include/GLSlayer/VertexFormat.h \
	../../include/GLSlayer/TransformFeedback.h \
	../../include/GLSlayer/Texture.h \
	../../include/GLSlayer/Shader.h \
	../../include/GLSlayer/SamplerState.h \
	../../include/GLSlayer/Resource.h \
	../../include/GLSlayer/RenderContext.h \
	../../include/GLSlayer/RenderContextInit.h \
	../../include/GLSlayer/Query.h \
	../../include/GLSlayer/Framebuffer.h \
	../../include/GLSlayer/Common.h \
	../../include/GLSlayer/Buffer.h \
	../../source/opengl/GLVertexFormat.h \
	../../source/opengl/GLTransformFeedback.h \
	../../source/opengl/GLTexture.h \
	../../source/opengl/GLShader.h \
	../../source/opengl/GLSamplerState.h \
	../../source/opengl/GLResource.h \
	../../source/opengl/GLRenderContext.h \
	../../source/opengl/GLQuery.h \
	../../source/opengl/GLFramebuffer.h \
	../../source/opengl/GLContextInfo.h \
	../../source/opengl/GLCommon.h \
	../../source/opengl/GLBuffer.h \
	../../source/opengl/GLSlayerMessages.h \
	../../source/opengl/extensions/wglext_ptrs.h \
	../../source/opengl/extensions/wglext.h \
	../../source/opengl/extensions/h_glext.h \
	../../source/opengl/extensions/glext_linux_ptrs.h \
	../../source/opengl/extensions/glext.h \
	../../source/opengl/extensions/glxext.h \
	../../source/opengl/extensions/glxext_ptrs.h

OTHER_FILES += \
	../../source/opengl/extensions/glext_linux_ptrs.h \
	../../source/opengl/extensions/glext_linux_load_decl.h \
	../../source/opengl/extensions/glext_linux_load_def.inc \
	../../source/opengl/extensions/glext_linux_funcs.h \
	../../source/opengl/extensions/glext_linux_flags.h \
	../../source/opengl/extensions/glelcg-xml.rb \
	../../source/opengl/extensions/make-exts.sh \
	../../source/opengl/extensions/glx_extensions.txt \
	../../source/opengl/extensions/glxext_ptrs.h \
	../../source/opengl/extensions/glxext_load_decl.h \
	../../source/opengl/extensions/glxext_load_def.inc \
	../../source/opengl/extensions/glxext_funcs.h \
	../../source/opengl/extensions/glxext_flags.h \
	../../source/opengl/extensions/extensions_linux.txt


unix {
	CONFIG(debug, debug|release) {
		OBJECTS_DIR = $$PWD/../$$TARGET-debug
		DESTDIR = $$PWD/../bin/debug/
	}
	CONFIG(release, debug|release) {
		OBJECTS_DIR = $$PWD/../$$TARGET-release
		DESTDIR = $$PWD/../bin/release/
	}

	LIBS += -lX11 -lGL
}
