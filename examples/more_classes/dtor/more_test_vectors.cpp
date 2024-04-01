#include <iostream>

#include "vector2d.H"

int main() {

    Vector2d v1(1.0, 2.0);
    Vector2d v2, v3;

    // test assignment

    std::cout << "doing v3 = v2 = v1" << std::endl;

    v3 = v2 = v1;

    std::cout << v2 << " " << v3 << std::endl;

    // test copy

    std::cout << "doing auto v4 = v1" << std::endl;
    auto v4 = v1;

    std::cout << "doing auto v5(v1)" << std::endl;
    auto v5(v1);

    std::cout << "doing auto v6{v1}" << std::endl;
    auto v6{v1};

    std::cout << v4 << std::endl;

}
