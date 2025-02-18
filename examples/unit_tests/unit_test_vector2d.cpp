#include "vector2d.H"
#include <cassert>

int main() {

    auto v1 = Vector2d(2, 4);
    auto v2 = Vector2d(-1, 7);

    // test addition

    std::cout << "testing addition" << std::endl;

    assert(v1 + v2 == Vector2d(1, 11));

    // test subtraction

    std::cout << "testing subtraction" << std::endl;

    assert(v1 - v2 == Vector2d(3, -3));

    // test unary minus

    std::cout << "testing unary minus" << std::endl;

    assert(-v1 == Vector2d(-2, -4));

    // test not equal

    std::cout << "testing inequality" << std::endl;

    assert(v1 != v2);

    // test the setters and the default constructor

    v1.set_x(0.0);
    v1.set_y(0.0);

    std::cout << "testing setters" << std::endl;

    assert(v1 == Vector2d());

    std::cout << "all tests passed" << std::endl;
}
