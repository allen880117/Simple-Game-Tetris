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
    util::SetColor(7);
    // Draw Boundary
    Rect Background(Point(0, 0), Point(10+1, 20+1));
    Background.drawBoundary();

    // Draw Main Board
    Board mainBoard(Point(1, 1), Point(10, 20));
    util::SetColor(10);
    mainBoard.drawPins();

    // Random Number Generator
    srand(time(NULL));
    int typeRng = rand() % 7;

    // Instantiate Tetris Block
    Point generatePoint = mainBoard.getRect().getLeftTop() 
                            + Point(mainBoard.getWidth()/2 -2 , 0);
    Object block(typeRng, generatePoint); 

    // Instantiate Command
    Command command;
    while(true){

        // typeRng = rand() % 7;
        // block.reset(typeRng, Point(1,1));
        util::SetColor(4);
        block.draw(true);

        if(kbhit()){
            command.getInput();
            if(command.getKeyType() == ESC){
                break;
            }
            else if(command.getKeyType() == UpArrow){
                util::gotoxy(12, 21);
                printf("^");
                block.draw(false);
                block.turn(CLOCKWISE, mainBoard);
            }
            else if(command.getKeyType() == DownArrow){
                util::gotoxy(12, 21);
                printf("v");

                block.draw(false);
                block.move(Point(0,1), mainBoard);
            }
            else if(command.getKeyType() == LeftArrow){
                util::gotoxy(12, 21);
                printf("<");

                block.draw(false);
                block.move(Point(-1,0), mainBoard);
            }
            else if(command.getKeyType() == RightArrow){
                util::gotoxy(12, 21);
                printf(">");

                block.draw(false);
                block.move(Point(1,0), mainBoard);
            }
            else if(command.getKeyType() == Space){
                util::gotoxy(12, 21);
                printf("s");
            }
        }

        command.reset();
        util::gotoxy(0,0);
        delay(33);
    }

    util::gotoxy(0,22);
    std::system("Pause");
}