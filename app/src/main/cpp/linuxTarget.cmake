# Dependencies
include(glm.cmake)
include(googletest.cmake)
include(glfw.cmake)

# Local dependencies
add_subdirectory(hal)
add_subdirectory(math)
add_subdirectory(common)
add_subdirectory(tests)
add_subdirectory(BreakItAll)
add_subdirectory(platform)

# Executable code and src files
add_executable(linuxVersion
                linuxExecutable/main.cpp)

# Link library BreakItAll and WindowManager to linuxVersion executable
target_link_libraries(linuxVersion
                      BreakItAll
                      WindowManager)

# Custom command to run in the linuxVersion in the terminal, e.g. $ make runNew
add_custom_target(runNew
                COMMAND linuxVersion
                DEPENDS linuxVersion
                WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
