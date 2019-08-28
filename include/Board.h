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

        // Is the pin be touched by object
        bool isPinsTouched(const Object &obj) const;

        // Set pins of Object
        void setObjectPins(const Object &obj);

        // Get rect
        Rect getRect() const;

        // Get height or width
        int getHeight() const;
        int getWidth() const;

      private:
        Rect* rect;
        int* pin;
    };
} // namespace canva

#endif
