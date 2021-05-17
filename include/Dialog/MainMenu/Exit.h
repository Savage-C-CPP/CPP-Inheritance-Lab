#ifndef __EXIT_H__
#define __EXIT_H__

#include <iostream>

void Exit() {
    std::cout << "Exit()\n";
    std::cin.ignore(1024, '\n');
    std::cout << "Press enter to continue...";
    std::cin.get();
    exit(0);
}

#endif // __EXIT_H__
