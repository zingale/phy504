#include <iostream>
#include <iomanip>

#include <mpi.h>

// compute pi by integrating f(x) = 4 / (1 + x^2) from [0, 1]

double f(double x) {
    return 4.0 / (1.0 + x * x);
}

int main() {

    MPI_Init(nullptr, nullptr);

    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // ask how many intervals

    int N{0};

    if (rank == 0) {
        std::cout << "how many intervals? ";
        std::cin >> N;
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    double dx = 1.0 / static_cast<double>(N);

    // each processor simply does a midpoint rule, using only each num_procs
    // number in [0, 1]

    double sum = 0.0;
    for (int i = rank; i < N; i += num_procs) {
        if (rank == 2) {
            std::cout << "i = " << i << std::endl;
        }
        double x = (static_cast<double>(i) + 0.5) * dx;
        sum += f(x);
    }

    sum *= dx;

    // now reduce the sum across all processors, only processor 0 will get the result

    double sum_global{0};
    MPI_Reduce(&sum, &sum_global, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        std::cout << std::setprecision(15) << "pi = " << sum_global << std::endl;
    }

    MPI_Finalize();
}
