cmake_minimum_required(VERSION 3.4.1)

add_library(game SHARED
            src/main/cpp/game.c
            src/main/cpp/utils.c
            src/main/cpp/triangle.c
            src/main/cpp/square.c)

add_library(gameLibJNIWrapper SHARED
            src/main/cpp/jni.c)

target_link_libraries(gameLibJNIWrapper
                      game)

target_link_libraries(gameLibJNIWrapper
                      -landroid
                      -llog
                      -lGLESv3)

target_link_libraries(game
                      -landroid
                      -llog
                      -lGLESv3)

                  #target_link_libraries(gameLibJNIWrapper
                  #   ${android}
                  #   ${log}
                  #   ${GLESv3}
                  #   ${JNI})

                  #target_link_libraries(game
                  #   ${android}
                  #   ${log}
                  #   ${GLESv3})
