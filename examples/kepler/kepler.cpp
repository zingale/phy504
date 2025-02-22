#include <iostream>
#include <cmath>
#include <string>

int main() {

    std::cout << "solve for P or a? ";

    std::string response{};

    std::cin >> response;

    bool solve_for_a{};

    if (response == "a" || response == "A") {
        solve_for_a = true;
    } else if (response == "p" || response == "P") {
        solve_for_a = false;
    } else {
        std::cout << "invalid value" << std::endl;
        return -1;
    }

    double a{};
    double P{};

    if (solve_for_a) {
        std::cout << "enter period (P): ";
        std::cin >> P;

        if (P < 0.0) {
            std::cout << "error: P must be positive" << std::endl;
            return -1;
        }

        a = std::pow(P, 2.0/3.0);
        std::cout << "semi-major axis, a = " << a << std::endl;

    } else {
        std::cout << "enter semi-major axis (a): ";
        std::cin >> a;

        if (a < 0.0) {
            std::cout << "error: a must be positive" << std::endl;
            return -1;
        }

        P = std::pow(a, 1.5);
        std::cout << "period, P = " << P << std::endl;

    }
}
