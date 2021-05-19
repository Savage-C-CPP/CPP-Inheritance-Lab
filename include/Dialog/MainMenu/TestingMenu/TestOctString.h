#ifndef __TEST_OCTSTRING_H__
#define __TEST_OCTSTRING_H__

#include "Dialog/DialogMenu.h"
#include <iostream>

void TestOctString(DataBox &data)
{
    std::cout << "TestOctString()\n";

    std::cout << "Выберите индекс тестируемой строки OctString (0 - " << data.sizeOfArr - 1 << ")";
    int i = get_variant(0, data.sizeOfArr - 1);

    MyString s;
    std::cout << "Выберите метод:\n";
    std::cout << "1. OctString::ConvertableToUnsignedLong()\n";
    std::cout << "2. OctString::operator+(OctString)\n";
    std::cout << "3. OctString::operator=(MyString)\n";
    int choice = get_variant(1, 3);

    system("clear");

    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == 1)
    {
        std::cout << "OctString::ConvertableToUnsignedLong()\n";
        OctString s = *data.strings[i];
        if (s.ConvertableToUnsignedLong())
            std::cout << "OctString \"" << s.getRawData() << "\" может быть представлена типом unsigned long.\n";
        else
            std::cout << "OctString \"" << s.getRawData() << "\" не может быть представлена типом unsigned long.\n";
    }
    else if (choice == 2)
    {
        std::cout << "OctString::operator+(OctString)\n";
        std::cout << "Введите 2 операнд восьмеричную строку: ";
        OctString op1, op2, res;
        op1 = *data.strings[i];
        std::getline(std::cin, input);
        op2 = input.c_str();
        res = op1 + op2;
        std::cout << "Результат вычисления:\n";
        std::cout << op1.getRawData() << " + " << op2.getRawData() << " = " << res.getRawData();
    }
    else if (choice == 3)
    {
        std::cout << "OctString::operator=(MyString)\n";
        std::cout << "Введите строку MyString, которая представляет собой восимеричное число: ";
        OctString octString;
        MyString myString;
        octString = *data.strings[i];
        std::getline(std::cin, input);
        myString = input.c_str();
        octString = myString;
        std::cout << "Полученная восьмеричная строка: " << octString.getRawData() << '\n';
        *data.strings[i] = octString; // Перезаписывает текущее значение новой octstring
    }
    pause();
}

#endif // __TEST_OCTSTRING_H__
