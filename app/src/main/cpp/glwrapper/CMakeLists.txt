add_library(glWrapper STATIC
        Gl.cpp
        ShaderLoader.cpp)

target_link_libraries(glWrapper
        -lGLESv2)

target_include_directories(glWrapper
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
