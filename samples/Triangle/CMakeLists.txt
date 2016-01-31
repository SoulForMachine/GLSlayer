
INCLUDE_DIRECTORIES(../../include/)
INCLUDE_DIRECTORIES(../../libs/include/)
INCLUDE_DIRECTORIES(../../samples/)

IF(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++0x -Wall -Wno-unused-parameter -Wno-missing-field-initializers -Wno-unused-result")
    FILE(COPY ./Shaders/ DESTINATION "${GLSlayer_BINARY_DIR}/bin/Shaders/Triangle")
ELSEIF(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    ADD_DEFINITIONS(-DUNICODE -D_UNICODE)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LIBPATH:${GLSlayer_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR}")
ENDIF()

SET(EXECUTABLE_OUTPUT_PATH "${GLSlayer_BINARY_DIR}/bin" CACHE INTERNAL "")

IF(UNIX)
    FILE(GLOB EXCLUDED_SOURCES ../Common/*windows* ../Common/*Windows*)
ELSEIF(WIN32)
    FILE(GLOB EXCLUDED_SOURCES ../Common/*linux* ../Common/*Linux*)
ENDIF()

FILE(GLOB Triangle_SOURCES *.cpp ../Common/*.cpp)
LIST(REMOVE_ITEM Triangle_SOURCES ${EXCLUDED_SOURCES})

ADD_EXECUTABLE(Triangle ${Triangle_SOURCES})

IF(UNIX)
    TARGET_LINK_LIBRARIES(Triangle GLSlayer X11 GL rt)
ELSEIF(WIN32)
    TARGET_LINK_LIBRARIES(Triangle GLSlayer)
ENDIF()

IF(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    ADD_CUSTOM_COMMAND(TARGET Triangle POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_directory
                       "${CMAKE_CURRENT_SOURCE_DIR}/Shaders"
                       "$(OutputPath)Shaders/$(ProjectName)")
    ADD_CUSTOM_COMMAND(TARGET Triangle POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${CMAKE_CURRENT_SOURCE_DIR}/../Common/Models"
                   "$(OutputPath)Models")
ENDIF()
