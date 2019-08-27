#ifndef RECT_H
#define RECT_H
#include "Point.h"

namespace canva{

    // Declaration of Class, Rect
    class Rect {

        public:
            // Constructor
            Rect(const int left, const int top, const int right, const int bottom);
            Rect(const Point &LeftTop, const Point &RightBottom);

            // Does Rect contain this Point
            bool contains(const Point &pt) const;
            

        private:
            int Left;
            int Top;
            int Right;
            int Bottom;
    };

} // namespace canva

#endif