add_subdirectory(opengl)

add_library(common STATIC
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
        ShaderProg.cpp
        Game.cpp
        Renderer.cpp
        Mesh.cpp
        Math.cpp
        Vector.cpp
        GameLoop.cpp
        Point2D.cpp
        Point3D.cpp)

target_link_libraries(common
        Platform
        -lGLESv2
        glWrapper
        glm)

target_include_directories(common
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
