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
add_subdirectory(linuxapp)

