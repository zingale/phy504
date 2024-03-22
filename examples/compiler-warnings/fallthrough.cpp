#include <iostream>
#include <cmath>

int main() {

    double x{};
    std::string sign{};

    std::cout << "enter a number: ";
    std::cin >> x;

    const auto sgn = static_cast<int>(std::copysign(1.0, x));

    switch (sgn) {

    case -1:
        sign = "negative";
    case 0:
        sign = "none";
        break;
    default:
        sign = "positive";
    }

    std::cout << "sign = " << sign << std::endl;
}
