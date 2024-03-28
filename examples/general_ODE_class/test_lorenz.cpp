#include <vector>
#include <iostream>

#include "ode_integrator.H"

constexpr int N{3};

enum lorenz_comps {
    ix,
    iy,
    iz};

namespace lorenz_params {
    constexpr double sigma{10.0};
    constexpr double rho{28.0};
    constexpr double beta{8.0/3.0};
}

std::vector<double> rhs([[maybe_unused]] double t,
                        const std::vector<double>& y) {

    std::vector<double> dydt(N, 0.0);

    dydt[ix] = lorenz_params::sigma * (y[iy] - y[ix]);
    dydt[iy] = lorenz_params::rho * y[ix] - y[iy] - y[ix] * y[iz];
    dydt[iz] = y[ix] * y[iy] - lorenz_params::beta * y[iz];

    return dydt;

}

int main() {

    ODE o(rhs, {-10.0, -10.0, -10.0});

    double tol{1.e-4};
    auto trajectory = o.integrate(0.025, 50.0, tol);

    std::cout << "# number of RHS evaluations = " << o.n_rhs << std::endl;
    std::cout << "# dt range = [" << o.dt_min << ", " << o.dt_max << "]" << std::endl;

    for (auto s : trajectory) {
        std::cout << s << std::endl;
    }
}
