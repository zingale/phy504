#include <iostream>
#include <iomanip>

#include <cmath>

int main() {

    float x{201010.0f};
    
    std::cout << std::setprecision(10);

    float r1 = std::sqrt(x + 1.0f) - std::sqrt(x);

    float r2 = 1.0f / (std::sqrt(x + 1.0f) + std::sqrt(x));

    std::cout << "r1 = " << r1 << " r2 = " << r2 << std::endl;
 
    double xd{201010.0};

    double d = std::sqrt(xd + 1.0) - std::sqrt(xd);

    std::cout << "d = " << d << std::endl;
}