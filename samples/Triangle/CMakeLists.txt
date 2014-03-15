
INCLUDE_DIRECTORIES(../../include/)
INCLUDE_DIRECTORIES(../../libs/include/)
INCLUDE_DIRECTORIES(../../samples/)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++0x -Wall -Wno-unused-parameter -Wno-missing-field-initializers -Wno-unused-result")
SET(EXECUTABLE_OUTPUT_PATH "${GLSlayer_BINARY_DIR}/bin" CACHE INTERNAL "")

FILE(GLOB WIN_SOURCES ../Common/*windows* ../Common/*Windows*)
FILE(GLOB Triangle_SOURCES *.cpp ../Common/*.cpp)
LIST(REMOVE_ITEM Triangle_SOURCES ${WIN_SOURCES})

ADD_EXECUTABLE(Triangle ${Triangle_SOURCES})
TARGET_LINK_LIBRARIES(Triangle GLSlayer X11 GL rt)
FILE(COPY ./Shaders/ DESTINATION "${GLSlayer_BINARY_DIR}/bin/Shaders/Triangle")

