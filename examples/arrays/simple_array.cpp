#include <iostream>
#include <array>

int main() {

    std::array<int, 10> int_arr;

    for (auto e : int_arr) {
        std::cout << e << std::endl;
    }
}