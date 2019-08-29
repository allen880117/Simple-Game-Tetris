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
#include "ConstParam.h"
using namespace std;
using namespace util;
using namespace canva;

int main(){
    
    util::clrscr();

    // Draw Main Board
    Board mainBoard(Point(1, 1), Point(10, 20));
    util::SetColor(10);
    mainBoard.getRect().drawOuterBoundary();
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
        int BottomTouchCounter = 0;
        
        util::SetColor(7);
        block.reset(rand()%7, generatePoint);
        block.draw(true);
        util::delay(333);

        while(true){

            util::delay(333);

            if(kbhit()){
                command.getInput();
                if(command.getKeyType() == command.ESC){
                    break;
                }
                else if(command.getKeyType() == command.UpArrow){
                    util::gotoxy(12, 21);
                    printf("^");
                    block.draw(false);
                    block.turn(block.CLOCKWISE, mainBoard);
                    block.draw(true);                
                }
                else if(command.getKeyType() == command.DownArrow){
                    util::gotoxy(12, 21);
                    printf("v");

                    block.draw(false);
                    block.move(Point(0,1), mainBoard);
                    block.draw(true);                
                }
                else if(command.getKeyType() == command.LeftArrow){
                    util::gotoxy(12, 21);
                    printf("<");

                    block.draw(false);
                    block.move(Point(-1,0), mainBoard);
                    block.draw(true);                
                }
                else if(command.getKeyType() == command.RightArrow){
                    util::gotoxy(12, 21);
                    printf(">");

                    block.draw(false);
                    block.move(Point(1,0), mainBoard);
                    block.draw(true);                
                }
                else if(command.getKeyType() == command.Space){
                    util::gotoxy(12, 21);
                    printf("s");
                }

            } else{
                block.draw(false);
                block.move(Point(0,1), mainBoard);
                block.draw(true);
            }
            
            if(block.isDownEnable(mainBoard)){
                BottomTouchCounter = 0;
            } else {
                BottomTouchCounter++;
            }

            command.reset();
            util::gotoxy(0,0);
            printf("%d",BottomTouchCounter);

            if(BottomTouchCounter == 3){
                block.draw(false);
                mainBoard.setObjectPins(block);
                mainBoard.lineCheckAndRearrange();
                
                util::SetColor(4);
                mainBoard.drawPins();
                break;
            }
        }

        if(command.getKeyType() == command.ESC)
            break;
    }

    util::gotoxy(0,22);
    std::system("Pause");
}