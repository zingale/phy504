#ifndef GRID_H
#define GRID_H

#include <cassert>
#include <cmath>
#include <format>
#include <iostream>

#include "array.H"

class Grid {

public:

    double dx;
    double dy;

    // for the domain decomposition, we will set the indices of
    // the valid cells in the domain on the current processor

    int ng;

    int ilo{-1};
    int ihi{-1};
    int jlo{-1};
    int jhi{-1};

    Grid(int _nx, int _ny, int _ng,
         double _xmin, double _xmax, double _ymin, double _ymax,
         int _rank, int _nprocs)
        : ng(_ng)
    {
        assert (_xmax > _xmin);
        assert (_ymax > _ymin);
        assert (_nx > 0);
        assert (_ny > 0);

        dx = (_xmax - _xmin) / static_cast<double>(_nx);
        dy = (_ymax - _ymin) / static_cast<double>(_ny);

        // compute the domain decomposition and set the bounding
        // indices for the grid on processor rank

        // each processor will hold a slab with the i coordinates
        // spanning ~ 1/nx of the x-domain, and the j coordinates
        // spanning the entire j range.  We will refer to a
        // global index space of nx x ny.

        // note: with this decomposition, the data will be
        // contiguous in memory on each processor

        int iwidth = std::floor(static_cast<double>(_nx) /
                                static_cast<double>(_nprocs));

        int iextra = _nx % _nprocs;

        // the first iwidth processors have a width of iwidth+1

        int mywidth = iwidth;
        if (_rank < iextra) {
            mywidth++;
        }

        // current processor's index space

        if (_rank < iextra) {
            ilo = (iwidth + 1) * _rank;
            ihi = ilo + mywidth - 1;
        } else {
            ilo = (iwidth + 1) * iextra + iwidth * (_rank - iextra);
            ihi = ilo + mywidth - 1;
        }

        jlo = 0;
        jhi = _ny-1;

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


inline std::ostream& operator<< (std::ostream& os, Grid g) {
    os << std::format("i: ({:3}, {:3}); j: ({:3}, {:3})",
                      g.ilo, g.ihi, g.jlo, g.jhi);
    return os;
}

#endif
