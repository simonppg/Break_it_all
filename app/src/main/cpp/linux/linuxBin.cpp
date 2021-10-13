// Copyright (c) 2021 Simon Puente
#include <iostream>
#include <vector>

#include "../common/BreakItAll.hpp"
#include "LinuxLogger.hpp"
#include "WindowManager.hpp"

using namespace std;

int main() {
  Logger *logger = new LinuxLogger();
  logger->sayHello();

  int width = 450, height = 800;
  WindowManager *wm = new WindowManager(NULL);

  if (wm->createWindow(width, height) != 0) {
    exit(EXIT_FAILURE);
  }

  BreakItAll *p = new BreakItAll();
  p->init();

  vector<string> examplesList;

  p->exampleList(&examplesList);

  for (long unsigned int i = 0; i < examplesList.size(); i++) {
    cout << examplesList[i] << endl;
  }

  while (!wm->shouldClose()) {
    wm->pollEvents();

    p->render();

    wm->refreshWindow();
  }

  wm->destroyWindow();
  cout << endl << "Hello World!" << endl << endl;

  return 0;
}
