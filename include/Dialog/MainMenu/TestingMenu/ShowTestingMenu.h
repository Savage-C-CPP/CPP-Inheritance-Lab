#ifndef __SHOW_TESTING_MENU_H__
#define __SHOW_TESTING_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./TestingMenu.h"

using std::cout;

void ShowTestingMenu()
{
    while (true)
    {
        system("clear");
        std::cout << "\t-----Меню тестирования-----\n";
        for (size_t i = 0; i < testing_meny_quantity; ++i)
            std::cout << testing_menu[i].title << "\n";

        int choice;
        choice = get_variant(testing_meny_quantity);
        for (size_t i = 0; i < testing_meny_quantity; ++i)
        {
            if (choice == testing_menu[i].choice)
            {
                Delegate procedure = testing_menu[i].procedure;
                (procedure)();
                break;
            }
        }
    }
}

#endif // __SHOW_TESTING_MENU_H__
