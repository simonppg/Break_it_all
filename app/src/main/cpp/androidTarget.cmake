include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)

add_subdirectory(shared/strings)
add_subdirectory(common)

add_library(Platform
  STATIC
  android/AndroidFilesManager.cpp
  android/AndroidPlatform.cpp
  android/AndroidLogger.cpp)

target_link_libraries(Platform
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
  common)

target_link_libraries(Game
  common)
