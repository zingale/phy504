#include <iostream>
#include <vector>

int main() {

    std::vector<double> a;
    a.resize(10);

    double b;   // uninitialized

    for (auto& v: a) {
        v = 10 * b;
    }

    for (auto v: a) {
        std::cout << v << std::endl;
    }

}
