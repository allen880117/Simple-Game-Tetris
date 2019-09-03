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
    
    /* ***** Pre Process ***** */
    // Random Number Generator
    srand(time(NULL));
    int typeRng = rand() % 7;

    // Instantiate Command, Main Board and Tetris Block
    Board mainBoard(Point(1, 1), Point(10, 20));
    Point generatePoint = mainBoard.getRect().getLeftTop() + Point(mainBoard.getWidth()/2 -2 , 0);
    Object block(typeRng, generatePoint); 
    Command command;

    // Clean Screen and Draw outer boundary
    util::clrscr();
    util::SetColor(10);
    mainBoard.getRect().drawOuterBoundary();

    /* ***** Main Process ***** */
    // Main Loop
    while(true){
        
        // Initialize collision counters
        int BottomTouchCounter = 0;

        // Re-Generate Block
        typeRng = rand() % 7;
        block.reset(typeRng, generatePoint);
        
        // 
        if(block.isTouchPins(mainBoard)){
            util::gotoxy(mainBoard.getRect().getRightBottom()+Point(2, 0));
            std::printf("GAME OVER");
            // Out of Main Loop
            goto END;
        }

        util::SetColor(7);        
        block.draw(true);

        while(true){

            util::delay(cc::delayTime);

            if(kbhit()){

                command.getInput();
                
                if(command.getKeyType() == command.ESC){
                    goto END;
                } else if(command.getKeyType() == command.UpArrow){
                    block.draw(false);
                    block.turn(block.CLOCKWISE, mainBoard);
                    block.draw(true);                
                } else if(command.getKeyType() == command.DownArrow){
                    block.draw(false);
                    block.move(Point(0,1), mainBoard);
                    block.draw(true);                
                } else if(command.getKeyType() == command.LeftArrow){
                    block.draw(false);
                    block.move(Point(-1,0), mainBoard);
                    block.draw(true);                
                } else if(command.getKeyType() == command.RightArrow){
                    block.draw(false);
                    block.move(Point(1,0), mainBoard);
                    block.draw(true);                
                } else if(command.getKeyType() == command.Space){
                    block.draw(false);
                    while(block.move(Point(0,1), mainBoard));
                    BottomTouchCounter = 3;
                    block.draw(true);
                }

            } else {
                block.draw(false);
                block.move(Point(0,1), mainBoard);
                block.draw(true);
            }
            
            if(block.isDownEnable(mainBoard)){
                BottomTouchCounter = 0;
            } else {
                BottomTouchCounter++;
            }

            if(BottomTouchCounter >= 3){
                block.draw(false);
                mainBoard.setObjectPins(block);
                mainBoard.lineCheckAndRearrange();
                
                util::SetColor(4);
                mainBoard.drawPins();
                break;
            }

            command.reset();
        }
    }

    /* ***** End Process ***** */
    END:
        util::gotoxy(0,22);
        std::system("Pause");
}