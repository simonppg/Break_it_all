add_subdirectory(opengl)

add_library(common STATIC
        Ball.cpp
        Dimension.cpp
        DrawContext.cpp
        FieldOfView.cpp
        event/CursorPositionChanged.cpp
        event/SurfaceChanged.cpp
        event/KeyPressed.cpp
        event/ScreenTouched.cpp
        BreakItAll.cpp
        SandBox.cpp
        Scene.cpp
        Test1.cpp
        Test2.cpp
        Test3.cpp
        Test4.cpp
        Camera.cpp
        Object.cpp
        Object3D.cpp
        ObjectDrawer.cpp
        ShaderProg.cpp
        Game.cpp
        Renderer.cpp
        Mesh.cpp
        MeshFactory.cpp
        Math.cpp
        Vector.cpp
        GameLoop.cpp
        Point2D.cpp
        Point3D.cpp)

target_link_libraries(common
        Platform
        glWrapper
        glm)

target_include_directories(common
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
