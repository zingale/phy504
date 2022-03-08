#include <iostream>

double sum(double x, double y);

double sum(double x, double y) {
    return x + y;
}

int main() {

    double m{3.2}, n{4.0};

    std::cout << sum(m, n) << std::endl;
    std::cout << sum(5.0, 5.0) << std::endl;
}
