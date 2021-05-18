#include <iostream>
#include <CIdentfierString.h>
#include <OctString.h>

#include "Dialog/MainMenu/ShowMainMenu.h"

using std::cin;
using std::cout;

int main(int, char **)
{
    DataBox data;

    ShowMainMenu(data);

    return EXIT_SUCCESS;
}
