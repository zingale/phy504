#include <iostream>
#include <random>

int main() {

    // a uniform random number generator that will be used as our seed
    std::random_device rd;

    // the Mersenne Twister -- we initialize it with a random seed
    std::mt19937 generator(rd());

    // our random number distribution
    std::uniform_real_distribution<double> uniform(0.0, 1.0);

    for (int n = 0; n < 10; ++n) {
        // sample our distribution with our generator
        std::cout << uniform(generator) << std::endl;
    }

}
