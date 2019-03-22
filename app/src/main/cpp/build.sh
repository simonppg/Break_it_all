g++ linux/main.cpp game.cpp linux/filesManager.cpp triangle.cpp utils.cpp Cube.cpp Camera.cpp square.cpp -DPROJECT_DIR=\"${HOME}/break_it_all/app\" -lGLESv2 -lglfw -o es.out

g++ linux/main.cpp game.cpp linux/filesManager.cpp triangle.cpp utils.cpp Cube.cpp Camera.cpp square.cpp -DPROJECT_DIR=\"${HOME}/break_it_all/app\" -lGL -lglfw -o gl.out
