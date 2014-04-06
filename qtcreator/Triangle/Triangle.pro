
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

INCLUDEPATH += $$PWD/../GLSlayer
DEPENDPATH += $$PWD/../GLSlayer
LIBS += -L$$OUT_PWD/../GLSlayer/ -lGLSlayer

unix {
	LIBS += -lX11 -lrt

	copyfiles.commands = mkdir -p $$OUT_PWD/Shaders/Triangle/ && \
						 rsync -aC --recursive $$PWD/../../samples/Triangle/Shaders/ $$OUT_PWD/Shaders/Triangle/
}
win32 {
	CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GLSlayer/release/ -lGLSlayer
	else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GLSlayer/debug/ -lGLSlayer
}

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles
