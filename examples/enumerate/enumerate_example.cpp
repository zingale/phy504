#include <iostream>
#include <vector>
#include <ranges>

int main() {

    std::vector<double> powers{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

    for (auto [index, value] : std::views::enumerate(powers)) {
        std::cout << index << " : " << value << std::endl;
    }
}
