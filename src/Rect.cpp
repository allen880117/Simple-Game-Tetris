#include "Rect.h"
#include "Point.h"
#include "Util.h"
#include "cstdio"

namespace canva{
    // Constructor
    Rect::Rect(const Point &lt, const Point &rb){     
        this->LeftTop = lt;
        this->RightBottom = rb;
    }

    // Does Rect contain this Point or Object
    bool Rect::contains(const Point &pt) const{
        if( pt.X >= this->LeftTop.X && pt.X <= this->RightBottom.X &&
            pt.Y >= this->LeftTop.Y && pt.Y <= this->RightBottom.Y ) 
            return true;
        else
        {
            return false;
        }    
    }

    bool Rect::contains(const Object &obj) const{
        if( this->contains(obj.locate + obj.blocks[0]) ||
            this->contains(obj.locate + obj.blocks[1]) ||
            this->contains(obj.locate + obj.blocks[2]) ||
            this->contains(obj.locate + obj.blocks[3]) )
            return true;
        else
        {
            return false;
        }
    }

    // Draw Boundary (innner)
    void Rect::drawBoundary(){
        
        int width = this->RightBottom.X - this->LeftTop.X +1;
        int height = this->RightBottom.Y - this->LeftTop.Y +1;

        // Top Bound
        util::gotoxy(this->LeftTop);
        for(int i=0; i<width; i++){
            if( i == 0 ) printf("+");
            else if( i == width - 1) printf("+");
            else printf("-");
        }

        // Between
        for(int i=1; i<height-1; i++){
            printf("\n");
            for(int i=0; i<width; i++){
                if( i == 0 ) printf("|");
                else if( i == width - 1) printf("|");
                else printf(" ");
            }
        }

        // Bottom Bound
        printf("\n");
        for(int i=0; i<width; i++){
            if( i == 0 ) printf("+");
            else if( i == width - 1) printf("+");
            else printf("-");
        }

        // Avolid the twinkle of cursor
        util::gotoxy(0, 0);
    }

} // namespace canva

