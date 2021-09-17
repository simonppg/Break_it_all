include(cmake/DownloadProject.cmake)

# Dependencies
include(cmake/glm.cmake)
include(cmake/googletest.cmake)

# Local dependencies
add_subdirectory(hal)
add_subdirectory(math)
add_subdirectory(common)
# add_subdirectory(tests)

add_library(Platform STATIC
    platform/android/AndroidLogger.cpp)

target_link_libraries(Platform
    -llog)

add_library(BreakItAllLibJNIWrapper
            SHARED
            androidLib.cpp)

target_link_libraries(BreakItAllLibJNIWrapper
    common
    -landroid
    Platform)
