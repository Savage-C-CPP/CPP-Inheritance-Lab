#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./InitializationMenu/ShowInitializationMenu.h"
#include "./TestingMenu/ShowTestingMenu.h"
#include "./Exit.h"

void ShowInitializationMenu();
void ShowTestingMenu();
void Exit();

static const MenuEntry main_menu[] =
{
    {'1', "1. Инициализация", false, ShowInitializationMenu},
    {'2', "2. Тестирование",  true,  ShowTestingMenu},
    {'3', "3. Выход",         false, Exit},
};

static const size_t main_menu_quantity =
    sizeof(main_menu) / sizeof(main_menu[0]);

#endif // __MAIN_MENU_H__
