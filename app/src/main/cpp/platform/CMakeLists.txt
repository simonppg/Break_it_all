# Wrapper library for glfw
add_library(WindowManager STATIC
            linux/WindowManager.cpp)

# Link glfw library to WindowManager
target_link_libraries(WindowManager
                      glfw)

# Make library public available
target_include_directories(WindowManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/linux)
