CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(GLSlayer)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
SET(CMAKE_INSTALL_RPATH "$ORIGIN/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_SUBDIRECTORY(source)
ADD_SUBDIRECTORY(samples)

