add_library(PlatformBase
        STATIC
        Platform.cpp)

target_include_directories(PlatformBase
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
