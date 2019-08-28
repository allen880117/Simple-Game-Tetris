#ifndef OBJECT_H
#define OBJECT_H
#include "Point.h"

namespace canva{

    enum DirClock{
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
            
            // switch Type and Direction
            void switchTypeDirection(const int type, const int direction = 0);

            // Move offset
            bool move(const Point &offset, const Board &board);

            // Turn
            bool turn(const DirClock &dirclock, const Board &board);
            
            // Reset
            void reset(const int type, const Point &loc=Point(0, 0));

            // Is inside rect
            bool isInsideRect(const Rect &rect) const;

            // Is touch board pin
            bool isTouchPins(const Board &board) const;

            // Draw
            void draw(bool show=true) const;
            
        private:
            // Set Blocks
            void setBlocks( const Point &pt0,
                            const Point &pt1,
                            const Point &pt2,
                            const Point &pt3 );
            // Left Top locate
            Point locate;
            Point blocks[4];
            int type;
            int direction;
    
        friend Rect;
        friend Board;
    };
} // namespace canva
#endif