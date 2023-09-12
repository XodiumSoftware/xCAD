#include <iostream>
#include "rectangle.hpp"

int main()
{
    Rectangle myRectangle(5.0, 3.0);

    double area = myRectangle.getArea();
    double perimeter = myRectangle.getPerimeter();

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}
