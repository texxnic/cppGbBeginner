#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include "Colours.h"
#include "Field.h"
#include "Game.h"

Field field;

int main()
{
    Console::size_console();
    std::cout << Colours::Code::S_BRICHT_YELLOW << "\n" << field.title_bj() << Colours::Code::DEFAULT << "\n";
    std::cout << "Press any key to continue...\n";
    system("pause");
    Console::clear_console();
    field.menu_main();
    while (field.get_continue())
    {
        if (!field.get_menu() && !field.get_continue())
        {
            break;
        }

        Game new_game(field.names);
        new_game.play();
        std::cout << "\n";

        std::cout << "Do you want play again?\nEnter 'Y' - Yes or 'N' - No : \n";
        switch (_getch())
        {
        case 'y':
            Console::clear_console();
            continue;
        case 'Y':
            Console::clear_console();
            continue;
        case 'n':
            new_game.~Game();
            field.names.clear();
            Console::clear_console();
            field.set_menu();
            field.menu_main();
            break;
        case 'N':
            new_game.~Game();
            field.names.clear();
            Console::clear_console();
            field.set_menu();
            field.menu_main();
            break;
        default: ;
        }
    }
    field.~Field();

    return 0;
}