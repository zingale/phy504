#include <iostream>
#include <random>

int main() {

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> uniform(0.0, 1.0);

    for (int n = 0; n < 10; ++n) {
        std::cout << uniform(generator) << std::endl;
    }

}