add_library(BreakItAll STATIC
            BreakItAll.cpp)

# TODO: remove this, BreakItAll should not know anything about GLES
target_link_libraries(BreakItAll
        -lGLESv2)

target_include_directories(BreakItAll PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})