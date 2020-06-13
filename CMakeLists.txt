cmake_minimum_required(VERSION 3.11)

# project name
project(bomberman)

# define assets path
set(ASSETS_PATH ${CMAKE_CURRENT_LIST_DIR}/assets)

# c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# define path to external libraries (cmake modules)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/Irrlicht")

# Windows: give path to the local SFML
IF (WIN32)
    set(SFML_DIR "${CMAKE_MODULE_PATH}/SFML-2.5.0/lib/cmake/SFML")
ENDIF (WIN32)

# use the cmake modules
find_package(Irrlicht REQUIRED)
find_package(SFML 2.5 COMPONENTS system audio REQUIRED)

# define the include path
include_directories(${Irrlicht_INCLUDE_DIRS})

# define the internal libraries to use
add_subdirectory(Music)
add_subdirectory(EventReceiver)
add_subdirectory(Button)
add_subdirectory(Controller)
add_subdirectory(GameObject)
add_subdirectory(MapGenerator)
add_subdirectory(BlockMap)
add_subdirectory(Player)
add_subdirectory(GameScene)
add_subdirectory(Menu)
add_subdirectory(Settings)
add_subdirectory(Storage)

# define sources to use
set(SRCS Application/main.cpp CPack/win32.rc)

# define the binary output
add_executable(${PROJECT_NAME} ${SRCS})

# define the internal libraries to use
target_link_libraries(${PROJECT_NAME} music)
target_link_libraries(${PROJECT_NAME} event_receiver)
target_link_libraries(${PROJECT_NAME} map_generator)
target_link_libraries(${PROJECT_NAME} block_map)
target_link_libraries(${PROJECT_NAME} button)
target_link_libraries(${PROJECT_NAME} controller)
target_link_libraries(${PROJECT_NAME} game_object)
target_link_libraries(${PROJECT_NAME} game_scene)
target_link_libraries(${PROJECT_NAME} menu)
target_link_libraries(${PROJECT_NAME} settings)
target_link_libraries(${PROJECT_NAME} player)
target_link_libraries(${PROJECT_NAME} storage)

# define the external libraries to use
target_link_libraries(${PROJECT_NAME} ${Irrlicht_LIBRARIES})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-audio)

# windows: define external libs dll location
IF (WIN32)
    set(DLL_IRRLICHT ${Irrlicht_DIR}/lib/Irrlicht.dll)
    set(DLL_OPENAL32 ${SFML_DIR}/../../../bin/openal32.dll)
    set(DLL_SFML_AUDIO_D ${SFML_DIR}/../../../bin/sfml-audio-d-2.dll)
    set(DLL_SFML_SYSTEM_D ${SFML_DIR}/../../../bin/sfml-system-d-2.dll)
    set(DLL_SFML_AUDIO ${SFML_DIR}/../../../bin/sfml-audio-2.dll)
    set(DLL_SFML_SYSTEM ${SFML_DIR}/../../../bin/sfml-system-2.dll)

    file(GLOB DLL_FILES_D ${DLL_IRRLICHT} ${DLL_OPENAL32} ${DLL_SFML_AUDIO_D} ${DLL_SFML_SYSTEM_D})
    file(GLOB DLL_FILES ${DLL_IRRLICHT} ${DLL_OPENAL32} ${DLL_SFML_AUDIO} ${DLL_SFML_SYSTEM})

    # copy dlls

    # irrlicht and openal (they dont change on debug or release)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${DLL_IRRLICHT} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${DLL_OPENAL32} $<TARGET_FILE_DIR:${PROJECT_NAME}>)

    # SFML Debug
    IF (CMAKE_BUILD_TYPE STREQUAL Debug)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${DLL_SFML_AUDIO_D} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${DLL_SFML_SYSTEM_D} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    ENDIF (CMAKE_BUILD_TYPE STREQUAL Debug)

    # SFML Release
    IF (CMAKE_BUILD_TYPE STREQUAL Release)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${DLL_SFML_AUDIO} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${DLL_SFML_SYSTEM} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    ENDIF (CMAKE_BUILD_TYPE STREQUAL Release)

    # CPack: windows: put the dlls with the binary
    install(FILES ${DLL_FILES} DESTINATION bin)

    # Windows Start Menu shortcut to launch the game
    set(CPACK_NSIS_CREATE_ICONS_EXTRA
            "CreateShortCut '$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\IndieStudio.lnk' '$INSTDIR\\\\bin\\\\bomberman.exe'"
            )

    # Delete the shortcut when using the uninstaller
    set(CPACK_NSIS_DELETE_ICONS_EXTRA
            "Delete '$SMPROGRAMS\\\\$START_MENU\\\\IndieStudio.lnk'"
            )

ENDIF (WIN32)

# CPack

set(PROJECT_PRETTY_NAME "IndieStudio")

# Location of files
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

IF (WIN32)
    install(DIRECTORY ${ASSETS_PATH}/ DESTINATION assets)
ENDIF (WIN32)

IF (UNIX)
    # put assets in UNIX style folder
    install(DIRECTORY ${ASSETS_PATH}/ DESTINATION share/${PROJECT_PRETTY_NAME}/assets)

    # linux icons
    file(GLOB LINUX_ICONS
            CPack/bomberman.png
            CPack/bomberman-128.png
            CPack/bomberman-96.png
            CPack/bomberman-72.png
            CPack/bomberman-64.png
            CPack/bomberman-48.png)
    install(FILES ${LINUX_ICONS} DESTINATION share/${PROJECT_PRETTY_NAME}/icons)

    # desktop launcher
    install(FILES CPack/indiestudio.desktop DESTINATION share/applications)
ENDIF (UNIX)

# Configuration
set(CPACK_PACKAGE_NAME ${PROJECT_PRETTY_NAME})
set(CPACK_PACKAGE_VENDOR "Club Baby Pro")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_LIST_DIR}/CPack/license.txt)
set(CPACK_NSIS_DISPLAY_NAME ${PROJECT_PRETTY_NAME})

include(CPack)
