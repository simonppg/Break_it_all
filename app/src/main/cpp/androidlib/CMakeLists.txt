add_library(AndroidPlatform
  STATIC
  AndroidFilesManager.cpp
  AndroidPlatform.cpp
  AndroidLogger.cpp)

target_link_libraries(AndroidPlatform
  Platform
  StringFormatter
  -landroid
  -llog)

add_library(BreakItAll
  SHARED
  androidLib.cpp)

add_library(Game
  SHARED
  main.cpp)

target_link_libraries(BreakItAll
  common
  AndroidPlatform)

target_link_libraries(Game
  common
  AndroidPlatform)
