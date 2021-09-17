include(cmake/DownloadProject.cmake)

# Dependencies
include(cmake/glm.cmake)
include(cmake/googletest.cmake)
include(cmake/glfw.cmake)

# Local dependencies
add_subdirectory(hal)
add_subdirectory(math)
add_subdirectory(common)
# add_subdirectory(tests)

# Wrapper library for glfw
add_library(WindowManager STATIC
            platform/linux/WindowManager.cpp)

# Link glfw library to WindowManager
target_link_libraries(WindowManager
                      glfw)

# Make library public available
target_include_directories(WindowManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/platform/linux)


# Platform specific code
add_library(Platform STATIC
    platform/linux/LinuxLogger.cpp)

target_link_libraries(Platform
    WindowManager)


# Executable code and src files
add_executable(linuxVersion
                linuxBin.cpp)

# Link library BreakItAll and WindowManager to linuxVersion executable
target_link_libraries(linuxVersion
    common
    Platform)

# Custom command to run in the linuxVersion in the terminal, e.g. $ make runNew
add_custom_target(runNew
                COMMAND linuxVersion
                DEPENDS linuxVersion
                WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
