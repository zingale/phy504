#include <iostream>

#include "container.H"

int main() {

    Container a(10);

    for (int i = 0; i < a.get_size(); ++i) {
        a.get_data()[i] = static_cast<double>(i);
    }

    std::cout << a << std::endl;

    auto b = a;

    std::cout << "resetting b to 0" << std::endl;

    for (int i = 0; i < b.get_size(); ++i) {
        b.get_data()[i] = 0.0;
    }

    std::cout << "contents of b" << std::endl;

    std::cout << b << std::endl;

    std::cout << "contents of a" << std::endl;

    std::cout << a << std::endl;

}
