#ifndef RECT_H
#define RECT_H
#include "Point.h"
#include "Object.h"

namespace canva{
    
    // Pre-declaration of Class, Board
    // Completely declare in "Board.h"
    class Board;

    // Declaration of Class, Rect
    class Rect {

        public:
            // Constructor
            Rect(const Point &lt, const Point &rb);

            // Does Rect contain this Point or Object
            bool contains(const Point &pt) const;
            bool contains(const Object &obj) const;

            // Draw Boundary (inner)
            void drawInnerBoundary();

            // Draw Boundary (outer)
            void drawOuterBoundary();

            // Get LeftTop or RightBottom
            Point getLeftTop() const;
            Point getRightBottom() const;

            // Get height or width
            int getHeight() const;
            int getWidth() const;

        private:
            Point LeftTop;
            Point RightBottom;
            int height;
            int width;

        friend Board;
    };

} // namespace canva

#endif