#include "rectangle.hpp"

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

double Rectangle::getArea()
{
    return length * width;
}

double Rectangle::getPerimeter()
{
    return 2 * (length + width);
}
