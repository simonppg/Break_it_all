cmake_minimum_required(VERSION 3.10.2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage -std=c++11 -Wall -Werror")
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)

# Get glm
download_project(PROJ   glm
        GIT_REPOSITORY  https://github.com/g-truc/glm.git
        GIT_TAG         master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${glm_SOURCE_DIR}/include")
endif()

# Get googletest
download_project(PROJ   googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")
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
        src/main/cpp/math_utils.cpp
        src/main/cpp/game.cpp
        src/main/cpp/Mesh.cpp)

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
            -llog)

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
    enable_testing()
    add_executable(executeTests
            src/main/cpp/tests/sqrt_test.cpp
            src/main/cpp/math_utils.cpp
            src/main/cpp/tests/game_test.cpp)

    target_link_libraries(executeTests
            gtest
            pthread)

    add_test(NAME executeTests
            COMMAND executeTests)

    add_custom_target(check
            COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} -VV
            DEPENDS executeTests)

    add_custom_target(coverage
            COMMAND lcov -c -d CMakeFiles -o cov.info
            COMMAND genhtml cov.info -o out
            COMMAND google-chrome out/index.html
            DEPENDS check
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

endif(ANDROID)
