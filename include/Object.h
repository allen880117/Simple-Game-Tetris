#ifndef OBJECT_H
#define OBJECT_H
#include "Point.h"

namespace canva{

    enum direction{
        CLOCKWISE,
        COUNTERCLOCKWISE,
    };

    // Pre-declaration of Class, Rect and Board
    // Completely declare in "Rect.h" 
    // Completely declare in "Board.h" 
    class Rect;
    class Board;
    
    // Declaration of Class, Object
    class Object{
        
        public:
            // Consturctor
            Object(const int type, const Point &loc=Point(0, 0));
            
            // switch Type
            void switchType(const int type);

            // switch Direction
            void switchDirection(const int dir);

            // Move offset
            bool move(const Point &offset, const Board &board);

            // Turn
            bool turn(const direction &dir);
            
            // Reset
            void reset(const int type, const Point &loc=Point(0, 0));

            // Is inside rect
            bool isInsideRect(const Rect &rect) const;

            // Is touch board pin
            bool isTouchPins(const Board &board) const;

            // Draw
            void draw(bool show=true) const;
            
        private:
            // Left Top locate
            Point locate;
            Point blocks[4];
            int type;
            int dir;
    
        friend Rect;
        friend Board;
    };
} // namespace canva
#endif