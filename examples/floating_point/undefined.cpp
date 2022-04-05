#include <iostream>
#include <cmath>

double trouble(double x) {
    return std::sqrt(x);
}

int main() {

    double x{-1};

    double y = trouble(x);
 
    for (int i = 0; i < 10; ++i) {
        y += std::pow(x, i);
    }

    std::cout << y << std::endl;

}
