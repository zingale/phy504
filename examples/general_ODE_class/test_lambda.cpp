#include <vector>
#include <iostream>

#include "ode_integrator.H"

// solve dy/dt = -y with y(0) = 1

int main() {

    auto f = [] (double t, const std::vector<double>& y) -> std::vector<double>
             {return {-y[0]};};

    ODE o(f, {1.0});

    double tol{1.e-8};
    auto trajectory = o.integrate(0.025, 1.0, tol);

    std::cout << "# number of RHS evaluations = " << o.n_rhs << std::endl;
    std::cout << "# number of rejected steps = " << o.n_reset << std::endl;
    std::cout << "# dt range = [" << o.dt_min << ", " << o.dt_max << "]" << std::endl;

    for (const auto& s : trajectory) {
        std::cout << s << std::endl;
    }
}
