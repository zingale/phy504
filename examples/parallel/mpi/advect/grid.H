#ifndef GRID_H
#define GRID_H

#include <cassert>
#include <cmath>
#include <format>
#include <iostream>

#include "array.H"

class grid {

public:

    int nx;
    int ny;
    int ng;

    double xmin;
    double xmax;
    double ymin;
    double ymax;

    double dx;
    double dy;

    // for the domain decomposition, we will set the indices of
    // the valid cells in the domain on the current processor

    int ilo{-1};
    int ihi{-1};
    int jlo{-1};
    int jhi{-1};

    grid(int _nx, int _ny, int _ng,
         double _xmin, double _xmax, double _ymin, double _ymax)
        : nx(_nx), ny(_ny), ng(_ng),
          xmin(_xmin), xmax(_xmax), ymin(_ymin), ymax(_ymax)
    {
        assert (xmax > xmin);
        assert (ymax > ymin);
        assert (nx > 0);
        assert (ny > 0);

        dx = (xmax - xmin) / static_cast<double>(nx);
        dy = (ymax - ymin) / static_cast<double>(ny);
    }

    ///
    /// compute the domain decomposition and set the 
    /// bounding indices for the grid on processor rank
    ///
    inline void set_decomposition(int rank, int nprocs) {

        // each processor will hold a slab with the i coordinates
        // spanning the entire x-domain, and the j coordinates
        // spanning their own respective subset.  We will refer to a
        // global index space of nx x ny.

        // note: with this decomposition, the data will be
        // contiguous in memory on each processor

        int jwidth = std::floor(static_cast<double>(ny) /
                                static_cast<double>(nprocs));

        int jextra = ny % nprocs;

        // the first iwidth processors have a width of iwidth+1
        int mywidth = jwidth;
        if (rank < jextra) {
            mywidth++;
        }

        // current processor's index space

        ilo = 0;
        ihi = nx-1;

        if (rank < jextra) {
            jlo = (jwidth+1)*rank;
            jhi = jlo + mywidth - 1;
        } else {
            jlo = (jwidth+1)*jextra + jwidth*(rank - jextra);
            jhi = jlo + mywidth - 1;
        }

    }

    ///
    /// get a scratch array indexed on this rank's subdomain
    /// with a perimeter of ghost cells
    ///
    inline Array scratch_array() {
        Array arr(ilo-ng, ihi+ng, jlo-ng, jhi+ng);
        return arr;
    }

};


inline std::ostream& operator<< (std::ostream& os, grid g) {
    os << std::format("i: ({:3}, {:3}); j: ({:3}, {:3})",
                      g.ilo, g.ihi, g.jlo, g.jhi);
    return os;
}

#endif
