cmake_minimum_required(VERSION 3.11)

# project name
project(game_scene)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define sources to use
set(SRCS IGameScene.hpp
        GameScene.cpp GameScene.hpp
        GameSceneManager.cpp GameSceneManager.hpp
        TestGameScene.cpp TestGameScene.hpp
        TestGameSceneTest.cpp TestGameSceneTest.hpp)

# define the binary output
add_library(${PROJECT_NAME} ${SRCS})

include_directories(${game_object_SOURCE_DIR})
include_directories(${controller_SOURCE_DIR})
include_directories(${event_receiver_SOURCE_DIR})
include_directories(${player_SOURCE_DIR})

# define the external libraries to use
target_link_libraries(${PROJECT_NAME} game_object)
target_link_libraries(${PROJECT_NAME} controller)
target_link_libraries(${PROJECT_NAME} player)
