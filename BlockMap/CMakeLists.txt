cmake_minimum_required(VERSION 3.11)

# project name
project(block_map)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define sources to use
set(SRCS blockMap.cpp blockMap.hpp)

# define the binary output
add_library(${PROJECT_NAME} ${SRCS})

# expose the headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# define the external libraries to use
target_link_libraries(${PROJECT_NAME} game_object)
target_link_libraries(${PROJECT_NAME} asset_selector)
