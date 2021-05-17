#ifndef __INITIALIZATION_MENU_H__
#define __INITIALIZATION_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./SetArrayCapacity.h"
#include "./FillArray.h"
#include "../ShowMainMenu.h"

void SetArrayCapacity();
void FillArray();
void ShowMainMenu();

static const MenuEntry initialization_menu[] =
{
    {'1', "1. Задать количество элементов", false, SetArrayCapacity},
    {'2', "2. Заполнить данными", true, FillArray},
    {'3', "3. Назад", false, ShowMainMenu},
};

static const size_t initialization_menu_quantity =
    sizeof(initialization_menu) / sizeof(initialization_menu[0]);

#endif // __INITIALIZATION_MENU_H__
