cmake_minimum_required(VERSION 3.11)

# project name
project(asset_selector)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define macros to use in code depending on build type
IF (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DASSET_SELECTOR_DEBUG)
ENDIF (CMAKE_BUILD_TYPE STREQUAL Debug)

IF (CMAKE_BUILD_TYPE STREQUAL Release)
    add_definitions(-DASSET_SELECTOR_RELEASE)
ENDIF (CMAKE_BUILD_TYPE STREQUAL Release)

# define sources
set(SRCS
        AssetSelector.cpp
        AssetSelector.hpp)

# define the binary output
add_library(${PROJECT_NAME} ${SRCS})

# expose the headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# define the external libraries to use
target_link_libraries(${PROJECT_NAME} exception)

