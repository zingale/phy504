#include <iostream>
#include <vector>

int main() {
    std::vector<double> container;

    container.push_back(10.0);
    container.push_back(-1.0);
    container.push_back(15.3);
    container.push_back(3.14159);

    std::cout << container[3] << std::endl;
}