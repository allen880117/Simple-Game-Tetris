#include <cstdio>
#include "Point.h"
#include "Object.h"
#include "Rect.h"
#include "Util.h"
#include "ConstParam.h"

namespace canva{
    // Constructor
    Rect::Rect(const Point &lt, const Point &rb){     
        this->LeftTop = lt;
        this->RightBottom = rb;
        this->width = Point(rb-lt).X + 1;
        this->height = Point(rb-lt).Y + 1;
    }

    // Does Rect contain this Point or Object (Fully Inside)
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
        if( this->contains(obj.locate + obj.blocks[0]) &&
            this->contains(obj.locate + obj.blocks[1]) &&
            this->contains(obj.locate + obj.blocks[2]) &&
            this->contains(obj.locate + obj.blocks[3]) )
            return true;
        else
        {
            return false;
        }
    }

    // Draw Boundary (innner)
    void Rect::drawInnerBoundary(){

        // Top Bound
        util::gotoxy(this->LeftTop);
        for(int i=0; i<width; i++){
            if( i == 0 || i == width - 1) printf("%s", cc::cConner);
            else printf("%s", cc::cDash);
        }

        // Between
        for(int i=1; i<height-1; i++){
            printf("\n");
            for(int i=0; i<width; i++){
                if( i == 0 || i == width - 1) printf("%s", cc::cSideEdge);
                else printf("%s", cc::cEmpty);
            }
        }

        // Bottom Bound
        printf("\n");
        for(int i=0; i<width; i++){
            if( i == 0 || i == width - 1) printf("%s", cc::cConner);
            else printf("%s", cc::cDash);
        }

        // Avolid the twinkle of cursor
        util::gotoxy(0, 0);
    }


    // Draw Boundary (outer)
    void Rect::drawOuterBoundary(){

        // Top Bound
        util::gotoxy( this->LeftTop + Point(-1,-1) );
        for(int i=0; i<width+2; i++){
            if( i == 0 || i == width+2 - 1) printf("%s", cc::cConner);
            else printf("%s", cc::cDash);
        }

        // Between
        for(int i=1; i<height+2-1; i++){
            printf("\n");
            for(int i=0; i<width+2; i++){
                if( i == 0 || i == width+2 - 1) printf("%s", cc::cSideEdge);
                else printf("%s", cc::cEmpty);
            }
        }

        // Bottom Bound
        printf("\n");
        for(int i=0; i<width+2; i++){
            if( i == 0 || i == width+2 - 1) printf("%s", cc::cConner);
            else printf("%s", cc::cDash);
        }

        // Avolid the twinkle of cursor
        util::gotoxy(0, 0);
    
    }

    // Get LeftTop
    Point Rect::getLeftTop() const{
        return this->LeftTop;
    }
    
    // Get RightBottom
    Point Rect::getRightBottom() const{
        return this->RightBottom;
    }

    // Get Height
    int Rect::getHeight() const{
        return this->height;
    }

    // Get Width    
    int Rect::getWidth() const{
        return this->width;
    }

} // namespace canva

