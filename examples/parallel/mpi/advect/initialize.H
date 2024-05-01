#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <cmath>

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

#endif
