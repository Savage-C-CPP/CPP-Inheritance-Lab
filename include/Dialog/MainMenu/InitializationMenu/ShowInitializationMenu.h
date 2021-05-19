#ifndef __SHOW_INITIALIZATION_MENU_H__
#define __SHOW_INITIALIZATION_MENU_H__

#include "Dialog/MainMenu/InitializationMenu/InitializationMenu.h"
#include <iostream>

void ShowInitializationMenu(DataBox& data)
{
    while (true)
    {
        system("clear");
        std::cout << "\t-----Меню инициализации-----\n";
        for (size_t i = 0; i < initialization_menu_quantity; ++i)
            std::cout << initialization_menu[i].title << "\n";

        int choice;
        choice = get_variant(1, initialization_menu_quantity);
        for (size_t i = 0; i < initialization_menu_quantity; ++i)
        {
            if (choice == initialization_menu[i].choice)
            {
                Delegate procedure = initialization_menu[i].procedure;
                if (!menu_entry_block_list[initialization_menu[i].entryName]) // Если пункт не заблокирован
                {
                    (procedure)(data);
                    break;
                }
                else
                {
                    if (initialization_menu[i].entryName == "SetArrayCapacity")
                        block_info("Задать размер массива можно только 1 раз");
                    else if (initialization_menu[i].entryName == "FillArray")
                        block_info("Сперва задайте размер массива строк");
                    else
                        block_info("Неизвестная причина");
                    break;
                }
            }
        }
    }
}

#endif // __SHOW_INITIALIZATION_MENU_H__
