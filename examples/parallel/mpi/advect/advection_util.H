#ifndef ADVECTION_UTIL
#define ADVECTION_UTIL

#include <cmath>
#include <fstream>

#include <mpi.h>

#include "array.H"
#include "grid.H"

///
/// initialize the solution with a Gaussian
///
inline void initialize(const grid& g, Array& a) {

    double xc = 0.5 * (g.xmin + g.xmax);
    double yc = 0.5 * (g.ymin + g.ymax);

    for (int i = g.ilo; i <= g.ihi; ++i) {
        double x = g.xmin + (static_cast<double>(i) + 0.5) * g.dx;

        for (int j = g.jlo; j <= g.jhi; ++j) {
            double y = g.ymin + (static_cast<double>(j) + 0.5) * g.dy;

            a(i, j) = 1.0 + std::exp(-60.0 * (std::pow(x - xc, 2) +
                                              std::pow(y - yc, 2)));
        }
    }
}

///
/// write out the data by copying everything to rank 0
/// 
inline void output(const grid& g, double t, const Array& a) {

    int rank{-1};
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int nprocs{-1};
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    // rank 0 will do all of the writing
    std::ofstream ofile;
    if (rank == 0) {
        ofile.open("advect_mpi.out");
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

                int icount = g.ihi - g.ilo + 1 + 2 * g.ng;
                int jcount = g.jhi - g.jlo + 1 + 2 * g.ng;

                std::cout << "sending size = " << a.nx() * a.ny() << std::endl;

                MPI_Send(a.data(), icount * jcount, MPI_DOUBLE,
                         0, n, MPI_COMM_WORLD);

            } else if (rank == 0) {

                // receive the index range from rank n

                MPI_Status status;

                int irange[2] = {0, 0};
                MPI_Recv(irange, 2, MPI_INT, n, n, MPI_COMM_WORLD, &status);

                std::cout << "recieving data from rank " << n << std::endl;
                std::cout << irange[0] << ", " << irange[1] << std::endl;

                // create a buffer to hold the data we will receive

                Array a_buf(irange[0]-g.ng, irange[1]+g.ng,
                            g.jlo-g.ng, g.jhi+g.ng);

                int icount = irange[1] - irange[0] + 1 + 2 * g.ng;
                int jcount = g.jhi - g.jlo + 1 + 2 * g.ng;

                std::cout << "buffer size = " << a_buf.nx() * a_buf.ny() << std::endl;

                auto ierr = MPI_Recv(a_buf.data(), icount * jcount, MPI_DOUBLE,
                                     n, n, MPI_COMM_WORLD, &status);

                if (ierr != MPI_SUCCESS) {
                    std::cout << "error in recv: " << ierr << std::endl;
                }

                std::cout << "outputing the data" << std::endl;

                // output the buffer to the file
                for (int i = irange[0]; i <= irange[1]; ++i) {
                    for (int j = g.jlo; j <= g.jhi; ++j) {
                        ofile << a_buf(i, j) << std::endl;
                    }
                    ofile << std::endl;
                }

                std::cout << "done" << std::endl;
            }

        }

    }

    // in testing, before any of the advection was implemented, I needed a barrier here
    // to make sure the execution doesn't end before the file is written.

    MPI_Barrier(MPI_COMM_WORLD);
}

#endif


