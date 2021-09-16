# Dependencies
include(glm.cmake)
include(googletest.cmake)

# Local dependencies
add_subdirectory(hal)
add_subdirectory(math)
add_subdirectory(common)
add_subdirectory(tests)
add_subdirectory(BreakItAll)

add_library(BreakItAllLibJNIWrapper
            SHARED
            androidLib.cpp)

target_link_libraries(BreakItAllLibJNIWrapper
                      BreakItAll
                      -landroid)
