#include <cstdio>
#include "Point.h"
#include "Object.h"
#include "Rect.h"
#include "Board.h"
#include "Util.h"
#include "ConstParam.h"

namespace canva{

    // Consturctor
    Object::Object(const int type, const Point &loc){
        this->type = type;
        this->direction = 0;
        this->locate = loc;
        this->switchTypeDirection(this->type, this->direction);
    }

    // switch Type and Direction
    void Object::switchTypeDirection(const int type, const int direction){
        //Offset from locate
        switch(type){
            case 0: // I
                switch(direction){
                    case 0: this->setBlocks(Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1)); break;
                    case 1: this->setBlocks(Point(2, 0), Point(2, 1), Point(2, 2), Point(2, 3)); break;
                    case 2: this->setBlocks(Point(0, 2), Point(1, 2), Point(2, 2), Point(3, 2)); break;
                    case 3: this->setBlocks(Point(1, 0), Point(1, 1), Point(1, 2), Point(1, 3)); break;
                    default: this->setBlocks(Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1)); break;
                } break;
            case 1: // J
                switch(direction){
                    case 0: this->setBlocks(Point(0, 0), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                    case 1: this->setBlocks(Point(1, 0), Point(2, 0), Point(1, 1), Point(1, 2)); break;
                    case 2: this->setBlocks(Point(2, 2), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                    case 3: this->setBlocks(Point(1, 0), Point(1, 1), Point(1, 2), Point(0, 2)); break;
                    default: this->setBlocks(Point(0, 0), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                } break;
            case 2: // L
                switch(direction){
                    case 0: this->setBlocks(Point(2, 0), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                    case 1: this->setBlocks(Point(1, 0), Point(1, 1), Point(1, 2), Point(2, 2)); break;
                    case 2: this->setBlocks(Point(0, 2), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                    case 3: this->setBlocks(Point(1, 0), Point(1, 1), Point(1, 2), Point(0, 0)); break;
                    default: this->setBlocks(Point(2, 0), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                } break;
            case 3: // O
                switch(direction){
                    case 0 ... 3:
                        this->setBlocks(Point(1, 0), Point(2, 0), Point(1, 1), Point(2, 1)); break;
                    default: this->setBlocks(Point(1, 0), Point(2, 0), Point(1, 1), Point(2, 1)); break;
                } break;
            case 4: // S
                switch(direction){
                    case 0: this->setBlocks(Point(1, 0), Point(2, 0), Point(0, 1), Point(1, 1)); break;
                    case 1: this->setBlocks(Point(1, 0), Point(1, 1), Point(2, 1), Point(2, 2)); break;
                    case 2: this->setBlocks(Point(1, 1), Point(2, 1), Point(0, 2), Point(1, 2)); break;
                    case 3: this->setBlocks(Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 2)); break;
                    default: this->setBlocks(Point(1, 0), Point(2, 0), Point(0, 1), Point(1, 1)); break;
                } break;
            case 5: // T
                switch(direction){
                    case 0: this->setBlocks(Point(1, 0), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                    case 1: this->setBlocks(Point(1, 0), Point(1, 1), Point(2, 1), Point(1, 2)); break;
                    case 2: this->setBlocks(Point(1, 2), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                    case 3: this->setBlocks(Point(0, 1), Point(1, 0), Point(1, 1), Point(1, 2)); break;
                    default: this->setBlocks(Point(1, 0), Point(0, 1), Point(1, 1), Point(2, 1)); break;
                } break;
            case 6: // Z
                switch(direction){
                    case 0: this->setBlocks(Point(0, 0), Point(1, 0), Point(1, 1), Point(2, 1)); break;
                    case 1: this->setBlocks(Point(2, 0), Point(2, 1), Point(1, 1), Point(1, 2)); break;
                    case 2: this->setBlocks(Point(0, 1), Point(1, 1), Point(1, 2), Point(2, 2)); break;
                    case 3: this->setBlocks(Point(1, 0), Point(1, 1), Point(0, 1), Point(0, 2)); break;
                    default: this->setBlocks(Point(0, 0), Point(1, 0), Point(1, 1), Point(2, 1)); break;
                } break;
            default: // O
                switch(direction){
                    case 0 ... 3:
                        this->setBlocks(Point(1, 0), Point(2, 0), Point(1, 1), Point(2, 1)); break;
                    default: this->setBlocks(Point(1, 0), Point(2, 0), Point(1, 1), Point(2, 1)); break;
                } break;
        }
    }

    // Move offset
    bool Object::move(const Point &offset, const Board &board){
        
        // Move First
        this->locate = this->locate + offset;
        
        // Check is moved object inside boundary
        // Check does moved object touch the pins on board
        bool isLegal = this->isInsideRect(board.Board::getRect())
                    && this->isTouchPins(board);

        if(!isLegal) { // Not a legal move
            // Recovery
            this->locate = this->locate - offset;
            return false;
            
        } else { // a legal move
            return true;
        }
    }

    // Turn
    bool Object::turn(const DirClock &dirclock, const Board &board){
        switch (dirclock){
            case CLOCKWISE:  this->direction = (this->direction >=3) ? 0 : this->direction+1; break;
            case COUNTERCLOCKWISE: this->direction = (this->direction <=0) ? 3 : this->direction-1; break;
            default: this->direction = (this->direction >=3) ? 0 : this->direction+1; break;
        }

        // Switch Block Direction
        this->switchTypeDirection(this->type, this->direction);
        
        // Check is turned object inside boundary
        // Check does turned object touch the pins on board
        bool isLegal = this->isInsideRect(board.Board::getRect())
                    && this->isTouchPins(board);

        if(!isLegal) { // Not a legal turn 

            // Recovery Direction
            switch (dirclock){ 
                case CLOCKWISE:  this->direction = (this->direction <=0) ? 3 : this->direction-1; break;
                case COUNTERCLOCKWISE: this->direction = (this->direction >=3) ? 0 : this->direction+1; break;
                default: this->direction = (this->direction <=0) ? 3 : this->direction-1; break;
            }

            // Recovery Type and Direction
            this->switchTypeDirection(this->type, this->direction);

            return false;

        } else { // a legal turn
            return true;
        }
    }
    
    // Reset
    void Object::reset(const int type, const Point &loc){
        this->type = type;
        this->direction = 0;
        this->locate = loc;
        this->switchTypeDirection(this->type, this->direction);
    }

    // Is inside rect
    bool Object::isInsideRect(const Rect &rect) const{
        return rect.Rect::contains(*this);
    }

    // Is touch board pin
    bool Object::isTouchPins(const Board &board) const{
        return board.Board::isPinsTouched(*this);
    }

    // Draw
    void Object::draw(const bool show) const{
        
        for(int i=0; i<4; i++){
            util::gotoxy(this->locate + this->blocks[i]);
            if(show) printf("%s", cc::cBlocks); // Show Obj
            else printf("%s", cc::cEmpty); // Clear Obj
        }
        
        // Avoid the twinkle of cursor
        util::gotoxy(0, 0); 
    }
    
    // Set Blocks (Private)
    void Object::setBlocks( const Point &pt0, const Point &pt1, const Point &pt2, const Point &pt3 ){
        this->blocks[0] = pt0;
        this->blocks[1] = pt1;
        this->blocks[2] = pt2;
        this->blocks[3] = pt3;
    }

} // namespace canva