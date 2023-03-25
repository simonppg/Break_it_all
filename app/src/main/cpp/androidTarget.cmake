include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)

add_subdirectory(stringformatter)
add_subdirectory(eventbus)
add_subdirectory(platform)
add_subdirectory(glwrapper)
add_subdirectory(game)

add_library(AndroidPlatform
  STATIC
  androidlib/AndroidFilesManager.cpp
  androidlib/AndroidPlatform.cpp
  androidlib/AndroidLogger.cpp)

target_link_libraries(AndroidPlatform
  Platform
  StringFormatter
  -landroid
  -llog)

add_library(BreakItAll
  SHARED
  androidlib/androidLib.cpp)

add_library(Game
  SHARED
  androidlib/main.cpp)

target_link_libraries(BreakItAll
  common
  AndroidPlatform)

target_link_libraries(Game
  common
  AndroidPlatform)
