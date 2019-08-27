#include <cstdio>
#include <windows.h>
#include "Util.h"
#include "Point.h"
#include "Object.h"
#include "Rect.h"
#include <cstdlib>
#include <time.h>
using namespace std;
using namespace util;
using namespace canva;

int main(){
    
    util::clrscr();
    
    Rect Background(Point(0, 0), Point(10+2, 20+2));
    Background.drawBoundary();
    Object sth1(0, Point(1,1)); 

    srand(time(NULL));
    int typeRng = rand() % 7;
    while(true){

        // Background.drawBoundary();

        typeRng = rand() % 7;
        sth1.reset(typeRng, Point(1,1));
        
        sth1.draw(true);
        delay(333);
        sth1.draw(false);
        delay(333);

    }

    gotoxy(0,21);
    system("Pause");
}