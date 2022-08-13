add_library(common STATIC
        Ball.cpp
        Dimension.cpp
        FieldOfView.cpp
        CursorPositionChanged.cpp
        SurfaceChanged.cpp
        KeyPressed.cpp
        ScreenTouched.cpp
        BreakItAll.cpp
        SandBox.cpp
        Test1.cpp
        Test2.cpp
        Test3.cpp
        Test4.cpp
        Camera.cpp
        Object.cpp
        Object3D.cpp
        ShaderProg.cpp
        Game.cpp
        Renderer.cpp
        ShaderLoader.cpp
        Mesh.cpp
        Math.cpp
        Vector.cpp
        GameLoop.cpp
        Point2D.cpp
        Point3D.cpp)

target_link_libraries(common
        Platform
        -lGLESv2
        glm)

target_include_directories(common
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
