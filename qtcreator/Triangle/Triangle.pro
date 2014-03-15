
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
	../../samples/Triangle/TriangleSample.cpp \
	../../samples/Triangle/Main.cpp

HEADERS += \
	../../samples/Common/ObjLoader.h \
	../../samples/Common/Utils.h \
	../../samples/Common/Console.h \
	../../samples/Common/SampleFramework_Linux.h \
	../../samples/Common/SampleFramework.h \
	../../samples/Common/ISample.h \
	../../samples/Triangle/TriangleSample.h

OTHER_FILES += \
    ../../samples/Triangle/Shaders/Simple.frag \
    ../../samples/Triangle/Shaders/Simple.vert

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

		COPY_SHADERS = mkdir -p $$DESTDIR/Shaders/Triangle/ && rsync -aC --recursive $$PWD/../../samples/Triangle/Shaders/ $$DESTDIR/Shaders/Triangle/

	QMAKE_POST_LINK += $$COPY_SHADERS
}
