#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>

#include "orbit.H"

OrbitState rhs(const OrbitState& state) {

    OrbitState dodt{};

    // dt/dt = 1

    dodt.t = 1;

    // dx/dt = vx; dy/dt = vy

    dodt.x = state.vx;
    dodt.y = state.vy;

    // d(vx)/dt = - GMx/r**3; d(vy)/dt = - GMy/r**3

    double r = std::sqrt(state.x * state.x + state.y * state.y);

    dodt.vx = - GM * state.x / std::pow(r, 3);
    dodt.vy = - GM * state.y / std::pow(r, 3);

    return dodt;

}

void write_history(const std::vector<OrbitState>& history) {

    for (const auto& o : history) {
        std::cout << std::setw(14) << o.t
                  << std::setw(14) << o.x
                  << std::setw(14) << o.y
                  << std::setw(14) << o.vx
                  << std::setw(14) << o.vy << std::endl;

    }

}

std::vector<OrbitState>
integrate(const double a, const double tmax, const double dt_in) {

    // how the history of the orbit

    // set initial conditions
    OrbitState state{};

    // assume circular orbit on the x-axis, counter-clockwise orbit

    state.t = 0.0;
    state.x = a;
    state.y = 0.0;
    state.vx = 0.0;
    state.vy = std::sqrt(GM / a);

    std::vector<OrbitState> orbit_history;

    orbit_history.push_back(state);

    double dt = dt_in;

    // integration loop
    while (state.t < tmax) {

        if (state.t + dt > tmax) {
            dt = tmax - state.t;
        }

        // get the derivatives
        auto state_derivs = rhs(state);

	// get the derivatives at the midpoint in time
	auto state_star = state + 0.5 * dt * state_derivs;
	state_derivs = rhs(state_star);

        // update the state
	state = state + dt * state_derivs;

        orbit_history.push_back(state);
    }

    return orbit_history;
}
