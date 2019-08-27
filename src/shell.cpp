#include <cstdio>
#include <windows.h>
#include "Util.h"
using namespace std;

int main(){
    
    clrscr();

    gotoxy(5, 5);
    printf("HELLO WORLD\n");

    delay(1000);
    clrscr();
    delay(1000);

    gotoxy(7, 7);
    printf("YO AGAIN\n");

    gotoxy(8, 8);
    system("PAUSE");
}