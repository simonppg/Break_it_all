# Get googletest
download_project(PROJ   googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         v1.8.x
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")
endif()
