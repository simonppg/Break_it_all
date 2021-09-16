add_library(math STATIC
        math_utils.cpp
        Vector.cpp)

target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
