include(cmake/DownloadProject.cmake)

# Dependencies
include(cmake/glm.cmake)
include(cmake/googletest.cmake)

# Local dependencies
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

add_library(hal
        hal/src/android/logger.hpp
        hal/src/android/filesManager.cpp)

target_link_libraries(hal
        -landroid
        -llog)

add_library(gameLibJNIWrapper
        SHARED
        hal/src/android/main.cpp)

target_link_libraries(gameLibJNIWrapper
        common)

