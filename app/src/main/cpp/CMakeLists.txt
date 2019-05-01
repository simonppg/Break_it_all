cmake_minimum_required(VERSION 3.10.2)

project(Break_it_all VERSION 0.0.1)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage -std=c++11 -Wall -Werror")
endif()
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

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
        GIT_TAG         v1.8.x
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")
endif()

add_subdirectory(hal)
add_subdirectory(common)

# Unit Tests
enable_testing()
add_executable(executeTests
        tests/sqrt_test.cpp
        common/src/common/math_utils.cpp
        common/src/common/Vector.cpp
        tests/game_test.cpp)

target_link_libraries(executeTests
        common
        gtest)

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
