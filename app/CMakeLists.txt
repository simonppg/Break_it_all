cmake_minimum_required(VERSION 3.4.1)

add_library(common STATIC
    src/main/cpp/triangle.c
    src/main/cpp/utils.c)

target_link_libraries(common
    -lGLESv2)

if(ANDROID)

    add_library(gameLibJNIWrapper SHARED
        src/main/cpp/jni.c
        src/main/cpp/game.c
        src/main/cpp/android/logger.c
        src/main/cpp/square.c)

    target_link_libraries(gameLibJNIWrapper
        common
        -landroid
        -llog
        -lGLESv3)

else(ANDROID)

    set(gameLauncher linuxLauncher)

    add_executable(${gameLauncher}
        src/main/cpp/linux/main.c
        src/main/cpp/linux/logger.c)


    target_link_libraries(${gameLauncher}
        common
        -lglfw)

    add_custom_target(run
        COMMAND ${gameLauncher}
        DEPENDS ${gameLauncher}
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

endif(ANDROID)
