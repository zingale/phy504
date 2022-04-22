#include <iostream>
#include <random>
#include <cmath>
const int N = 1000000;

int main() {

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> uniform(0.0, 1.0);

    int N_circle{0};

    for (int n = 0; n < N; ++n) {

        double x = uniform(generator);
        double y = uniform(generator);

        double r = std::sqrt(std::pow(x - 0.5, 2) + std::pow(y - 0.5, 2));

        if (r <= 0.5) {
            N_circle++;
        }

    }

    std::cout << "pi = " << 4 * static_cast<double>(N_circle) / N << std::endl;
}