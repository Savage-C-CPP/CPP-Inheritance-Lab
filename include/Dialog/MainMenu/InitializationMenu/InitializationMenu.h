#ifndef __INITIALIZATION_MENU_H__
#define __INITIALIZATION_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./SetArrayCapacity.h"
#include "./FillArray.h"
#include "../ShowMainMenu.h"

void SetArrayCapacity(DataBox &);
void FillArray(DataBox &);
void ShowMainMenu(DataBox &);

static MenuEntry initialization_menu[] =
{
    {1, "SetArrayCapacity", "1. Задать количество элементов", SetArrayCapacity},
    {2, "FillArray", "2. Заполнить данными", FillArray},
    {3, "MainMenu", "3. Назад", ShowMainMenu}
};

static const size_t initialization_menu_quantity =
    sizeof(initialization_menu) / sizeof(initialization_menu[0]);

#endif // __INITIALIZATION_MENU_H__
