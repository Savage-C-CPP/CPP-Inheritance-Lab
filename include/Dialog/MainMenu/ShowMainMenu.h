#ifndef __SHOW_MAIN_MENU_H__
#define __SHOW_MAIN_MENU_H__

#include "Dialog/MainMenu/MainMenu.h"
#include "MyString.h"
#include <iostream>

void ShowMainMenu(DataBox &data)
{
    while (true)
    {
        system("clear");
        std::cout << "\t-----Главное меню-----\n";
        for (size_t i = 0; i < main_menu_quantity; ++i)
            std::cout << main_menu[i].title << "\n";

        int choice;
        choice = get_variant(main_menu_quantity);
        for (size_t i = 0; i < main_menu_quantity; ++i)
        {
            if (choice == main_menu[i].choice)
            {
                Delegate procedure = main_menu[i].procedure;
                if (!menu_entry_block_list[main_menu[i].entryName]) // Если пункт не заблокирован
                {
                    (procedure)(data);
                    break;
                }
                else
                {
                    if (main_menu[i].entryName == "TestingMenu")
                        block_info("Тестирование недоступно. Убедитесь, что вы заполнили массив строк.");
                    else
                        block_info("Неизвестная причина");
                    break;
                }
            }
        }
    }
}

#endif // __SHOW_MAIN_MENU_H__
