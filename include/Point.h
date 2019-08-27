#ifndef POINT_H
#define POINT_H

namespace canva{

    // Pre-declaration of Class, Rect and Object
    // Completely declare in "Rect.h"
    // Completely declare in "Object.h"
    class Rect;
    class Object;

    // Declaration of Class, Point
    class Point{
    
        public:
            // Constructor
            Point();
            Point(const int x, const int y);

            // Calculate the summation of 
            Point operator+(const Point &rhs) const;

            // Is Point inside the Rect
            bool isInside(const Rect &rect) const;

            // Get/Set
            int getX() const;
            int getY() const;
            void setX(const int x);
            void setY(const int y);

        private:
            int X;
            int Y;

        friend Rect;
        friend Object;
    };

} // namespace canva

#endif