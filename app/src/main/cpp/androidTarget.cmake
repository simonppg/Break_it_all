include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)

add_subdirectory(shared/strings)
add_subdirectory(shared/eventbus)
add_subdirectory(shared/platform)
add_subdirectory(common)

add_library(AndroidPlatform
  STATIC
  android/AndroidFilesManager.cpp
  android/AndroidPlatform.cpp
  android/AndroidLogger.cpp)

target_link_libraries(AndroidPlatform
  Platform
  StringFormatter
  -landroid
  -llog)

add_library(BreakItAll
  SHARED
  android/androidLib.cpp)

add_library(Game
  SHARED
  android/main.cpp)

target_link_libraries(BreakItAll
  common
  AndroidPlatform)

target_link_libraries(Game
  common
  AndroidPlatform)
