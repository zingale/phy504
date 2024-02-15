#include <iostream>

int main() {

    int a{1};
    int b{2};

    auto c = a / b;
    auto d = static_cast<double>(a) / b;

    std::cout << c << " " << d << std::endl;

}
