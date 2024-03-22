#include <iostream>
#include <iomanip>
#include <limits>
#include <numbers>

int main() {

    std::cout << std::setprecision(std::numeric_limits<float>::digits10+1)
              << std::numbers::e_v<float> << std::endl;
    std::cout << std::setprecision(std::numeric_limits<double>::digits10+1)
              << std::numbers::e_v<double> << std::endl;
    std::cout << std::setprecision(std::numeric_limits<long double>::digits10+1)
              << std::numbers::e_v<long double> << std::endl;

}
