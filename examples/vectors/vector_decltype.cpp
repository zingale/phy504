#include <iostream>
#include <vector>

int main() {

    char c{'a'};

    std::vector<decltype(c)> myvec(10, c);

    for (auto e : myvec) {
        std::cout << e;
    }
    std::cout << std::endl;
}