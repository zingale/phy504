#include <vector>
#include <iostream>

#include "ode_integrator.H"

enum lorenz_comps {
    ix,
    iy,
    iz};

enum param_comps {
    isigma,
    irho,
    ibeta};

std::vector<double> rhs([[maybe_unused]] double t,
                        const std::vector<double>& y,
                        std::vector<double>& params) {

    double dxdt = params[isigma] * (y[iy] - y[ix]);
    double dydt = params[irho] * y[ix] - y[iy] - y[ix] * y[iz];
    double dzdt = y[ix] * y[iy] - params[ibeta] * y[iz];

    return {dxdt, dydt, dzdt};

}

int main() {

    // these are the parameters that Lorenz used

    constexpr double sigma{10.0};
    constexpr double rho{28.0};
    constexpr double beta{8.0/3.0};

    ODE o(rhs, {-10.0, -10.0, -10.0},
          {sigma, rho, beta});

    double tol{1.e-4};
    auto trajectory = o.integrate(0.025, 50.0, tol);

    std::cout << "# number of RHS evaluations = " << o.n_rhs << std::endl;
    std::cout << "# number of rejected steps = " << o.n_reset << std::endl;
    std::cout << "# dt range = [" << o.dt_min << ", " << o.dt_max << "]" << std::endl;

    for (const auto& s : trajectory) {
        std::cout << s << std::endl;
    }
}
