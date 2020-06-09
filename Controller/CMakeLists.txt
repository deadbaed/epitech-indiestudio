cmake_minimum_required(VERSION 3.11)

# project name
project(controller)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define sources to use
set(SRCS IrrlichtController.cpp IrrlichtController.hpp)

# define the binary output
add_library(${PROJECT_NAME} ${SRCS})

# define the external libraries to use
target_link_libraries(${PROJECT_NAME} event_receiver)
