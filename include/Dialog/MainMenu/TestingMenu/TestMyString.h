#ifndef __TEST_MYSTRING_H__
#define __TEST_MYSTRING_H__

#include "Dialog/DialogMenu.h"
#include <iostream>

void TestMyString(DataBox& data) {
    std::cout << "TestMyString()\n";

    std::cout << "Выберите индекс тестируемой строки MyString (0 - " << data.sizeOfArr - 1 << ")";
    int i = get_variant(0, data.sizeOfArr - 1);

    MyString s;
    std::cout << "Выберите метод:\n";
    std::cout << "1. MyString::getLength()\n";
    std::cout << "2. MyString::operator=(MyString)\n";
    std::cout << "3. MyString::operator=(const char[])\n";
    int choice = get_variant(1, 3);

    system("clear");

    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == 1)
    {
        std::cout << "MyString::GetLength()\n";
        std::cout << "Строка \"" << data.strings[i]->getRawData() << "\"\n";
        auto l = data.strings[i]->getLength();
        std::cout << "Результат MyString::getLength() " << l << '\n';
    }
    else if (choice == 2)
    {
        std::cout << "MyString::operator=(MyString)\n";
        std::cout << "Введите новую строку: ";
        std::getline(std::cin, input);
        MyString str1, str2(input.c_str());
        str1 = str2;
        std::cout << "Вы ввели: ";
        str1.println();
        *data.strings[i] = str1; // Перезаписывает текущее значение новой строкой
    }
    else if (choice == 3)
    {
        std::cout << "MyString::operator=(const char[])\n";
        std::cout << "Введите новую строку: ";
        std::getline(std::cin, input);
        MyString str;
        str = input.c_str();
        std::cout << "Вы ввели: ";
        str.println();
        *data.strings[i] = str; // Перезаписывает текущее значение новой строкой
    }
    pause();
}

#endif // __TEST_MYSTRING_H__
