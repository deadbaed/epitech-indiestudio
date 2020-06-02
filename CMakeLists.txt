cmake_minimum_required(VERSION 3.11)

# Name of the projet
project(bomberman)

# c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define path to external libraries (cmake modules)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/lib")
set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/Irrlicht")

# use the cmake modules
find_package(Irrlicht REQUIRED)

# define the include path
include_directories(${Irrlicht_INCLUDE_DIRS})

# define sources to use
set(SRCS
        src/main.cpp
        src/menu/Window.cpp)

# define the binary output
add_executable(bomberman ${SRCS})

# define the external libraries to use
target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
