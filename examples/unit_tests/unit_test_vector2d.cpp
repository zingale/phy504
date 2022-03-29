#include "vector2d.H"
#include <cassert>

int main() {

    auto v1 = Vector2d(2, 4);
    auto v2 = Vector2d(-1, 7);

    // test addition

    assert(v1 + v2 == Vector2d(1, 11));

    // test subtraction

    assert(v1 - v2 == Vector2d(3, -3));

    // test unary minus

    assert(-v1 == Vector2d(-2, -4));

    // test not equal

    assert(v1 != v2);

}