#ifndef BOARD_H
#define BOARD_H
#include "Rect.h"
#include "Object.h"

namespace canva{

    class Board{

      public:
        // Constructor
        Board(const Point &lt, const Point &rb);
        
        // Destructor
        ~Board();

        // Draw pins
        void drawPins();

        // Set pins of Object
        void setObjectPins(const Object &obj);

        // Get rect
        Rect getRect();

      private:
        Rect* rect;
        int* pin;
        int height;
        int width;
    };
} // namespace canva

#endif
