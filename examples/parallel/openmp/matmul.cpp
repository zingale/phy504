#include <iostream>
#include <omp.h>
#include <vector>

// be careful about memory (N**2)
// N = 10000 is 0.75 GB of memory

const int N = 10000;

int main() {

    auto start = omp_get_wtime();

    std::vector<std::vector<double>> a(N, std::vector<double>(N, 0));
    std::vector<double> x(N, 0);
    std::vector<double> b(N, 0);

    #pragma omp parallel
    {

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a[i][j] = static_cast<double>(i + j);
            }
            x[i] = static_cast<double>(i);
            b[i] = 0.0;
        }

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                b[i] += a[i][j] * x[j];
            }
        }

    }

    auto end = omp_get_wtime();

    std::cout << "execution time (s) = " << end - start << std::endl;
}