#include <iostream>
#include <vector>

int main() {

    std::vector<int> int_vec{-1, 10, 2, 4, 6, 19, -100, 2, 4};

    std::cout << "initial vector: ";
    for (auto e : int_vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    auto it = int_vec.begin();

    int_vec.erase(it, it+4);

    std::cout << "updated vector: ";
    for (auto e : int_vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

}