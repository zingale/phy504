#include <iostream>
#include <ranges>

int main() {

    for (auto i : std::views::iota(2, 7)) {
        std::cout << i << std::endl;
    }

}
