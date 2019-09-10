#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "Tetris.h"
#include "Util.h"
#include "Point.h"
#include "Object.h"
#include "Rect.h"
#include "Board.h"
#include "Command.h"
#include "ConstParam.h"

namespace simple_game_tetris{

    Tetris::Tetris(){
        this->mainBoard = new canva::Board(canva::Point(1,1), canva::Point(10, 20));
        this->generatePoint = this->mainBoard->getRect().getLeftTop() + canva::Point(this->mainBoard->getWidth()/2 -2, 0);
        this->block = new canva::Object(this->PROCESS_RNG(), this->generatePoint);
        this->command = new util::Command();
        this->BottomTouchCounter = 0;

        srand(time(NULL));
    }

    Tetris::~Tetris(){
        delete this->mainBoard;
        delete this->block;
        delete this->command;
    }

    int Tetris::PROCESS_ALL(){
        util::clrscr();
        this->PROCESS_DRAW_BOUNDARY();

        while(true){
            this->PROCESS_RESET_BTC();
            this->PROCESS_RESET_BLOCK();
            if(!this->PROCESS_CHECK_GENERATE()) {
                this->PROCESS_END_GAME();
                return 0; // END_GAME
            } else {
                this->PROCESS_DRAW_BLOCK();
            }

            while(true){
                util::delay(cc::delayTime);           

                if(this->PROCESS_KB_OPERATE() == 1 )
                    return 0; // END_GAME

                this->PROCESS_CHECK_BTC_COUNT();

                if(this->PROCESS_CHECK_BTC_TRIGGER()) {
                    break;
                }   
            }
        }
    }

    int Tetris::PROCESS_RNG(){
        return rand() % 7;
    }

    void Tetris::PROCESS_RESET_BTC(){
        this->BottomTouchCounter = 0;
    }
    void Tetris::PROCESS_RESET_BLOCK(){
        this->block->reset(this->PROCESS_RNG(), this->generatePoint);
    }

    bool Tetris::PROCESS_CHECK_GENERATE(){
        if(this->block->isTouchPins(*(this->mainBoard))){
            util::gotoxy(this->mainBoard->getRect().getRightBottom()+ canva::Point(2, 0));
            std::printf("GAME OVER");
            return false;  
        }
        else return true;
    }

    void Tetris::PROCESS_CHECK_BTC_COUNT(){
        if(this->block->isDownEnable(*(this->mainBoard))){
            this->BottomTouchCounter = 0;
        } else {
            this->BottomTouchCounter++;
        }
    }

    bool Tetris::PROCESS_CHECK_BTC_TRIGGER(){
        if(this->BottomTouchCounter >= 3){
                this->block->draw(false);
                this->mainBoard->setObjectPins(*(this->block));
                this->mainBoard->lineCheckAndRearrange();
                
                util::SetColor(4);
                this->mainBoard->drawPins();
                return true;
        }
        else return false;
    }

    void Tetris::PROCESS_DRAW_BOUNDARY(){
        util::SetColor(10);
        this->mainBoard->getRect().drawOuterBoundary();
    }

    void Tetris::PROCESS_DRAW_BLOCK(){
        util::SetColor(7);
        this->block->draw(true);
    }   

    int Tetris::PROCESS_KB_OPERATE(){
        if(kbhit()){

            this->command->getInput();
            
            if(this->command->getKeyType() == this->command->ESC){
                this->PROCESS_END_GAME();
                return 1;
            } else if(this->command->getKeyType() == this->command->UpArrow){
                this->block->draw(false);
                this->block->turn(this->block->CLOCKWISE, *(this->mainBoard));
                this->block->draw(true);                
            } else if(this->command->getKeyType() == this->command->DownArrow){
                this->block->draw(false);
                this->block->move(canva::Point(0,1), *(this->mainBoard));
                this->block->draw(true);                
            } else if(this->command->getKeyType() == this->command->LeftArrow){
                this->block->draw(false);
                this->block->move(canva::Point(-1,0), *(this->mainBoard));
                this->block->draw(true);                
            } else if(this->command->getKeyType() == this->command->RightArrow){
                this->block->draw(false);
                this->block->move(canva::Point(1,0), *(this->mainBoard));
                this->block->draw(true);                
            } else if(this->command->getKeyType() == this->command->Space){
                this->block->draw(false);
                while(this->block->move(canva::Point(0,1), *(this->mainBoard)));
                BottomTouchCounter = 3;
                this->block->draw(true);
            }

        } else {
            this->block->draw(false);
            this->block->move(canva::Point(0,1), *(this->mainBoard));
            this->block->draw(true);
        }

        this->command->reset();
        return 0;
    }

    void Tetris::PROCESS_END_GAME(){
        util::gotoxy(this->mainBoard->getRect().getRightBottom()+canva::Point(2, 0));
        std::printf("GAME OVER");

        util::gotoxy(0,22);
        system("PAUSE");
    }
} // simple_game_tetris