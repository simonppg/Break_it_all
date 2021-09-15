# Dependencies
include(glm.cmake)
include(googletest.cmake)

# Local dependencies
add_subdirectory(hal)
add_subdirectory(math)
add_subdirectory(common)
add_subdirectory(tests)
add_subdirectory(BreakItAll)

# Target
add_subdirectory(androidNativeLibrary)
