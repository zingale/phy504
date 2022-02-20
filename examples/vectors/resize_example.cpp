#include <iostream>
#include <vector>

int main() {

    std::vector<double> container{0.0, 1.0, 2.0};

    std::cout << "current contents: ";

    for (auto e : container) {
        std::cout << e << " ";
    }

    std::cout << std::endl;

    container.resize(10, 0.0);

    std::cout << "new contents: ";

    for (auto e : container) {
        std::cout << e << " ";
    }

    std::cout << std::endl;

    container.clear();

    std::cout << "after clear: ";

    for (auto e : container) {
        std::cout << e << " ";
    }

    std::cout << std::endl;

}