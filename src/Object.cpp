#include "Object.h"
#include "Rect.h"
#include "util.h"
#include "cstdio"

namespace canva{

    // Consturctor
    Object::Object(const int type, const Point &loc){
        this->type = type;
        this->dir = 0;
        this->locate = loc;
        switchType(type);
    }

    // switchType
    void Object::switchType(const int type){
        //Offset from locate
        switch(type){
            case 0: // I
                this->blocks[0] = Point(0, 0);
                this->blocks[1] = Point(0, 1);
                this->blocks[2] = Point(0, 2);
                this->blocks[3] = Point(0, 3);
                break;
            case 1: // J
                this->blocks[0] = Point(0, 0);
                this->blocks[1] = Point(0, 1);
                this->blocks[2] = Point(1, 1);
                this->blocks[3] = Point(2, 1);
                break;
            case 2: // L
                this->blocks[0] = Point(2, 0);
                this->blocks[1] = Point(0, 1);
                this->blocks[2] = Point(1, 1);
                this->blocks[3] = Point(2, 1);
                break;
            case 3: // O
                this->blocks[0] = Point(0, 0);
                this->blocks[1] = Point(1, 0);
                this->blocks[2] = Point(0, 1);
                this->blocks[3] = Point(1, 1);
                break;
            case 4: // S
                this->blocks[0] = Point(1, 0);
                this->blocks[1] = Point(2, 0);
                this->blocks[2] = Point(0, 1);
                this->blocks[3] = Point(1, 1);
                break;
            case 5: // T
                this->blocks[0] = Point(1, 0);
                this->blocks[1] = Point(0, 1);
                this->blocks[2] = Point(1, 1);
                this->blocks[3] = Point(2, 1);
                break;
            case 6: // Z
                this->blocks[0] = Point(0, 0);
                this->blocks[1] = Point(1, 0);
                this->blocks[2] = Point(1, 1);
                this->blocks[3] = Point(2, 1);
                break;
            default: // I
                this->blocks[0] = Point(0, 0);
                this->blocks[1] = Point(0, 1);
                this->blocks[2] = Point(0, 2);
                this->blocks[3] = Point(0, 3);
                break;
        }
    }
    
    // Reset
    void Object::reset(const int type, const Point &loc){
        this->type = type;
        this->dir = 0;
        this->locate = loc;
        switchType(type);
    }

    // Move offset
    bool Object::move(const Point &offset, const Rect &boundary){
        for(int i=0; i<4; i++) this->blocks[i] = this->blocks[i] + offset;
        return true; // Dev
    }

    // Is inside rect
    bool Object::isInside(const Rect &rect) const{
        return rect.Rect::contains(*this);
    }

    // Draw
    void Object::draw(const bool show) const{
        
        for(int i=0; i<4; i++){
            util::gotoxy(this->locate + this->blocks[i]);
            if(show) printf("*"); // Show Obj
            else printf(" "); // Clear Obj
        }
        
        // Avoid the twinkle of cursor
        util::gotoxy(0, 0); 
    }
    
} // namespace canva