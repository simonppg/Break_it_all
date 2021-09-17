include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)

add_subdirectory(common)

add_library(Platform
    STATIC
    android/logger.hpp
    android/filesManager.cpp
    android/AndroidLogger.cpp)

target_link_libraries(Platform
    -landroid
    -llog)

add_library(BreakItAllLibJNIWrapper
    SHARED
    android/androidLib.cpp)

add_library(gameLibJNIWrapper
    SHARED
    android/main.cpp)

target_link_libraries(BreakItAllLibJNIWrapper
    common)

target_link_libraries(gameLibJNIWrapper
    common)
