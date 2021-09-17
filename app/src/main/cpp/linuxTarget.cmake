add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")

include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)
include(cmake/glfw.cmake)

add_subdirectory(common)

add_library(WindowManager
    STATIC
    linux/WindowManager.cpp)

target_link_libraries(WindowManager
    glfw)

target_include_directories(WindowManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/platform/linux)

add_library(Platform
    STATIC
    linux/logger.hpp
    linux/filesManager.cpp
    linux/LinuxLogger.cpp)

target_link_libraries(Platform
    glfw
    WindowManager)

add_executable(linuxVersion
    linux/linuxBin.cpp)

target_link_libraries(linuxVersion
    common
    Platform)

add_custom_target(runNew
    COMMAND linuxVersion
    DEPENDS linuxVersion
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_executable(linuxLauncher
    linux/main.cpp)

target_link_libraries(linuxLauncher
    common
    glfw)

add_custom_target(run
    COMMAND linuxLauncher
    DEPENDS linuxLauncher
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
