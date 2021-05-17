#ifndef __SHOW_INITIALIZATION_MENU_H__
#define __SHOW_INITIALIZATION_MENU_H__

#include "Dialog/MainMenu/InitializationMenu/InitializationMenu.h"
#include <iostream>

void ShowInitializationMenu()
{
    while (true)
    {
        system("clear");
        std::cout << "\t-----Меню инициализации-----\n";
        for (size_t i = 0; i < initialization_menu_quantity; ++i)
            std::cout << initialization_menu[i].title << "\n";

        int choice;
        choice = get_variant(initialization_menu_quantity);
        for (size_t i = 0; i < initialization_menu_quantity; ++i)
        {
            if (choice == initialization_menu[i].choice)
            {
                Delegate procedure = initialization_menu[i].procedure;
                (procedure)();
                break;
            }
        }
    }
}

#endif // __SHOW_INITIALIZATION_MENU_H__
