#ifndef __DIALOG_MENU_H__
#define __DIALOG_MENU_H__

#include <limits>

typedef void (*Delegate)(void);

struct MenuEntry
{
    int choice;
    char const *title;
    bool blocked;
    Delegate procedure;
};

char get_variant(unsigned int max)
{
    bool done = false;
    int choice;
    while (!done)
    {
        std::cout << "> ";
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некоректный ввод. Попробуйте снова!\n";
            break;
        }
        else if (choice < 1 || choice > max)
            std::cout << "Некоректный ввод. Попробуйте снова!\n";
        else
            done = true;
    }
    return choice;
}

#endif //__DIALOG_MENU_H__
