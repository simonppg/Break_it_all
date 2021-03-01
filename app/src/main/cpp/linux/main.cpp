#include <iostream>
#include "BreakItAll.hpp"

int main() {
    BreakItAll *p = new BreakItAll();

    p->init();

    std::cout << std::endl << "Hello World!" << std::endl << std::endl;
    return 0;
}
