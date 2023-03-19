add_library(Platform
        STATIC
        Platform.cpp)

target_include_directories(Platform
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
