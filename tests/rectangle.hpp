#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w);

    double getArea();
    double getPerimeter();
};

#endif // RECTANGLE_H
