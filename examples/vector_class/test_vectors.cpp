#include <iostream>
#include "vector2d.H"

int main() {

    // create 2 vectors

    Vector2d v1(1, 2);
    Vector2d v2(2, 4);

    // output our vectors

    std::cout << v1 << " " << v2 << std::endl;

    // output their sum

    std::cout << v1 + v2 << std::endl;

    // create a new vector from subtracting our two vectors

    auto v3 = v1 - v2;
    std::cout << v3 << std::endl;

    // create a copy

    auto v4 = v3;
    std::cout << v3 << " " << v4 << std::endl;

    // change the data in the original
    v3.set_x(0.0);
    v3.set_y(0.0);

    // did both change? or just the original?

    std::cout << v3 << " " << v4 << std::endl;

}
