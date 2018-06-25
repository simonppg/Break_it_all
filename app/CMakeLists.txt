cmake_minimum_required(VERSION 3.4.1)

add_library(androidLogger SHARED
    src/main/cpp/android/logger.c)

add_library(logger SHARED
    src/main/cpp/linux/logger.c)

add_library(common SHARED
    src/main/cpp/triangle.c
    src/main/cpp/utils.c)

add_library(game SHARED
    src/main/cpp/game.c
    src/main/cpp/android/logger.c
    src/main/cpp/square.c)

add_library(gameLibJNIWrapper SHARED
    src/main/cpp/jni.c)

target_link_libraries(gameLibJNIWrapper
    game)

if(ANDROID)
target_link_libraries(androidLogger
    -llog
    -landroid)
target_link_libraries(common
    androidLogger)
endif(ANDROID)

if(NOT ANDROID)
target_link_libraries(common
    logger)
endif(UNIX)

target_link_libraries(game
    common
    -landroid
    -llog
    -lGLESv3)

set(gameLauncher linuxLauncher)

add_executable(${gameLauncher}
    src/main/cpp/linux/main.c
    src/main/cpp/linux/logger.c)

target_link_libraries(common
    -lGLESv2)

target_link_libraries(${gameLauncher}
    common
    -lglfw)

add_custom_target(run
    COMMAND ${gameLauncher}
    DEPENDS ${gameLauncher}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
