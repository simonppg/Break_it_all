include(cmake/DownloadProject.cmake)

# Dependencies
include(cmake/glm.cmake)
include(cmake/googletest.cmake)

# Local dependencies
add_subdirectory(common)
# add_subdirectory(tests)

add_library(Platform STATIC
    hal/src/android/logger.hpp
    hal/src/android/filesManager.cpp
    platform/android/AndroidLogger.cpp)

target_link_libraries(Platform
    -landroid
    -llog)

add_library(BreakItAllLibJNIWrapper
            SHARED
            android/androidLib.cpp)

target_link_libraries(BreakItAllLibJNIWrapper
    common
    -landroid
    Platform)

add_library(gameLibJNIWrapper
        SHARED
        android/main.cpp)

target_link_libraries(gameLibJNIWrapper
        common)

