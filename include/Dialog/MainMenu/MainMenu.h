#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./InitializationMenu/ShowInitializationMenu.h"
#include "./TestingMenu/ShowTestingMenu.h"
#include "./Exit.h"

void ShowInitializationMenu(DataBox &);
void ShowTestingMenu(DataBox &);
void Exit(DataBox &);

static MenuEntry main_menu[] =
{
    {1, "InitializationMenu", "1. Инициализация", ShowInitializationMenu},
    {2, "TestingMenu", "2. Тестирование", ShowTestingMenu},
    {3, "Exit", "3. Выход", Exit},
};

static const size_t main_menu_quantity =
    sizeof(main_menu) / sizeof(main_menu[0]);

#endif // __MAIN_MENU_H__
