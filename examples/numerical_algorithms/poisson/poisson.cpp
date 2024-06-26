#include <iostream>

#include "poisson.H"

const double TOL = 1.e-10;

int main() {

    auto p = Poisson(0.0, 1.0, 64);

    p.set_source([] (double x) {return std::sin(x);});

    p.set_left_bc(0.0);
    p.set_right_bc(1.0);

    p.solve(TOL);

    std::cout << "number of smoothing iterations: " << p.n_smooth() << std::endl;

    p.write_solution("poisson.txt");
}
