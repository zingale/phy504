#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>

#include "orbit.H"

OrbitState rhs(const OrbitState& state) {

    OrbitState dodt{};

    // dx/dt = vx; dy/dt = vy

    dodt.x = state.vx;
    dodt.y = state.vy;

    // d(vx)/dt = - GMx/r**3; d(vy)/dt = - GMy/r**3

    double r = std::sqrt(state.x * state.x + state.y * state.y);

    dodt.vx = - GM * state.x / std::pow(r, 3);
    dodt.vy = - GM * state.y / std::pow(r, 3);

    return dodt;

}

void write_history(const std::vector<double> times,
                   const std::vector<OrbitState>& history) {

    assert(times.size() == history.size());

    for (int i = 0; i < static_cast<int>(times.size()); ++i) {
        std::cout << std::setw(14) << times[i]
                  << std::setw(14) << history[i].x
                  << std::setw(14) << history[i].y
                  << std::setw(14) << history[i].vx
                  << std::setw(14) << history[i].vy << std::endl;

    }

}

void integrate(const double a, const double tmax, const double dt_in,
               std::vector<double>& times, std::vector<OrbitState>& orbit_history) {

    // how the history of the orbit

    // set initial conditions
    OrbitState state{};

    // assume circular orbit on the x-axis, counter-clockwise orbit

    double t = 0.0;

    state.x = a;
    state.y = 0.0;
    state.vx = 0.0;
    state.vy = std::sqrt(GM / a);

    times.push_back(t);
    orbit_history.push_back(state);

    double dt = dt_in;

    // integration loop
    while (t < tmax) {

        if (t + dt > tmax) {
            dt = tmax - t;
        }

        // get the derivatives
        auto state_derivs = rhs(state);

	// get the derivatives at the midpoint in time
	auto state_star = state + 0.5 * dt * state_derivs;
	state_derivs = rhs(state_star);

        // update the state
	state = state + dt * state_derivs;
        t += dt;

        times.push_back(t);
        orbit_history.push_back(state);
    }

}
