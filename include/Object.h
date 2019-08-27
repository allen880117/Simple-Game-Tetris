#ifndef OBJECT_H
#define OBJECT_H

#include "Point.h"

namespace canva{

    // Pre-declaration of Class, Rect and Object
    // Completely declare in "Rect.h" 
    class Rect;
    
    // Declaration of Class, Object
    class Object{
        
        public:
            // Consturctor
            Object(const int type, const Point &loc=Point(0, 0));
            
            // switch Type
            void switchType(const int type);

            // Move offset
            bool move(const Point &offset, const Rect &boundary);
            
            // Reset
            void reset(const int type, const Point &loc=Point(0, 0));

            // Is inside rect
            bool isInside(const Rect &rect) const;

            // Draw
            void draw(bool show=true) const;
            
        private:
            // Left Top locate
            Point locate;
            Point blocks[4];
            int type;
            int dir;
    
        friend Rect;
    };
} // namespace canva
#endif