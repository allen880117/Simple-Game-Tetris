#include "Board.h"
#include "Object.h"
#include "Rect.h"
#include "Point.h"
#include "Util.h"
#include "cstdio"

namespace canva{

    // Consturctor
    Board::Board(const Point &lt, const Point &rb) {
        
        this->rect = new Rect(lt, rb);
        this->width = Point(rb-lt).X + 1;
        this->height = Point(rb-lt).Y + 1;
        this->pin = new int[this->width*this->height];

        // Initial
        for(int i=0; i<this->width*this->height; i++) this->pin[i] = 0;

    }

    // Destructor    
    Board::~Board(){
        delete [] pin;
        delete rect;
    }

    // Draw pins
    void Board::drawPins(){
        // Traverse all pins
        for(int i=0; i<this->height; i++){
            util::gotoxy(this->rect->LeftTop + Point(0, i));
            for(int j=0; j<this->width; j++){
                if(pin[i*width + j] == 1) printf("O");
                else printf(" ");
            }
        }
    }

    // Set pins of Object
    void Board::setObjectPins(const Object &obj){
        for(int i=0; i<4; i++){
            Point offsetFromLT = ( obj.locate + obj.blocks[i] ) - this->rect->LeftTop;
            int idx = offsetFromLT.Y * this->width + offsetFromLT.X;
            this->pin[idx] = 1;
        }
    }

    // Get rect
    Rect Board::getRect(){
        return *(this->rect);
    }

} // namespace canva