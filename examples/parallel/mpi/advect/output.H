#ifndef OUTPUT_H
#define OUTPUT_H

#include <cmath>
#include <fstream>
#include <format>

#include <mpi.h>

#include "array.H"
#include "grid.H"
#include "simulation.H"


///
/// write out the data by copying everything to rank 0
///
inline void output(const Grid& g, double t, const Array& a) {

    int rank{-1};
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int nprocs{-1};
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    // rank 0 will do all of the writing
    std::ofstream ofile;

    if (rank == 0) {
        auto tstr = std::format("t{:5.3f}", t);
        ofile.open("advection_" + tstr + "_mpi.out");
    }

    for (int n = 0; n < nprocs; ++n) {

        if (n == 0) {

            // write out rank 0's data.  No communication needed

            for (int i = g.ilo; i <= g.ihi; ++i) {
                for (int j = g.jlo; j <= g.jhi; ++j) {
                    ofile << a(i, j) << std::endl;
                }
                ofile << std::endl;
            }

        } else {

            // we are working on a rank > 0, so we need to copy the
            // data over to rank 0

            if (rank == n) {

                // transfer the index range

                int irange[2] = {g.ilo, g.ihi};
                MPI_Send(irange, 2, MPI_INT, 0, n, MPI_COMM_WORLD);

                // now transfer the data -- we'll send everything,
                // including the ghost cells

                MPI_Send(a.data(), a.nx * a.ny, MPI_DOUBLE,
                         0, n, MPI_COMM_WORLD);

            } else if (rank == 0) {

                // receive the index range from rank n

                MPI_Status status;

                int irange[2] = {0, 0};
                MPI_Recv(irange, 2, MPI_INT, n, n, MPI_COMM_WORLD, &status);

                // create a buffer to hold the data we will receive

                Array a_buf(irange[0]-g.ng, irange[1]+g.ng,
                            g.jlo-g.ng, g.jhi+g.ng);

                auto ierr = MPI_Recv(a_buf.data(), a_buf.nx * a_buf.ny, MPI_DOUBLE,
                                     n, n, MPI_COMM_WORLD, &status);

                if (ierr != MPI_SUCCESS) {
                    std::cout << "error in recv: " << ierr << std::endl;
                }

                // output the buffer to the file
                for (int i = irange[0]; i <= irange[1]; ++i) {
                    for (int j = g.jlo; j <= g.jhi; ++j) {
                        ofile << a_buf(i, j) << std::endl;
                    }
                    ofile << std::endl;
                }

            }

        }

    }

}
#endif
