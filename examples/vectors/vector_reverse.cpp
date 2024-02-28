#include <iostream>
#include <vector>

int main() {

    std::vector<double> v{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};

    for (auto it = v.rbegin(); it < v.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}
