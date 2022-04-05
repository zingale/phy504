#include <iostream>

int main() {

    double h{0.01};
    double sum{0.0};

    for (int n = 0; n < 100; ++n) {
        sum += h;
    }

    std::cout << "sum == 1:        " << (sum == 1.0) << std::endl;
    std::cout << "|sum - 1| < tol: " << (std::abs(sum - 1.0) < 1.e-10) << std::endl;

}