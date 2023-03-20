include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)

add_subdirectory(stringformatter)
add_subdirectory(eventbus)
add_subdirectory(platform)
add_subdirectory(glwrapper)
add_subdirectory(game)

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
