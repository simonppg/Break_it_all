add_library(LinuxPlatform
  STATIC
  LinuxFilesManager.cpp
  LinuxPlatform.cpp
  LinuxLogger.cpp)

target_link_libraries(LinuxPlatform
  Platform
  StringFormatter
  WindowManager)

add_executable(linuxVersion
  linuxBin.cpp)

add_executable(linuxLauncher
  GLFWKeyMapper.cpp
  App.cpp
  main.cpp)

target_link_libraries(linuxVersion
  common
  LinuxPlatform)

target_link_libraries(linuxLauncher
  common
  LinuxPlatform)

set_target_properties(linuxLauncher linuxVersion
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_custom_target(runNew
  COMMAND linuxVersion
  DEPENDS linuxVersion
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_custom_target(run
  COMMAND linuxLauncher ${CMD_ARGS}
  DEPENDS linuxLauncher
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

