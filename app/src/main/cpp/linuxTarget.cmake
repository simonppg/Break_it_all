# Dependencies
include(glm.cmake)
include(googletest.cmake)
include(glfw.cmake)

# Local dependencies
add_subdirectory(hal)
add_subdirectory(math)
add_subdirectory(common)
add_subdirectory(tests)

# Target
add_subdirectory(linuxExecutable)
