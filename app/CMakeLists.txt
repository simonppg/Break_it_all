cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src/main/cpp/glm)
set(GLM_ENABLE_EXPERIMENTAL)

add_library(common STATIC
        src/main/cpp/SandBox.cpp
        src/main/cpp/Test1.cpp
        src/main/cpp/Test2.cpp
        src/main/cpp/triangle.cpp
        src/main/cpp/utils.cpp
        src/main/cpp/square.cpp
        src/main/cpp/Cube.cpp
        src/main/cpp/Camera.cpp
        src/main/cpp/game.cpp)

target_link_libraries(common
        -lGLESv2
        glm)

if(ANDROID)

    add_library(gameLibJNIWrapper SHARED
            src/main/cpp/android/main.cpp
            src/main/cpp/android/filesManager.cpp)

    target_link_libraries(gameLibJNIWrapper
            common
            -landroid
            -llog
            -lGLESv3
            glm)

    # Examples
    #add_library(window SHARED
    #       src/main/cpp/examples/window/main.cpp)

    #target_link_libraries(window
    #        android
    #        GLESv2
    #        log)

    #add_library(triangle SHARED
    #        src/main/cpp/examples/triangle/triangle.cpp
    #        src/main/cpp/examples/triangle/jni.cpp
    #        src/main/cpp/utils.cpp
    #        src/main/cpp/android/filesManager.cpp)

    #target_link_libraries(triangle
    #        -landroid
    #        -llog
    #        -lGLESv3)

else(ANDROID)

    add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")
    set(CMAKE_BUILD_TYPE Debug)

    add_executable(linuxLauncher
            src/main/cpp/linux/main.cpp
            src/main/cpp/linux/filesManager.cpp)

    target_link_libraries(linuxLauncher
            common
            -lglfw)

    add_custom_target(run
            COMMAND linuxLauncher
            DEPENDS linuxLauncher
            WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

endif(ANDROID)
