# Get googletest
download_project(PROJ   googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         release-1.11.0
        ${UPDATE_DISCONNECTED_IF_AVAILABLE})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
if (CMAKE_VERSION VERSION_LESS 3.22.1)
    include_directories("${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")
endif()
