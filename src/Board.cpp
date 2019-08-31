#include <cstdio>
#include "Point.h"
#include "Object.h"
#include "Rect.h"
#include "Board.h"
#include "Util.h"
#include "ConstParam.h"

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
                return true;
        }

        return false; // Obj doesn't touch the pins
    }

    // Set pins of Object
    void Board::setObjectPins(const Object &obj){
        for(int i=0; i<4; i++){
            Point offsetFromLT = ( obj.locate + obj.blocks[i] ) - this->rect->LeftTop;
            int idx = offsetFromLT.Y * this->getWidth() + offsetFromLT.X;
            this->pin[idx] = 1;
        }
    }

    // Check whether pins form lines, if exists, rearrange them
    void Board::lineCheckAndRearrange(){
        
        // Declare some temp counters
        bool* isFull = new bool[this->rect->height];
        int* downCounter = new int[this->rect->height];
        for(int i=0; i<this->getHeight(); i++){
            isFull[i] = true;
            downCounter[i] = 0;
        }

        // Check
        for(int i=0; i<this->getHeight(); i++){
            
            // Check is line full
            for(int j=0; j<this->getWidth(); j++){
                if(this->pin[i*this->getWidth() + j] == 0){
                    isFull[i] = false;
                    break;                    
                }
            }

            // if line is full
            if(isFull[i]){
                // The lines that above this line need go down one more block 
                for(int j=i-1; j>=0; j--){
                    downCounter[j]++;
                }
            }

        }

        // Rearrange
        int* tempPins = new int[this->getWidth()*this->getHeight()];
        for(int i=0; i<this->getWidth()*this->getHeight(); i++) 
            tempPins[i] = 0;
        
        for(int i=0; i<this->getHeight(); i++){
            if(!isFull[i]){
                for(int j=0; j<this->getWidth(); j++){
                    int idx = (i+downCounter[i]) * this->getWidth() + j;
                    tempPins[idx] = this->pin[i*this->getWidth() + j];
                }       
            }
        }
        
        // Change Pointer
        delete [] this->pin;
        this->pin = tempPins;

        // Free temp counters
        delete [] isFull;
        delete [] downCounter;
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