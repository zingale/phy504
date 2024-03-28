#include <vector>
#include <iostream>

#include "ode_integrator.H"

constexpr int N{4};

enum orbit_comps {
    ix,
    iy,
    iu,
    iv};

constexpr double GM{4.0 * M_PI * M_PI};   // G * Mass in AU, year, solar mass unit

std::vector<double> orbit([[maybe_unused]] double t,
                          const std::vector<double>& y) {

    // order is x, y, u, v

    std::vector<double> dydt(N, 0.0);

    dydt[ix] = y[iu];
    dydt[iy] = y[iv];

    // du/dt = - GMx/r**3; dv/dt = - GMy/r**3

    double r = std::sqrt(y[ix] * y[ix] + y[iy] * y[iy]);

    dydt[iu] = - GM * y[ix] / std::pow(r, 3);
    dydt[iv] = - GM * y[iy] / std::pow(r, 3);

    return dydt;

}

int main() {

    double a{1.0};
    double e{0.8};

    ODE o(orbit, {a * (1.0 - e), 0.0,
                  0.0, std::sqrt(GM / a * (1.0 + e) / (1.0 - e))});

    double tol{1.e-4};
    auto trajectory = o.integrate(0.025, 1.0, tol);

    std::cout << "# number of RHS evaluations = " << o.n_rhs << std::endl;
    std::cout << "# dt range = [" << o.dt_min << ", " << o.dt_max << "]" << std::endl;

    for (const auto& s : trajectory) {
        std::cout << s << std::endl;
    }
}
