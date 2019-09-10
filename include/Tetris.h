#ifndef TETRIS_H
#define TETRIS_H
#include "Board.h"
#include "Point.h"
#include "Rect.h"
#include "Command.h"

namespace simple_game_tetris{

    class Tetris {
        public:
            Tetris();
            ~Tetris();
            int  PROCESS_ALL();
            int  PROCESS_RNG();
            void PROCESS_RESET_BTC();
            void PROCESS_RESET_BLOCK();
            bool PROCESS_CHECK_GENERATE();
            void PROCESS_CHECK_BTC_COUNT();
            bool PROCESS_CHECK_BTC_TRIGGER();
            void PROCESS_DRAW_BOUNDARY();
            void PROCESS_DRAW_BLOCK();
            int  PROCESS_KB_OPERATE();
            void PROCESS_END_GAME();

        private:
            canva::Board *mainBoard;
            canva::Point generatePoint;
            canva::Object *block;
            util::Command *command;
            int BottomTouchCounter;
    };
} // namesapce simple_game tetris

#endif