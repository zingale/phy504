#include <iostream>
#include <limits>

int main() {

    std::cout << "double: " << std::endl;
    std::cout << "  smallest value = " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "  lowest value = " << std::numeric_limits<double>::lowest() << std::endl;
    std::cout << "  largest value = " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "short: " << std::endl;
    std::cout << "  smallest value = " << std::numeric_limits<short>::min() << std::endl;
    std::cout << "  lowest value = " << std::numeric_limits<short>::lowest() << std::endl;
    std::cout << "  largest value = " << std::numeric_limits<short>::max() << std::endl;

}
