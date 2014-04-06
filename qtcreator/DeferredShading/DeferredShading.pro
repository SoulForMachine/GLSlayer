
TEMPLATE = app
CONFIG += console
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x -Wall -Wno-unused-parameter -Wno-missing-field-initializers -Wno-unused-result
QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../GLSlayer/

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

INCLUDEPATH += $$PWD/../GLSlayer
DEPENDPATH += $$PWD/../GLSlayer
LIBS += -L$$OUT_PWD/../GLSlayer/ -lGLSlayer

unix {
	LIBS += -lX11 -lrt

	copyfiles.commands = mkdir -p $$OUT_PWD/Shaders/DeferredShading/ && \
						 rsync -aC --recursive $$PWD/../../samples/DeferredShading/Shaders/ $$OUT_PWD/Shaders/DeferredShading/ && \
						 rsync -aC --include=*.obj $$PWD/../../samples/Common/Models/skull.obj $$OUT_PWD/Models/
}
win32 {
	CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GLSlayer/release/ -lGLSlayer
	else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GLSlayer/debug/ -lGLSlayer
}


QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles
