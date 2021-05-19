#ifndef __FILL_ARRAY_H__
#define __FILL_ARRAY_H__

#include <iostream>

void FillArray(DataBox &data)
{
    std::cout << "FillArray()\n";

    std::cout << "Выберите индекс (0 - " << data.sizeOfArr - 1 << ")";
    int i = get_variant(0, data.sizeOfArr - 1);

    std::cout << "Выберите тип строки:\n";
    std::cout << "1. MyString\n";
    std::cout << "2. CIdentifierString\n";
    std::cout << "3. OctString\n";
    int choice = get_variant(1, 3);

    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice == 1)
    {
        std::cout << "Введите строку: ";
        std::getline(std::cin, input);
        MyString *newString = new MyString(input.c_str());
        data.strings[i] = newString;
        std::cout << "Вы ввели: ";
        data.strings[i]->println();
        menu_entry_block_list["TestMyString"] = false;
    }
    else if (choice == 2)
    {
        std::cout << "Введите строку-идентификатор: ";
        std::getline(std::cin, input);
        MyString *newString = new CIdentifierString(input.c_str());
        data.strings[i] = newString;
        std::cout << "Вы ввели: ";
        data.strings[i]->println();
        menu_entry_block_list["TestCIdentifierString"] = false;
    }
    else if (choice == 3)
    {
        std::cout << "Введите строку представляющую восьмеричное число: ";
        std::getline(std::cin, input);
        OctString *newString = new OctString(input.c_str());
        data.strings[i] = newString;
        std::cout << "Вы ввели: ";
        data.strings[i]->println();
        menu_entry_block_list["TestOctString"] = false;
    }
    menu_entry_block_list["TestingMenu"] = false;
    pause();
}

#endif // __FILL_ARRAY_H__
