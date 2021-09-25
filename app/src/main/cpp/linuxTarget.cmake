add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")

include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)
include(cmake/glfw.cmake)

add_subdirectory(shared/strings)
add_subdirectory(common)

add_library(WindowManager
    STATIC
    linux/WindowManager.cpp)

target_link_libraries(WindowManager
    glfw)

add_library(Platform
    STATIC
    linux/logger.hpp
    linux/filesManager.cpp
    linux/LinuxLogger.cpp)

target_link_libraries(Platform
    StringFormatter
    WindowManager)

add_executable(linuxVersion
    linux/linuxBin.cpp)

add_executable(linuxLauncher
    linux/main.cpp)

target_link_libraries(linuxVersion
    common)

target_link_libraries(linuxLauncher
    common)

add_custom_target(runNew
    COMMAND linuxVersion
    DEPENDS linuxVersion
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_custom_target(run
    COMMAND linuxLauncher
    DEPENDS linuxLauncher
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

