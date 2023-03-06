#include <iostream>
#include <vector>

#include "../common/BreakItAll.hpp"
#include "LinuxLogger.hpp"
#include "windowmanager/WindowManager.hpp"

using std::cout;
using std::endl;

int main() {
  Logger *logger = new LinuxLogger();
  logger->sayHello();

  int width = 450, height = 800;
  WindowManager *wm = new WindowManager(NULL);

  try {
    wm->createWindow(width, height);
  } catch (const WindowCanNotBeCreated &ex) {
    logger->logi("%s", ex.what());
    exit(EXIT_FAILURE);
  }

  BreakItAll *p = new BreakItAll();
  p->init();

  vector<string> examplesList;

  p->exampleList(&examplesList);

  for (string example : examplesList) {
    cout << example << endl;
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
