
TEMPLATE = app
CONFIG += console
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wno-unused-parameter -Wno-missing-field-initializers -Wno-unused-result

INCLUDEPATH += \
	../../include/ \
	../../libs/include/ \
	../../samples/


SOURCES += \
	../../samples/Common/ObjLoader.cpp \
	../../samples/Common/Utils.cpp \
	../../samples/Common/SampleFramework_Linux.cpp \
	../../samples/DeferredShading/DeferredSample.cpp \
	../../samples/DeferredShading/Main.cpp

HEADERS += \
	../../samples/Common/ObjLoader.h \
	../../samples/Common/Utils.h \
	../../samples/Common/Console.h \
	../../samples/Common/SampleFramework_Linux.h \
	../../samples/Common/SampleFramework.h \
	../../samples/Common/ISample.h \
	../../samples/DeferredShading/DeferredSample.h \
	../../samples/DeferredShading/Light.h

OTHER_FILES += \
    ../../samples/DeferredShading/Shaders/SimpleTexture.frag \
    ../../samples/DeferredShading/Shaders/ScreenSpace.vert \
    ../../samples/DeferredShading/Shaders/Lighting.vert \
    ../../samples/DeferredShading/Shaders/Lighting.frag \
    ../../samples/DeferredShading/Shaders/GBuffer.vert \
    ../../samples/DeferredShading/Shaders/GBuffer.frag

unix {
	CONFIG(debug, debug|release) {
		OBJECTS_DIR = $$PWD/../$$TARGET-debug
		DESTDIR = $$PWD/../bin/debug/
	}
	CONFIG(release, debug|release) {
		OBJECTS_DIR = $$PWD/../$$TARGET-release
		DESTDIR = $$PWD/../bin/release/
	}

	LIBS += -lX11 -lrt -L$$DESTDIR/ -lGLSlayer

		COPY_SHADERS = mkdir -p $$DESTDIR/Shaders/DeferredShading/ && rsync -aC --recursive $$PWD/../../samples/DeferredShading/Shaders/ $$DESTDIR/Shaders/DeferredShading/
		COPY_MODELS = rsync -aC --include=*.obj $$PWD/../../samples/Common/Models/skull.obj $$DESTDIR/Models/

	QMAKE_POST_LINK += $$COPY_SHADERS & $$COPY_MODELS
}
