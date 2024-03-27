#include <array>
#include <iostream>

#include "ode_integrator.H"

constexpr int N{4};

enum orbit_comps {
    ix,
    iy,
    iu,
    iv};

constexpr double GM{4.0 * M_PI * M_PI};   // G * Mass in AU, year, solar mass unit

std::array<double, N> orbit([[maybe_unused]] double t,
                            const std::array<double, N>& y) {

    // order is x, y, u, v

    std::array<double, N> dydt{};

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
    double e{0.6};

    ODE<N> o(orbit, {a * (1.0 - e), 0.0,
                     0.0, std::sqrt(GM / a * (1.0 + e) / (1.0 - e))});

    auto trajectory = o.integrate(0.025, 1.0);

    for (auto s : trajectory) {
        std::cout << s << std::endl;
    }
}
