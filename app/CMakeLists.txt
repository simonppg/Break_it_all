cmake_minimum_required(VERSION 3.4.1)

add_library(game SHARED
            src/main/cpp/game.c
            src/main/cpp/utils.c
            src/main/cpp/triangle.c
            src/main/cpp/jni.c)

target_link_libraries(game
                      -llog
                      -lGLESv2)
