#ifndef __FILL_ARRAY_H__
#define __FILL_ARRAY_H__

#include <iostream>

void FillArray() {
    std::cout << "FillArray()\n";
    std::cin.ignore(1024, '\n');
    std::cout << "Press enter to continue...";
    std::cin.get();
}

#endif // __FILL_ARRAY_H__
