cmake_minimum_required(VERSION 3.11)

# project name
project(storage)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define macros to use in code depending on build type
IF (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DSTORAGE_DEBUG)
ENDIF (CMAKE_BUILD_TYPE STREQUAL Debug)

IF (CMAKE_BUILD_TYPE STREQUAL Release)
    add_definitions(-DSTORAGE_RELEASE)
ENDIF (CMAKE_BUILD_TYPE STREQUAL Release)

# define sources to use
set(SRCS
        Storage.cpp Storage.hpp
        BasePath.cpp
        LoadFile.cpp
        FileName.cpp)

# define the binary output
add_library(${PROJECT_NAME} ${SRCS})

# expose the headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

