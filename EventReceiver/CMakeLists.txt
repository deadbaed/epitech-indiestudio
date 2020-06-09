cmake_minimum_required(VERSION 3.11)

# project name
project(event_receiver)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define sources to use
set(SRCS MyEventReceiver.cpp MyEventReceiver.hpp)

# define the binary output
add_library(${PROJECT_NAME} ${SRCS})
