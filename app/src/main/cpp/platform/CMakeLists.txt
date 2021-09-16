if(ANDROID)

# Platform specific code
    add_library(AndroidPlatform STATIC
        android/AndroidLogger.cpp)

    target_link_libraries(AndroidPlatform
        -llog)

else(ANDROID)

# Wrapper library for glfw
    add_library(WindowManager STATIC
                linux/WindowManager.cpp)

# Link glfw library to WindowManager
    target_link_libraries(WindowManager
                          glfw)

# Make library public available
    target_include_directories(WindowManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/linux)


# Platform specific code
    add_library(LinuxPlatform STATIC
        linux/LinuxLogger.cpp)

    target_link_libraries(LinuxPlatform
        WindowManager)

endif(ANDROID)
