#include <iostream>
#include "vector2d.H"

int main() {

    // create 2 vectors

    Vector2d v1(1, 2);
 
    std::cout << "v1 == " << v1 << std::endl;

    // test left multiplication

    double a{2.0};

    auto v_new = a * v1;

    std::cout << "a * v1 = " << v_new << std::endl;

    // test scalar division

    auto v_new2 = v1 / a;

    std::cout << "v1 / a = " << v_new2 << std::endl;

    // test right multiplication

    auto v_new3 = v1 * a;

    std::cout << "v1 * a = " << v_new3 << std::endl;

    // test abs

    std::cout << "|v1| = " << v1.abs() << std::endl;

    // test dot

    auto v2 = Vector2d(2, 5);

    std::cout << "v1 . v2 = " << v1.dot(v2) << std::endl;


}