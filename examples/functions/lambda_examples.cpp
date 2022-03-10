#include <iostream>

int main() {

    double x{10.0};

    auto f = [=] (double y) {return x + y;};

    std::cout << f(1) << " " << f(2) << " " << f(3) << std::endl;

    auto g = [&] () {x *= 2; return x;};

    std::cout << g() << " " << g() << " " << g() << std::endl;

    std::cout << "x = " << x << std::endl;
    
}