#ifndef UTIL_H
#define UTIL_H
#include <conio.h>
#include <windows.h>
#include "Point.h"

namespace util{
    // Move cursor to position <x, y>
    // <x, y> start from <0, 0>
    void gotoxy(int x, int y);
    void gotoxy(const canva::Point &pt);

    // Clear screen
    void clrscr();

    // Delay the process of program
    void delay(const int ms);

    // Set Text and Background Color
    void SetColor(const int color=7);

} // namespace util


#endif