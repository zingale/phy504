#include <iostream>
#include <iomanip>
#include <cmath>

#include <omp.h>

int main() {

    double sum{0.0};

    #pragma omp parallel reduction(+:sum)
    {
        #pragma omp for
        for (int i = 0; i < 10000; ++i) {
            sum += std::exp(static_cast<double>(i % 5) - 
                            2.0 * static_cast<double>(i % 7));
        }
    }
    std::cout << std::setprecision(15) << sum << std::endl;
}