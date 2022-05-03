#include <iostream>
#include <iomanip>

#include <random>
#include <cmath>

#include <omp.h>

const int N = 1000000;

int main() {

    auto start = omp_get_wtime();

    int N_circle{0};

    #pragma omp parallel reduction(+:N_circle)
    {

        std::random_device rd;
        std::seed_seq seed{static_cast<int>(rd()), omp_get_thread_num()};
        std::mt19937 generator(seed);
        std::uniform_real_distribution<double> uniform(0.0, 1.0);

        #pragma omp for
        for (int n = 0; n < N; ++n) {

            double x = uniform(generator);
            double y = uniform(generator);

            double r2 = std::pow(x - 0.5, 2) + std::pow(y - 0.5, 2);

            if (r2 <= 0.25) {
                N_circle++;
            }

        }
        
    }

    std::cout << "pi = " << std::setprecision(10) << 4 * static_cast<double>(N_circle) / N << std::endl;

    std::cout << "time = " << omp_get_wtime() - start << std::endl;
}