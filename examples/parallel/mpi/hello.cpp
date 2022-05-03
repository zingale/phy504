#include <iostream>
#include <mpi.h>

int main() {

    MPI_Init(nullptr, nullptr);

    // Get the number of processes

    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    // Get the rank of the process
    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    std::cout << "Hello from " << rank << " out of " << num_procs << std::endl;

    MPI_Finalize();
    
}