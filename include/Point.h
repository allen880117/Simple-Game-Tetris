#ifndef POINT_H
#define POINT_H

namespace canva{

    // Pre-declaration of Class, Rect
    // Completely decalre in "Rect.h"
    class Rect;

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

        private:
            int X;
            int Y;

        friend class Rect;
    };

} // namespace canva

#endif