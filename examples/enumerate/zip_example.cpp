#include <iostream>
#include <vector>
#include <string>
#include <ranges>

int main() {

    std::vector<std::string> names{"A", "B", "C", "D", "E"};
    std::vector<int> values{1, 2, 3, 4, 5, 6};

    for (auto [v, n] : std::views::zip(names, values)) {
        std::cout << v << " : " << n << std::endl;
    }

}
