#include <iostream>
#include <cmath>

int main() {

    double P = 0.0;
    double r = 0.0;
    double n = 0.0;
    double t = 0.0;

    std::cout << "Enter the principal (P): ";
    std::cin >> P;
    std::cout << std::endl;

    if (P <= 0.0) {
        std::cout << "invalid value" << std::endl;
        return -1;
    }

    std::cout << "Enter the annual interest rate (r) [percent/year]: ";
    std::cin >> r;
    std::cout << std::endl;

    if (r <= 0.0) {
        std::cout << "invalid value" << std::endl;
        return -1;
    }

    std::cout << "Enter the number of compounding periods per year (n) [1/year]: ";
    std::cin >> n;
    std::cout << std::endl;

    if (n <= 0.0) {
        std::cout << "invalid value" << std::endl;
        return -1;
    }

    std::cout << "Enter the duration of the investment [year]: ";
    std::cin >> t;
    std::cout << std::endl;

    if (t <= 0.0) {
        std::cout << "invalid value" << std::endl;
        return -1;
    }

    // we need to change the interest rate from a percentage to a fraction:
    r = r / 100.0;

    double A = P * std::pow(1.0 + r / n, n * t);

    std::cout << "new amount = " << A << std::endl;
    std::cout << "income = " << A - P << std::endl;

}
