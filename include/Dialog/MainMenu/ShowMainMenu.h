#ifndef __SHOW_MAIN_MENU_H__
#define __SHOW_MAIN_MENU_H__

#include "Dialog/MainMenu/MainMenu.h"
#include <iostream>

void ShowMainMenu()
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
                (procedure)();
                break;
            }
        }
    }
}

#endif // __SHOW_MAIN_MENU_H__
