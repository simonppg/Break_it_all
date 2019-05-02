add_library(common STATIC
        src/common/SandBox.cpp
        src/common/Test1.cpp
        src/common/Test2.cpp
        src/common/Test3.cpp
        src/common/Test4.cpp
        src/common/Camera.cpp
        src/common/Object.cpp
        src/common/ShaderProg.cpp
        src/common/game.cpp
        src/common/Renderer.cpp
        src/common/Mesh.cpp)

target_link_libraries(common
        hal
        math
        -lGLESv2
        glm)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)