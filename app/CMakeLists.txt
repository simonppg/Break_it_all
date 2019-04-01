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
    # Download and unpack googletest at configure time
    configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
    execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
    execute_process(COMMAND "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Add googletest directly to our build. This adds
    # the following targets: gtest, gtest_main, gmock
    # and gmock_main
    add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
            "${CMAKE_BINARY_DIR}/googletest-build")

    # The gtest/gmock targets carry header search path
    # dependencies automatically when using CMake 2.8.11 or
    # later. Otherwise we have to add them here ourselves.
    if(CMAKE_VERSION VERSION_LESS 2.8.11)
        include_directories("${gtest_SOURCE_DIR}/include"
                "${gmock_SOURCE_DIR}/include")
    endif()

    # Now simply link your own targets against gtest, gmock,
    # etc. as appropriate
    enable_testing()
    add_executable(executeTests
            src/main/cpp/tests/sqrt_test.cpp)

    target_link_libraries(executeTests
            gtest
            pthread)

    add_test(NAME executeTests
            COMMAND executeTests)

endif(ANDROID)
