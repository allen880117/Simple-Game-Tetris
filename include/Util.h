#ifndef UTIL_H
#define UTIL_H
#include <conio.h>
#include <windows.h>

// Move cursor to position <x, y>
// <x, y> start from <0, 0>
void gotoxy(int x, int y);

// Clear screen
void clrscr();

// Delay the process of program
void delay(int ms);

// Change the text color of console
// WORD setTextColor(WORD color);

#endif