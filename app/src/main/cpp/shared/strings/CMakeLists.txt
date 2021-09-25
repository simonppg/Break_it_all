add_library(StringFormatter
        STATIC
        StringFormatter.cpp)

target_include_directories(StringFormatter
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
