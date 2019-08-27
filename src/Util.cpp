#include <conio.h>
#include <windows.h>
#include "Point.h"

static HANDLE hConsole = 0;
static int instanceCount = 0;

namespace util{
    void gotoxy(int x, int y){

        COORD coord;
        
        if (instanceCount == 0){
            hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
            instanceCount = 1;
        }

        coord.X = x;
        coord.Y = y;

        SetConsoleCursorPosition(hConsole, coord);
    }

    void gotoxy(const canva::Point &pt){
        gotoxy(pt.canva::Point::getX(), pt.canva::Point::getY());
    }

    void clrscr(){

        // Here's where we'll home the cursor
        COORD coordStart = {0, 0};
        DWORD cCharWritten;

        // To get buffer info
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        
        // Number of character cells in the current buffer
        // DWORD: Console Size
        DWORD dwConSize;

        if (instanceCount == 0){
            hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
            instanceCount = 1;
        }

        // Get Console Screen Buffer Info 
        // to get the number of character cells in the current buffer
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

        // Fill with blanks
        FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordStart, &cCharWritten);

        // Set Cursor Position to Start Positiion <0, 0>
        SetConsoleCursorPosition(hConsole, coordStart);

    }

    void delay(int ms){
        Sleep(ms);
    }
} // namespace util


