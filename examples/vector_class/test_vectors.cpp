#include <iostream>
#include "vector2d.H"

int main() {

    Vector2d v1(1, 2);
    Vector2d v2(2, 4);

    std::cout << v1 << " " << v2 << std::endl;
    std::cout << v1 + v2 << std::endl;

    auto v3 = v1 - v2;
    std::cout << v3 << std::endl;

    auto v4 = v3;
    std::cout << v3 << " " << v4 << std::endl;
    v3.set_x(0.0);
    v3.set_y(0.0);
    std::cout << v3 << " " << v4 << std::endl;

    auto v5 = -v3;

}