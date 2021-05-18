#ifndef __TESTING_MENU_H__
#define __TESTING_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./TestMyString.h"
#include "./TestCIdentifierString.h"
#include "./TestOctString.h"
#include "../ShowMainMenu.h"

void TestMyString(DataBox &);
void TestCIdentifierString(DataBox &);
void TestOctString(DataBox &);
void ShowMainMenu(DataBox &);

static MenuEntry testing_menu[] =
{
    {1, "TestMyString", "1. MyString", TestMyString},
    {2, "TestCIdentifierString", "2. CIdentifierString", TestCIdentifierString},
    {3, "TestOctString", "3. OctString", TestOctString},
    {4, "MainMenu", "4. Назад", ShowMainMenu},
};

static const size_t testing_meny_quantity =
    sizeof(testing_menu) / sizeof(testing_menu[0]);

#endif // __TESTING_MENU_H__
