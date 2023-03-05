# Get glfw3
download_project(PROJ   glfw
        GIT_REPOSITORY  https://github.com/glfw/glfw.git
        GIT_TAG         3.3-stable
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})
add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 3.22.1)
    include_directories("${glfw_SOURCE_DIR}/include")
endif()
