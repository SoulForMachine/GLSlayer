
ADD_DEFINITIONS(-DGLSLAYER_EXPORTS=1)

INCLUDE_DIRECTORIES(../../include/)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++0x -fvisibility=hidden -Wall -Wno-unused-parameter")
SET(LIBRARY_OUTPUT_PATH "${GLSlayer_BINARY_DIR}/bin" CACHE INTERNAL "")

FILE(GLOB WIN_SOURCES *windows* *Windows* ./extensions/*windows* ./extensions/*Windows*)
FILE(GLOB GLSlayer_SOURCES *.cpp ./extensions/*.cpp)
LIST(REMOVE_ITEM GLSlayer_SOURCES ${WIN_SOURCES})

ADD_LIBRARY(GLSlayer SHARED ${GLSlayer_SOURCES})
TARGET_LINK_LIBRARIES(GLSlayer X11 GL)
