#include <iostream>

#include "shapes.H"

int main() {

    Quadrilateral q(1.0, 2.0, 1.0, 2.0);

    std::cout << "perimeter of q = " << q.perimeter() << std::endl;

    Rectangle r(2.0, 4.0);

    std::cout << "perimenter of r = " << r.perimeter() << std::endl;
    std::cout << "area of r = " << r.area() << std::endl;
}