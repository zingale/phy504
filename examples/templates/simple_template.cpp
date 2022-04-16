#include <iostream>

template <typename T>
T add(const T& x, const T& y) {
    return x + y;
}

int main() {

    double x{1}, y{2};

    auto z = add<double>(x, y);
    std::cout << z << std::endl;

    int a{-2}, b{4};

    std::cout << add<int>(a, b) << std::endl;

    std::cout << add(x, z) << std::endl;
}