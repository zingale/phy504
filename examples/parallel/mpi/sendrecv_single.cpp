#include <iostream>
#include <vector>

#include <mpi.h>

int main() {

    MPI_Init(nullptr, nullptr);

    std::vector<int> data(5, 0);

    int mype{-1};
    MPI_Comm_rank(MPI_COMM_WORLD, &mype);

    int num_procs{0};
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    // fill the interior 3 data elements

    data[1] = 3 * mype;
    data[2] = 3 * mype + 1;
    data[3] = 3 * mype + 2;

    // send to the left and receive from the right
    //
    // send:    mype -> mype - 1
    // receive: mype <- mype + 1

    int sendto{-1};
    int recvfrom{-1};

    if (mype == 0) {
        sendto = MPI_PROC_NULL;
    } else {
        sendto = mype-1;
    }

    if (mype == num_procs-1) {
        recvfrom = MPI_PROC_NULL;
    } else {
        recvfrom = mype+1;
    }

    MPI_Status status;

    MPI_Sendrecv(&data[1], 1, MPI_INT, sendto, 0,
                 &data[4], 1, MPI_INT, recvfrom, 0,
                 MPI_COMM_WORLD, &status);


    // send to the right and receive from the left
    //
    // send:    mype -> mype+1
    // receive: mype <- mype-1

    if (mype == num_procs-1) {
        sendto = MPI_PROC_NULL;
    } else {
        sendto = mype+1;
    }

    if (mype == 0) {
        recvfrom = MPI_PROC_NULL;
    } else {
        recvfrom = mype-1;
    }

    MPI_Sendrecv(&data[3], 1, MPI_INT, sendto, 1,
                 &data[0], 1, MPI_INT, recvfrom, 1,
                 MPI_COMM_WORLD, &status);

    std::cout << "PE: " << mype << " data: ";
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    MPI_Finalize();
}
