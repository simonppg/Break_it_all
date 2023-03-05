# Get glm
download_project(PROJ   glm
        GIT_REPOSITORY  https://github.com/g-truc/glm.git
        GIT_TAG         master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 3.22.1)
    include_directories("${glm_SOURCE_DIR}/include")
endif()
