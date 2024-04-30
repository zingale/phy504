#ifndef ADVECTION_UTIL
#define ADVECTION_UTIL

#include <cmath>
#include <fstream>
#include <format>

#include <mpi.h>

#include "array.H"
#include "grid.H"
#include "simulation.H"

///
/// initialize the solution with a Gaussian
///
inline void initialize(const Grid& g, Array& a) {

    double xc = 0.5 * (domain::xmin + domain::xmax);
    double yc = 0.5 * (domain::ymin + domain::ymax);

    for (int i = g.ilo; i <= g.ihi; ++i) {
        double x = domain::xmin + (static_cast<double>(i) + 0.5) * g.dx;

        for (int j = g.jlo; j <= g.jhi; ++j) {
            double y = domain::ymin + (static_cast<double>(j) + 0.5) * g.dy;

            a(i, j) = 1.0 + std::exp(-60.0 * (std::pow(x - xc, 2) +
                                              std::pow(y - yc, 2)));
        }
    }
}

///
/// fill ghostcells, assuming doubly periodic
///
inline void fill_ghost_cells(const Grid& g, Array& a) {

    // we are doing a 1-d domain decomposition in the x-direction

    int rank{-1};
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int nprocs{-1};
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    // first do the periodic fill in the y-direction -- this is all
    // local

    for (int i = g.ilo-g.ng; i <= g.ihi+g.ng; ++i) {
        a(i, g.jlo-1) = a(i, g.jhi);
        a(i, g.jhi+1) = a(i, g.jlo);
    }

    // now fill the interior ghost cells

    {

        // send the first column of valid data to the left to fill the
        // left PE's right ghost cells, and receive from the right PE.
        // Wrap periodically.

        int sendto = rank == 0 ? nprocs - 1 : rank - 1;
        int recvfrom = rank == nprocs - 1 ? 0 : rank + 1;

        MPI_Status status;
        MPI_Sendrecv(&a(g.ilo, g.jlo-g.ng), a.ysize(), MPI_DOUBLE, sendto, 0,
                     &a(g.ihi+1, g.jlo-g.ng), a.ysize(), MPI_DOUBLE, recvfrom, 0,
                     MPI_COMM_WORLD, &status);
    }

    {

        // send the last column of valid data to the right to fill the
        // right PE's left ghost cells, and receive from the left PE.
        // Wrap periodically.

        int sendto = rank == nprocs - 1 ? 0 : rank + 1;
        int recvfrom = rank == 0 ? nprocs - 1 : rank - 1;

        MPI_Status status;
        MPI_Sendrecv(&a(g.ihi, g.jlo-g.ng), a.ysize(), MPI_DOUBLE, sendto, 1,
                     &a(g.ilo-1, g.jlo-g.ng), a.ysize(), MPI_DOUBLE, recvfrom, 1,
                     MPI_COMM_WORLD, &status);
    }

}


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

                MPI_Send(a.data(), a.xsize() * a.ysize(), MPI_DOUBLE,
                         0, n, MPI_COMM_WORLD);

            } else if (rank == 0) {

                // receive the index range from rank n

                MPI_Status status;

                int irange[2] = {0, 0};
                MPI_Recv(irange, 2, MPI_INT, n, n, MPI_COMM_WORLD, &status);

                // create a buffer to hold the data we will receive

                Array a_buf(irange[0]-g.ng, irange[1]+g.ng,
                            g.jlo-g.ng, g.jhi+g.ng);

                auto ierr = MPI_Recv(a_buf.data(), a_buf.xsize() * a_buf.ysize(), MPI_DOUBLE,
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
