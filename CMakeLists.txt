cmake_minimum_required(VERSION 3.11)

# Name of the projet
project(bomberman)

# c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define path to external libraries (cmake modules)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
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

# windows only: copy the irrlicht dll inside current directory
IF (WIN32)
    add_custom_command(TARGET bomberman POST_BUILD                 # post-build event for target
            COMMAND ${CMAKE_COMMAND} -E copy_if_different          # which executes "cmake - E copy_if_different..."
            "${Irrlicht_DIR}/Irrlicht.dll"                         # input file
            $<TARGET_FILE_DIR:bomberman>)                          # output is the same output as target
ENDIF()
