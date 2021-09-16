if(ANDROID)

# Platform specific code
    add_library(AndroidPlatform STATIC
        android/AndroidLogger.cpp)

    target_link_libraries(AndroidPlatform
        -llog)

else(ANDROID)
endif(ANDROID)
