#include <iostream>
#include <vector>

int main() {

    std::vector<int> container{0, 1, 1, 2, 3, 5, 8, 13, 21};

    for (auto it = container.cbegin(); it < container.cend(); ++it) {
        std::cout << *it << std::endl;
    }

}