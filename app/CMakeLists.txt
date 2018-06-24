cmake_minimum_required(VERSION 3.4.1)

add_library(game SHARED
    src/main/cpp/game.c
    src/main/cpp/utils.c
    src/main/cpp/triangle.c
    src/main/cpp/square.c)

add_library(gameLibJNIWrapper SHARED
    src/main/cpp/jni.c)

target_link_libraries(gameLibJNIWrapper
    game)

target_link_libraries(gameLibJNIWrapper
    -landroid
    -llog
    -lGLESv3)

target_link_libraries(game
    -landroid
    -llog
    -lGLESv3)

if (UNIX)
    set(gameLauncher linuxLauncher)

    add_library(triangle2 SHARED
        src/main/cpp/triangle2.c
        src/main/cpp/triangle.c
        src/main/cpp/utils.c)

    add_executable(${gameLauncher}
        src/main/cpp/linux/main.c)

    target_link_libraries(triangle2
        -lGLESv2)

    target_link_libraries(${gameLauncher}
        triangle2
        -lglfw)

    add_custom_target(run
        COMMAND ${gameLauncher}
        DEPENDS ${gameLauncher}
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
endif (UNIX)
