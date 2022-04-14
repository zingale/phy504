#include <iostream>
#include <string>

int main() {

    std::string a{"test"};

    std::string steal(std::move(a));

    std::cout << "steal = " << steal << " a = " << a << std::endl;
}