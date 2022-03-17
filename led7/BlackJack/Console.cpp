#include "Console.h"

namespace Console
{
    void size_console()
    {
        HWND hwnd = GetConsoleWindow();
        if (hwnd != nullptr)
        {
            MoveWindow(hwnd, 150, 150, 950, 600, TRUE);
        }
    }

    void clear_console()
    {
        const COORD top_left = { 0, 0 };
        const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, top_left, &written
        );
        FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, top_left, &written
        );
        SetConsoleCursorPosition(console, top_left);
    }
}