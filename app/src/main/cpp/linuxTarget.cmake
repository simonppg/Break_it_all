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

# Target
add_subdirectory(linuxExecutable)
