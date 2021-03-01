#include <iostream>
#include "BreakItAll.hpp"
#include "WindowManager.hpp"

int main() {
    BreakItAll *p = new BreakItAll();

    p->init();

    int width = 450, height = 800;

    WindowManager *wm = new WindowManager();

    if(wm->createWindow(width, height) != 0) {
        exit(EXIT_FAILURE);
    }

    while (!wm->shouldClose()) {
        wm->pollEvents();
        
        wm->refreshWindow();
    }

    wm->destroyWindow();
    std::cout << std::endl << "Hello World!" << std::endl << std::endl;
    return 0;
}

