#ifndef POINT_H
#define POINT_H

namespace canva{

    // Pre-declaration of Class, Object, Rect and Board
    // Completely declare in "Rect.h"
    // Completely declare in "Board.h"
    // Completely declare in "Object.h"
    class Object;
    class Rect;
    class Board;

    // Declaration of Class, Point
    class Point{
    
        public:
            // Constructor
            Point();
            Point(const int x, const int y);

            // Calculate the summation of two points
            Point operator+(const Point &rhs) const;

            // Calculate the subtraction of two points
            Point operator-(const Point &rhs) const;

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

        friend Object;        
        friend Rect;
        friend Board;
    };

} // namespace canva

#endif