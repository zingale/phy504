#include <iostream>

#include "container.H"

int main() {

    Container a(10);

    for (int i = 0; i < a.get_size(); ++i) {
        a.get_data()[i] = static_cast<double>(i);
    }

    std::cout << a << std::endl;

    auto b = a;

    for (int i = 0; i < b.get_size(); ++i) {
        b.get_data()[i] = 0.0;
    }

    std::cout << b << std::endl;
    std::cout << a << std::endl;

}