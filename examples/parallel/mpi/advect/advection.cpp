#include <iostream>

#include <mpi.h>

#include "advection_util.H"
#include "grid.H"

namespace domain {
    constexpr int nx{512};
    constexpr int ny{512};
    constexpr int ng{1};

    constexpr double xmin{0.0};
    constexpr double xmax{1.0};
    constexpr double ymin{0.0};
    constexpr double ymax{1.0};
}

namespace simulation {
    constexpr double C{0.4};
    constexpr double tmax{1.0};
    constexpr double u{1.0};
    constexpr double v{1.0};
}

int main() {

     MPI_Init(nullptr, nullptr);

     int rank{-1};
     MPI_Comm_rank(MPI_COMM_WORLD, &rank);

     int nprocs{-1};
     MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

     // setup the grid

     grid g(domain::nx, domain::ny, domain::ng,
            domain::xmin, domain::xmax, domain::ymin, domain::ymax);

     g.set_decomposition(rank, nprocs);

     // create the memory for storing the old and new solution

     auto a = g.scratch_array();
     auto anew = g.scratch_array();

     // initialize
     initialize(g, a);

     // output
     double t{0.0};
     output(g, t, a);

     // evolve

     while (t < simulation::tmax) {

         // get dt

         double dt = simulation::C * std::min(g.dx / simulation::u,
                                              g.dy / simulation::v);
         if (t + dt > simulation::tmax) {
             dt = simulation::tmax - t;
         }

         // fill ghost cells

         // do the first-order unsplit update
         // note: this is unstable for C > 0.5 because the update
         // does not see the diagonal upwind cell


         t += dt;

         a = anew;

     }

}
