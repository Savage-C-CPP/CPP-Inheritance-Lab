#ifndef __TEST_CIDENTIFIERSTRING_H__
#define __TEST_CIDENTIFIERSTRING_H__

#include "Dialog/DialogMenu.h"
#include <iostream>

void TestCIdentifierString(DataBox &data)
{
    std::cout << "TestCIdentifierString()\n";

    std::cout << "Выберите индекс тестируемой строки CIdentifierString (0 - " << data.sizeOfArr - 1 << ")";
    int i = get_variant(0, data.sizeOfArr - 1);

    MyString s;
    std::cout << "Выберите метод:\n";
    std::cout << "1. CIdentifierString::operator[](unsigned int)\n";
    std::cout << "2. CIdentifierString::operator+(MyString)\n";
    std::cout << "3. CIdentifierString::operator+(CIdentifierString)\n";
    std::cout << "4. static CIdentifierString::isValidCIdentifier()\n";
    int choice = get_variant(1, 4);

    system("clear");

    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == 1)
    {
        std::cout << "CIdentifierString::operator[](unsigned int)\n";
        if (data.strings[i]->isEmpty())
        {
            std::cout << "Строка пуста.\n";
            pause();
            return;
        }
        MyString s = *data.strings[i];
        std::cout << "Введите индекс символа (0 - " << s.getLength() - 1 << ")\n";
        unsigned int ix = get_variant(0, s.getLength() - 1);
        std::cout << "В строке \"" << s.getRawData() << "\" по индексу " << ix << " находится символ '" << s[ix] << "'.\n";
    }
    else if (choice == 2)
    {
        std::cout << "CIdentifierString::operator+(MyString)\n";
        std::cout << "Введите строку MyString для конкатенации: ";
        CIdentifierString left, res;
        left = *data.strings[i];
        MyString right;
        std::getline(std::cin, input);
        right = input.c_str();
        res = left + right;
        std::cout << "Результат конкатенации:\n";
        if (res.isEmpty())
            std::cout << "Пустая строка.(В результате конкатенации получилась невалиднай идентификатор)\n";
        else
        {
            std::cout << res.getRawData();
            *data.strings[i] = res; // Перезаписываем старый идентификатор новым
        }
    }
    else if (choice == 3)
    {
        std::cout << "CIdentifierString::operator+(CIdentifierString)\n";
        std::cout << "Введите новый идентификатор для конкатенации: ";
        CIdentifierString left, right, res;
        left = *data.strings[i];
        std::getline(std::cin, input);
        right = input.c_str();
        res = left + right;
        std::cout << "Результат конкатенации:\n";
        std::cout << res.getRawData() << '\n';
        *data.strings[i] = res; // Перезаписываем старый идентификатор новым
    }
    else if (choice == 4)
    {
        std::cout << "static CIdentifierString::isValidCIdentifier()\n";
        std::cout << "Введите строку для проверки на валидность: ";
        std::getline(std::cin, input);
        if (CIdentifierString::isValidCIdentifier(input.c_str()))
            std::cout << "Строка \"" << input << "\" валидный идентификатор в C/C++";
        else
            std::cout << "Строка \"" << input << "\" невалидный идентификатор в C/C++";
    }
    pause();
}

#endif // __TEST_CIDENTIFIERSTRING_H__
