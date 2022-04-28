#include <iostream>
#include <omp.h>
#include <vector>

const int N = 20000;

int main() {

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
}