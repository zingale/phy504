#include <iostream>

int main() {

    float x{1.000001e15};
    float y{1.0000e15};

    std::cout << "x^2 - y^2 :      " << x*x - y*y << std::endl;
    std::cout << "(x - y)(x + y) : " << (x - y) * (x + y) << std::endl;

    double m{1.000001e15};
    double n{1.0000e15};

    std::cout << "double precision value: " << (m - n) * (m + n) << std::endl;

}