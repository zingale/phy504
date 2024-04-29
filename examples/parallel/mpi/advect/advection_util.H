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

        if (n != 0) {

            // we need to copy the data over to rank 0

            if (rank == n) {

                // transfer the index range

                int jrange[2] = {g.jlo, g.jhi};
                MPI_Send(jrange, 2, MPI_INT, 0, n, MPI_COMM_WORLD);

                // now transfer the data -- note that we are contiguous
                // in the j range, but we have ghost cells.  We'll

                // copy the ghostcells over in the i-direction so we
                // don't need to create a temporary buffer to store
                // the data

                int icount = g.ihi - g.ilo + 1 + 2 * g.ng;
                int jcount = g.jhi - g.jlo + 1;

               MPI_Send(&a(0, g.jlo), icount * jcount, MPI_DOUBLE,
                        0, n, MPI_COMM_WORLD);

            } else if (rank == 0) {

                // receive the index range from rank n

                MPI_Status status;

                int jrange[2] = {0, 0};
                MPI_Recv(jrange, 2, MPI_INT, n, n, MPI_COMM_WORLD, &status);

                std::cout << "recieving data from rank " << n << std::endl;
                std::cout << jrange[0] << ", " << jrange[1] << std::endl;

                // create a buffer to hold the data we will receive

                Array a_buf(g.ilo-g.ng, g.ihi+g.ng, jrange[0], jrange[1]);

                int icount = g.ihi - g.ilo + 1 + 2 * g.ng;
                int jcount = jrange[1] - jrange[0] + 1;

                MPI_Recv(&a_buf(0, jrange[0]), icount * jcount, MPI_DOUBLE,
                         n, n, MPI_COMM_WORLD, &status);

                std::cout << "outputing the data" << std::endl;

                // output the buffer to the file
                for (int j = jrange[0]; j <= jrange[1]; ++j) {
                    for (int i = g.ilo; i <= g.ihi; ++i) {
                        ofile << a_buf(i, j) << std::endl;
                    }
                    ofile << std::endl;
                }
            }

        } else {

            // write out rank 0's data.  No communication needed

            for (int j = g.jlo; j <= g.jhi; ++j) {
                for (int i = g.ilo; i <= g.ihi; ++i) {
                    ofile << a(i, j) << std::endl;
                }
                ofile << std::endl;
            }

        }

    }

}

#endif


