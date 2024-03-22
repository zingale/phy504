#include <cassert>
#include <iostream>

#include "vector3d.H"

int main() {

    Vector3d v1(1, 2, 3);
    Vector3d v2(2, 4, 6);

    // these numbers are well-behaved so we don't have roundoff
    // issues in our asserts, but we should really check for
    // equality to some tolerance.

    std::cout << "testing unary minus vs. multiplication by -1" << std::endl;

    assert(-v1 == v1 * -1);

    std::cout << "testing v1 * v2 = " << v1 * v2 << std::endl;

    assert(v1 * v2 == 28);

    std::cout << "testing multiplication by a scalar" << std::endl;

    assert(v1 * 2 == v2);
    assert(2 * v1 == v2);

    std::cout << "testing division by a scalar" << std::endl;

    assert(v2 / 2 == v1);

}
