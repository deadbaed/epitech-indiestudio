cmake_minimum_required(VERSION 3.11)

# Name of the projet
project(bomberman)

# c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define path to external libraries (cmake modules)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/Irrlicht")

# Windows: give path to the local SFML
IF(WIN32)
    set(SFML_DIR "${CMAKE_MODULE_PATH}/SFML-2.5.0/lib/cmake/SFML")
ENDIF()

# use the cmake modules
find_package(Irrlicht REQUIRED)
find_package(SFML 2.5 COMPONENTS system audio REQUIRED)

# define the include path
include_directories(${Irrlicht_INCLUDE_DIRS})

# define sources to use
set(SRCS
    src/main.cpp src/GameObject.cpp src/Player.cpp src/GameScene.cpp src/IrrlichtController.cpp src/GameSceneManager.cpp src/TestGameScene.cpp src/Menu.cpp src/Button.cpp src/MyEventReceiver.cpp src/Settings.cpp src/TestGameSceneTest.cpp src/Music.cpp include/Music.hpp)
include_directories(./include)


# define the binary output
add_executable(bomberman ${SRCS})

# define the external libraries to use
target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
target_link_libraries(bomberman sfml-system sfml-audio)

# windows only: copy the dlls
IF(WIN32)
    # Irrlicht
    add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${Irrlicht_DIR}/lib/Irrlicht.dll" $<TARGET_FILE_DIR:bomberman>)

    # SFML Debug
    IF(CMAKE_BUILD_TYPE STREQUAL Debug)
        add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${SFML_DIR}/../../../bin/sfml-audio-d-2.dll" $<TARGET_FILE_DIR:bomberman>)
        add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${SFML_DIR}/../../../bin/sfml-system-d-2.dll" $<TARGET_FILE_DIR:bomberman>)
        add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${SFML_DIR}/../../../bin/openal32.dll" $<TARGET_FILE_DIR:bomberman>)
    ENDIF(CMAKE_BUILD_TYPE STREQUAL Debug)

    # SFML Release
    IF(CMAKE_BUILD_TYPE STREQUAL Release)
        add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${SFML_DIR}/../../../bin/sfml-audio-2.dll" $<TARGET_FILE_DIR:bomberman>)
        add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${SFML_DIR}/../../../bin/sfml-system-2.dll" $<TARGET_FILE_DIR:bomberman>)
        add_custom_command(TARGET bomberman POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${SFML_DIR}/../../../bin/openal32.dll" $<TARGET_FILE_DIR:bomberman>)
    ENDIF(CMAKE_BUILD_TYPE STREQUAL Release)

ENDIF(WIN32)
