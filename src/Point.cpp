#include "Point.h"
#include "Rect.h"

namespace canva{

    // Constructor
    Point::Point(){
        this->X = 0;
        this->Y = 0;
    }

    Point::Point(const int x, const int y){
        this->X = x;
        this->Y = y;
    }

    // Calculate the summation of 
    Point Point::operator+(const Point &rhs) const{
        return Point(this->X + rhs.X, this->Y + rhs.Y);
    }

    // Is Point inside the Rect
    bool Point::isInside(const Rect &rect) const{
        return rect.Rect::contains(*this);
    }

    // Get/Set
    int Point::getX() const{
        return this->X;
    }

    int Point::getY() const{
        return this->Y;
    }

    void Point::setX(const int x) {
        this->X = x;
    }

    void Point::setY(const int y) {
        this->Y = y;
    }

} // namespace canva
