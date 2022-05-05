#include <iostream>
#include <cmath>

template <int a>
double func(double x) {

    double y;

    if constexpr(a == 0) {
        y = 0.0;
    } else {
        y = x + x * x + std::pow(x, 3) + std::pow(x, 4);
    }

    return y;
}


int main() {

    std::cout << func<0>(2.0) << std::endl;
    std::cout << func<1>(2.0) << std::endl;
}
