cmake_minimum_required(VERSION 3.10.2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ   googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})

download_project(PROJ   glm
        GIT_REPOSITORY  https://github.com/g-truc/glm.git
        GIT_TAG         master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})

add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${glm_SOURCE_DIR}/include")
endif()

add_library(common STATIC
        src/main/cpp/SandBox.cpp
        src/main/cpp/Test1.cpp
        src/main/cpp/Test2.cpp
        src/main/cpp/Test3.cpp
        src/main/cpp/Test4.cpp
        src/main/cpp/Triangle.cpp
        src/main/cpp/Square.cpp
        src/main/cpp/utils.cpp
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

else(ANDROID)

    add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")

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

    # Unit Tests
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    if (CMAKE_VERSION VERSION_LESS 2.8.11)
        include_directories("${gtest_SOURCE_DIR}/include"
                "${gmock_SOURCE_DIR}/include")
    endif()
    enable_testing()
    add_executable(executeTests
            src/main/cpp/tests/sqrt_test.cpp)

    target_link_libraries(executeTests
            gtest
            pthread)

    add_test(NAME executeTests
            COMMAND executeTests)
    
endif(ANDROID)
