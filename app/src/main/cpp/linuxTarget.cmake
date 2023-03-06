add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")

include(cmake/DownloadProject.cmake)
include(cmake/glm.cmake)
include(cmake/glfw.cmake)

add_subdirectory(shared/strings)
add_subdirectory(common)
add_subdirectory(linux/windowmanager)

add_library(Platform
  STATIC
  linux/LinuxFilesManager.cpp
  linux/LinuxPlatform.cpp
  linux/LinuxLogger.cpp)

target_link_libraries(Platform
  StringFormatter
  WindowManager)

add_executable(linuxVersion
  linux/linuxBin.cpp)

add_executable(linuxLauncher
  linux/GLFWKeyMapper.cpp
  linux/App.cpp
  linux/main.cpp)

target_link_libraries(linuxVersion
  common)

target_link_libraries(linuxLauncher
  common)

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

