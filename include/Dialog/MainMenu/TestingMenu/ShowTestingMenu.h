#ifndef __SHOW_TESTING_MENU_H__
#define __SHOW_TESTING_MENU_H__

#include "Dialog/DialogMenu.h"
#include "./TestingMenu.h"

using std::cout;

void ShowTestingMenu(DataBox &data)
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
                if (!menu_entry_block_list[testing_menu[i].entryName]) // Если пункт не заблокирован
                {
                    (procedure)(data);
                    break;
                }
                else
                {
                    // if (initialization_menu[i].entryName == "SetArrayCapacity")
                    //     block_info("Задать размер массива можно только 1 раз");
                    // if (initialization_menu[i].entryName == "FillArray")
                    //     block_info("Сперва задайте размер массива строк");
                    // else
                    //     block_info("Неизвестная причина");
                    block_info("Тестирование этого класса недоступно. (Вероятно вы его не добавили в массив DataBox.strings*");
                    break;
                }
            }
        }
    }
}

#endif // __SHOW_TESTING_MENU_H__
