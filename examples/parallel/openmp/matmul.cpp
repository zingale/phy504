#include <iostream>
#include <omp.h>
#include <vector>

#include "array.H"

const int N = 10000;

int main() {


    Array a(N, N);
    std::vector<double> x(N);
    std::vector<double> b(N);

    #pragma omp parallel
    {

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a(i, j) = static_cast<double>(i + j);
            }
            x[i] = i;
            b[i] = 0.0;
        }

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                b[i] += a(i, j) * x[j];
            }
        }

    }
}
