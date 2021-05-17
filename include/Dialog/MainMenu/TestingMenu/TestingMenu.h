#ifndef __TESTING_MENU_H__
#define __TESTING_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./TestMyString.h"
#include "./TestCIdentifierString.h"
#include "./TestOctString.h"
#include "../ShowMainMenu.h"

void TestMyString();
void TestCIdentifierString();
void TestOctString();
void ShowMainMenu();

static const MenuEntry testing_menu[] =
{
    {1, "1. MyString",          true,  TestMyString},
    {2, "2. CIdentifierString", true,  TestCIdentifierString},
    {3, "3. OctString",         true,  TestOctString},
    {4, "4. Назад",             false, ShowMainMenu},
};

static const size_t testing_meny_quantity =
    sizeof(testing_menu) / sizeof(testing_menu[0]);

#endif // __TESTING_MENU_H__
