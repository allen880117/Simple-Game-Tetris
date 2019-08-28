#include "Board.h"
#include "Object.h"
#include "Rect.h"
#include "Point.h"
#include "Util.h"
#include "cstdio"
#include "ConstCharacter.h"

namespace canva{

    // Consturctor
    Board::Board(const Point &lt, const Point &rb) {
        
        this->rect = new Rect(lt, rb);
        this->pin = new int[this->getWidth()*this->getHeight()];

        // Initial
        for(int i=0; i<this->getWidth()*this->getHeight(); i++) 
            this->pin[i] = 0;
    }

    // Destructor    
    Board::~Board(){
        delete [] pin;
        delete rect;
    }

    // Draw pins
    void Board::drawPins(){

        // Traverse all pins
        for(int i=0; i<this->getHeight(); i++){
            util::gotoxy(this->rect->LeftTop + Point(0, i));
            for(int j=0; j<this->getWidth(); j++){
                if(pin[i*this->getWidth() + j] == 1) printf("%s", cc::cPin);
                else printf("%s", cc::cEmpty);
            }
        }
    }

    // Is the pin be touched by object
    bool Board::isPinsTouched(const Object &obj) const{
        
        for(int i=0; i<4; i++){
            Point offsetFromLT = ( obj.locate + obj.blocks[i] ) - this->rect->LeftTop;
            int idx = offsetFromLT.Y * this->getWidth() + offsetFromLT.X;
            
            if(this->pin[idx] == 1) // Obj touch the pin
                return false;
        }

        return true; // Obj doesn't touch the pins
    }

    // Set pins of Object
    void Board::setObjectPins(const Object &obj){
        for(int i=0; i<4; i++){
            Point offsetFromLT = ( obj.locate + obj.blocks[i] ) - this->rect->LeftTop;
            int idx = offsetFromLT.Y * this->getWidth() + offsetFromLT.X;
            this->pin[idx] = 1;
        }
    }

    // Get rect
    Rect Board::getRect() const{
        return *(this->rect);
    }

    // Get Height
    int Board::getHeight() const{
        return this->rect->height;
    }
    
    // Get Width
    int Board::getWidth() const{
        return this->rect->width;
    }

} // namespace canva