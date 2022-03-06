#include <iostream>
#include <vector>

int main() {

    std::vector<int> a{0, 4, 10, 3, 21, 100, 63, 7, 2, 1, 9, 20};

    for (auto &e : a) {
        if (e % 2 == 1) {
            continue;
        }
        e *= -1;
    }

    for (auto e : a) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
