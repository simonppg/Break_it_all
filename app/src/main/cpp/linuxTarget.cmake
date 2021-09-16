include(cmake/DownloadProject.cmake)

# Dependencies
include(cmake/glm.cmake)
include(cmake/googletest.cmake)
include(cmake/glfw.cmake)

# Local dependencies
add_subdirectory(hal)
add_subdirectory(math)
add_subdirectory(common)
add_subdirectory(tests)
add_subdirectory(BreakItAll)
add_subdirectory(platform)

# Executable code and src files
add_executable(linuxVersion
                linuxBin.cpp)

# Link library BreakItAll and WindowManager to linuxVersion executable
target_link_libraries(linuxVersion
                      BreakItAll
                      LinuxPlatform)

# Custom command to run in the linuxVersion in the terminal, e.g. $ make runNew
add_custom_target(runNew
                COMMAND linuxVersion
                DEPENDS linuxVersion
                WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
