#include "poisson2d.H"

const double TOL = 1.e-10;

int main() {

    auto p = Poisson(0.0, 1.0, 0.0, 1.0, 512, 512);

    p.set_source([] (double x, double y)
                 {return -2.0 * ((1.0 - 6.0 * x * x) * y * y * (1.0 - y * y) +
                                 (1.0 - 6.0 * y * y) * x * x * (1.0 - x * x));});

    p.set_xlo_bc(0.0);
    p.set_xhi_bc(0.0);
    p.set_ylo_bc(0.0);
    p.set_yhi_bc(0.0);

    p.solve(TOL);

    p.write_solution("poisson.txt");
}
