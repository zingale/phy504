#include <iostream>
#include <vector>

int main() {

    std::vector<double> container(10, 0.0);

    for (auto e : container) {
        e = 1.0;
    }

    std::cout << "current vector: ";
    for (auto e : container) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    for (auto& e : container) {
        e = 2.0;
    }

    std::cout << "current vector: ";
    for (auto e : container) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    for (auto it = container.begin(); it < container.end(); ++it) {
        *it = 3.0;
    }

    std::cout << "current vector: ";
    for (auto e : container) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

}