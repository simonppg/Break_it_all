// Copyright (c) 2021 Simon Puente
#include <cstdlib>

#include "App.hpp"

int main(int argc, char **argv) {
  int sceneNumber = 0;

  if (argc > 1) {
    sceneNumber = atoi(argv[1]);
  }

  App().start(sceneNumber);

  return EXIT_SUCCESS;
}
