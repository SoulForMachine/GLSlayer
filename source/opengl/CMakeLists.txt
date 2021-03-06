
ADD_DEFINITIONS(-DGLSLAYER_EXPORTS=1)

INCLUDE_DIRECTORIES(../../include/)

IF(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++0x -fvisibility=hidden -Wall -Wno-unused-parameter")
ELSEIF(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    ADD_DEFINITIONS(-DUNICODE -D_UNICODE)
ENDIF()

SET(LIBRARY_OUTPUT_PATH "${GLSlayer_BINARY_DIR}/bin" CACHE INTERNAL "")

IF(UNIX)
    FILE(GLOB EXCLUDED_SOURCES *windows* *Windows* ./extensions/*windows* ./extensions/*Windows*)
ELSEIF(WIN32)
    FILE(GLOB EXCLUDED_SOURCES *linux* *Linux* ./extensions/*linux* ./extensions/*Linux*)
ENDIF()

FILE(GLOB GLSlayer_SOURCES *.cpp ./extensions/*.cpp)
LIST(REMOVE_ITEM GLSlayer_SOURCES ${EXCLUDED_SOURCES})

ADD_LIBRARY(GLSlayer SHARED ${GLSlayer_SOURCES})

IF(UNIX)
    TARGET_LINK_LIBRARIES(GLSlayer X11 GL)
ENDIF()

