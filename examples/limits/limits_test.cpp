#include <iostream>
#include <limits>

int main() {

    std::cout << "double: " << std::endl;
    std::cout << "  smallest value = " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "  lowest value = " << std::numeric_limits<double>::lowest() << std::endl;
    std::cout << "  largest value = " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "short: " << std::endl;
    std::cout << "  smallest value = " << std::numeric_limits<unsigned short>::min() << std::endl;
    std::cout << "  lowest value = " << std::numeric_limits<unsigned short>::lowest() << std::endl;
    std::cout << "  largest value = " << std::numeric_limits<unsigned short>::max() << std::endl;

    int i = 32767;
    std::cout << "i = " << i << std::endl;
    i++;
    std::cout << "i = " << i << std::endl;


}
