cmake_minimum_required(VERSION 3.4.1)

add_library(common STATIC
    src/main/cpp/triangle.c
    src/main/cpp/utils.c
    src/main/cpp/square.c)

target_link_libraries(common
    -lGLESv2)

if(ANDROID)

    set(androidSrcDir "src/main/cpp/android")

    add_library(gameLibJNIWrapper SHARED
        ${androidSrcDir}/jni.c
        ${androidSrcDir}/game.c
        ${androidSrcDir}/logger.c
        ${androidSrcDir}/filesManager.c)

    target_link_libraries(gameLibJNIWrapper
        common
        -landroid
        -llog
        -lGLESv3)

else(ANDROID)

    set(gameLauncher linuxLauncher)
    set(linuxSrcDir "src/main/cpp/linux")

    add_executable(${gameLauncher}
        ${linuxSrcDir}/main.c
        ${linuxSrcDir}/logger.c)


    target_link_libraries(${gameLauncher}
        common
        -lglfw)

    add_custom_target(run
        COMMAND ${gameLauncher}
        DEPENDS ${gameLauncher}
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

endif(ANDROID)
