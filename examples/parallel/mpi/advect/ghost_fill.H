#ifndef GHOST_FILL_H
#define GHOST_FILL_H

#include <mpi.h>

#include "array.H"
#include "grid.H"
#include "simulation.H"

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
        MPI_Sendrecv(&a(g.ilo, g.jlo-g.ng), a.ny, MPI_DOUBLE, sendto, 0,
                     &a(g.ihi+1, g.jlo-g.ng), a.ny, MPI_DOUBLE, recvfrom, 0,
                     MPI_COMM_WORLD, &status);
    }

    {

        // send the last column of valid data to the right to fill the
        // right PE's left ghost cells, and receive from the left PE.
        // Wrap periodically.

        int sendto = rank == nprocs - 1 ? 0 : rank + 1;
        int recvfrom = rank == 0 ? nprocs - 1 : rank - 1;

        MPI_Status status;
        MPI_Sendrecv(&a(g.ihi, g.jlo-g.ng), a.ny, MPI_DOUBLE, sendto, 1,
                     &a(g.ilo-1, g.jlo-g.ng), a.ny, MPI_DOUBLE, recvfrom, 1,
                     MPI_COMM_WORLD, &status);
    }

}
#endif
