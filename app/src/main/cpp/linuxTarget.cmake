add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")

include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)
include(cmake/glfw.cmake)

add_subdirectory(stringformatter)
add_subdirectory(eventbus)
add_subdirectory(platform)
add_subdirectory(glwrapper)
add_subdirectory(game)
add_subdirectory(linuxapp/windowmanager)

add_library(LinuxPlatform
  STATIC
  linuxapp/LinuxFilesManager.cpp
  linuxapp/LinuxPlatform.cpp
  linuxapp/LinuxLogger.cpp)

target_link_libraries(LinuxPlatform
  Platform
  StringFormatter
  WindowManager)

add_executable(linuxVersion
  linuxapp/linuxBin.cpp)

add_executable(linuxLauncher
  linuxapp/GLFWKeyMapper.cpp
  linuxapp/App.cpp
  linuxapp/main.cpp)

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

