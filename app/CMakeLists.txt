cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src/main/cpp/glm)
set(GLM_ENABLE_EXPERIMENTAL)

add_library(common STATIC
    src/main/cpp/triangle.cpp
    src/main/cpp/utils.cpp
    src/main/cpp/square.cpp
    src/main/cpp/game.cpp)

target_link_libraries(common
    -lGLESv2
    glm)

if(ANDROID)

    set(androidSrcDir "src/main/cpp/android")

    add_library(gameLibJNIWrapper SHARED
        ${androidSrcDir}/main.cpp
        ${androidSrcDir}/filesManager.cpp)

    target_link_libraries(gameLibJNIWrapper
        common
        -landroid
        -llog
        -lGLESv3
        glm)

    # Examples
    add_library(window SHARED
            src/main/cpp/examples/window/main.cpp)

    target_link_libraries(window
            android
            GLESv2
            log)

else(ANDROID)

    set(gameLauncher linuxLauncher)
    set(linuxSrcDir "src/main/cpp/linux")

    add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")
    set(CMAKE_BUILD_TYPE Debug)

    add_executable(${gameLauncher}
        ${linuxSrcDir}/main.cpp
        ${linuxSrcDir}/filesManager.cpp)

    target_link_libraries(${gameLauncher}
        common
        -lglfw)

    add_custom_target(run
        COMMAND ${gameLauncher}
        DEPENDS ${gameLauncher}
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

endif(ANDROID)