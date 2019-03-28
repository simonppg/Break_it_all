SRC="*.cpp linux/*cpp"
g++ ${SRC} -DPROJECT_DIR=\"${HOME}/break_it_all/app\" -lGLESv2 -lglfw -o es.out
g++ ${SRC} -DPROJECT_DIR=\"${HOME}/break_it_all/app\" -lGL -lglfw -o gl.out
