// compute the volume of a D-dimensional hypersphere
// via mean-value Monte-Carlo integration

#include <iostream>
#include <random>
#include <cmath>
#include <numbers>

constexpr int D = 10;
constexpr int N = 1000000;

double integrand(std::vector<double> r) {

    double d = std::sqrt(std::inner_product(r.cbegin(), r.cend(), r.cbegin(), 0.0));

    if (d <= 1.0) {
        return 1.0;
    }

    return 0.0;

}

double analytic() {

    return std::pow(std::numbers::pi, D/2.0) / std::tgamma(D/2.0 + 1.0);

}

int main() {

    //std::default_random_engine generator();
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    std::vector<double> r(D, 0.0);

    double v{0.0};

    for (int n = 0; n < N; ++n) {

        // get D random numbers between -1 and 1

        for (auto &e : r) {
            e = distribution(generator);
        }

        v += integrand(r);

    }
    v *= std::pow(2.0, D);

    std::cout << "volume = " << v / N << " " << analytic() << std::endl;

}
