#include <iostream>

int main() {

    bool test{true};

    double x{0.0};

    x = 3.14;

    if (test) {
        double x = 1.0;
    }

    std::cout << "x = " << x << std::endl;
}