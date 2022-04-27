#include <iostream>
#include <random>

int main() {

    std::seed_seq seed{1, 2, 3, 4, 5};
    std::mt19937 generator(seed);
    std::uniform_real_distribution<double> uniform(0.0, 1.0);

    for (int n = 0; n < 10; ++n) {
        std::cout << uniform(generator) << std::endl;
    }

}
