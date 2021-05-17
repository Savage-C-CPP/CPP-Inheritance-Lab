#ifndef __TEST_MYSTRING_H__
#define __TEST_MYSTRING_H__

#include <iostream>

void TestMyString() {
    std::cout << "TestMyString()\n";
    std::cin.ignore(1024, '\n');
    std::cout << "Press enter to continue...";
    std::cin.get();
}

#endif // __TEST_MYSTRING_H__
