#include <iostream>

#include "vector2d.H"

int main() {

    // vectors displancing N, E, S, W

    Vector2d v_north(0.0, 1.0);
    Vector2d v_east(1.0, 0.0);
    Vector2d v_south(0.0, -1.0);
    Vector2d v_west(-1.0, 0.0);

    // test compound addition -- if we sum up the four vectors above,
    // we should get zero

    Vector2d v1;
    v1 += v_north;
    v1 += v_east;

    std::cout << "compound addition (intermediate result): " << v1 << std::endl;
    v1 += v_south;
    v1 += v_west;

    std::cout << "compound addition (final result): " << v1 << std::endl;

    // test compound subtraction

    Vector2d v2(1.0, 1.0);
    v2 -= v_north;

    std::cout << "compound subtraction: " << v2 << std::endl;

    // test compound multiplication

    Vector2d v3(2.0, 4.0);
    v3 *= 4;

    std::cout << "compound multiplication: " << v3 << std::endl;

    // test compound division

    Vector2d v4(1.0, -5.0);
    v4 /= 2;

    std::cout << "compound division: " << v4 << std::endl;


}