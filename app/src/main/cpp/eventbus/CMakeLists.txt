add_library(EventBus
        STATIC
        EventBus.cpp
        CursorPositionChanged.cpp
        SurfaceChanged.cpp
        KeyPressed.cpp
        ScreenTouched.cpp
        EventBus.cpp)

target_include_directories(EventBus
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
