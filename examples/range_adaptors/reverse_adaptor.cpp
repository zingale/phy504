#include <iostream>
#include <vector>
#include <ranges>

int main() {

    std::vector<double> v{1, 2, 3, 4, 5};

    for (auto e : v | std::views::reverse) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

}
