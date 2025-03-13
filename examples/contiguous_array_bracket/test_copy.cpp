#include <iostream>

#include "array.H"

int main() {

    Array a(10, 10);

    auto b = a;

    b[1, 1] = 10.0;

    std::cout << a << std::endl;

    std::cout << b << std::endl;
}
