add_library(common STATIC
        Dimension.cpp
        FieldOfView.cpp
        BreakItAll.cpp
        SandBox.cpp
        Test1.cpp
        Test2.cpp
        Test3.cpp
        Test4.cpp
        Camera.cpp
        Object.cpp
        ShaderProg.cpp
        game.cpp
        Renderer.cpp
        Mesh.cpp
        Math.cpp
        Vector.cpp
        Point3D.cpp)

target_link_libraries(common
        Platform
        -lGLESv2
        glm)

target_include_directories(common
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
