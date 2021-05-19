#ifndef __DIALOG_MENU_H__
#define __DIALOG_MENU_H__

#include <limits>
#include <map>

// Будем кидать ссылку на такую коробку из процедуры в процедуру и оперировать данными в ней
struct DataBox {
    MyString** strings;
    int sizeOfArr;
    bool filled = false;
};

typedef void (*Delegate)(DataBox&);

struct MenuEntry
{
    int choice;
    char const *entryName;
    char const *title;
    Delegate procedure;
};


char get_variant(unsigned int min, unsigned int max)
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
        else if (choice < min || choice > max)
            std::cout << "Некоректный ввод. Попробуйте снова!\n";
        else
            done = true;
    }
    return choice;
}

void pause() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press enter to continue...";
    std::cin.get();
}

void block_info(const char why[]) {
    std::cout << "Этот пункт недоступен!\n";
    std::cout << "Причина: " << why << "\n";
    pause();
}

std::map<std::string, bool> menu_entry_block_list {
    // Main menu
    {"MainMenu",             false},
    {"InitializationMenu",   false},
    {"TestingMenu",          true},
    // Init menu entries   
    {"SetArrayCapacity",      false},
    {"FillArray",             true},
    // Testing menu   
    {"TestMyString",          true},
    {"TestCIdentifierString", true},
    {"TestOctString",         true}
};

#endif //__DIALOG_MENU_H__
