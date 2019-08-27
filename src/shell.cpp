#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include "Util.h"
#include "Point.h"
#include "Object.h"
#include "Rect.h"
#include "Board.h"
#include "Command.h"
using namespace std;
using namespace util;
using namespace canva;

int main(){
    
    util::clrscr();
    
    // Draw Boundary
    Rect Background(Point(0, 0), Point(10+1, 20+1));
    Background.drawBoundary();

    // Draw Main Board
    Board mainBoard(Point(1, 1), Point(10, 20));
    mainBoard.drawPins();

    // Random Number Generator
    srand(time(NULL));
    int typeRng = rand() % 7;

    // Instantiate Tetris Block
    Object block(typeRng, Point(1,1)); 

    // Instantiate Command
    Command command;
    while(true){

        // Background.drawBoundary();
        // typeRng = rand() % 7;
        // sth1.reset(typeRng, Point(1,1));
        block.draw(true);

        if(kbhit()){
            command.getInput();
            if(command.getKeyType() == ESC){
                break;
            }
            else if(command.getKeyType() == UpArrow){
                util::gotoxy(12, 21);
                printf("^");
            }
            else if(command.getKeyType() == DownArrow){
                util::gotoxy(12, 21);
                printf("v");

                block.draw(false);
                block.move(Point(0,1), mainBoard.getRect());
            }
            else if(command.getKeyType() == LeftArrow){
                util::gotoxy(12, 21);
                printf("<");
            }
            else if(command.getKeyType() == RightArrow){
                util::gotoxy(12, 21);
                printf(">");
            }
            else if(command.getKeyType() == Space){
                util::gotoxy(12, 21);
                printf("s");
            }
        }

        command.reset();

        delay(100);
    }

    util::gotoxy(0,22);
    std::system("Pause");
}