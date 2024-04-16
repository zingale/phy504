// compute the volume of a D-dimensional hypersphere
// via mean-value Monte-Carlo integration

#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <numbers>

constexpr int N_MAX{1000000};

double integrand(std::vector<double> r) {

    double d = std::sqrt(std::inner_product(r.cbegin(), r.cend(), r.cbegin(), 0.0));

    if (d <= 1.0) {
        return 1.0;
    }

    return 0.0;
}

double analytic(const double D) {
    return std::pow(std::numbers::pi, D/2.0) / std::tgamma(D/2.0 + 1.0);
}

int main() {

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    double D{-1};
    std::cout << "Enter dimensionality of the hypersphere: ";
    std::cin >> D;

    // we'll hold D random numbers, representing {r_0, r_1, ..., r_{D-1}}

    std::vector<double> r(D, 0.0);

    int N = 10;
    while (N <= N_MAX) {

        double V{0.0};

        for (int n = 0; n < N; ++n) {

            // get D random numbers between -1 and 1

            for (auto &e : r) {
                e = distribution(generator);
            }

            V += integrand(r);
        }

        V *= std::pow(2.0, D);

        std::cout << "samples: " << std::setw(7) << N << ";  "
                  << "volume: " << V / N << std::endl;

        N *= 10;

    }

    std::cout << "analytic result: " << analytic(D) << std::endl;
}
