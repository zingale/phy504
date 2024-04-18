#ifndef ODE_INTEGRATOR_H
#define ODE_INTEGRATOR_H

#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <ranges>
#include <vector>

// A 4th-order Runge-Kutta integrator to solve:
//
//   dy/dt = f
//   y(t=0) = y0
//
// where y is a vector of length N.
// This is templated on the size of the system, N.
//
// The signature of the righthand side function, f, is:
//
// std::vector<double> f(double t, const std::array<double>& y)
//

namespace adaptive_rk4 {
    constexpr double S1{0.9};
    constexpr double S2{4.0};
}

using rhs_func =
    std::function<std::vector<double>(double,
                                      const std::vector<double>&)>;

using rhs_param_func =
    std::function<std::vector<double>(double,
                                      const std::vector<double>&,
                                      std::vector<double>&)>;

struct solution {
    double t;
    std::vector<double> y{};

    // constructor that takes an vector of values

    solution(double t_in, std::vector<double>& y_in)
        : t(t_in), y(y_in) {}

};

std::ostream& operator<<(std::ostream& os, const solution& s) {
    os << std::setprecision(4);
    os << std::setw(10) << s.t << " ";
    for (auto e : s.y) {
        os << std::setw(10) << e << " ";
    }
    return os;
}

class ODE {

public:

    int neqs{-1};

    int n_rhs{0};
    int n_reset{0};
    double dt_min{std::numeric_limits<double>::max()};
    double dt_max{std::numeric_limits<double>::lowest()};

private:

    double t{0.0};

    std::vector<double> y_init;
    std::vector<double> params;
    rhs_func rhs;
    rhs_param_func rhs_param;

    std::vector<solution> history{};

    // do an update of the form y_new = y + dt * dydt

    std::vector<double> update_step(const std::vector<double>& y0, double dt,
                                    std::vector<double>& dydt) {

        std::vector<double> y_new{y0};
        for (auto [y, ydot] : std::views::zip(y_new, dydt)) {
            y += dt * ydot;
        }

        return y_new;
    }

    // do a single step of RK4 given initial y0 and timestep dt

    std::vector<double> rk4_step(const std::vector<double>& y0, double t0, double dt) {

        // get the k1 acceleration
        auto k1 = params.empty() ? rhs(t0, y0) : rhs_param(t0, y0, params);
        n_rhs++;

        assert(static_cast<int>(k1.size()) == neqs);

        // get the k2 acceleration
        auto y_tmp = update_step(y0, 0.5*dt, k1);
        auto k2 = params.empty() ? rhs(t0 + 0.5*dt, y_tmp) : rhs_param(t0 + 0.5*dt, y_tmp, params);
        n_rhs++;

        // get the k3 acceleration
        y_tmp = update_step(y0, 0.5*dt, k2);
        auto k3 = params.empty() ? rhs(t0 + 0.5*dt, y_tmp) : rhs_param(t0 + 0.5*dt, y_tmp, params);
        n_rhs++;

        // get the k4 acceleration
        y_tmp = update_step(y0, dt, k3);
        auto k4 = params.empty() ? rhs(t0 + dt, y_tmp) : rhs_param(t0 + dt, y_tmp, params);
        n_rhs++;

        // compute the final update
        for (auto n = 0ul; n < y0.size(); ++n) {
            y_tmp[n] = y0[n] + (dt / 6.0) * (k1[n] + 2.0 * k2[n] + 2.0 * k3[n] + k4[n]);
        }

        return y_tmp;
    }


public:

    // constructor that takes an vector with initial conditions

    ODE(rhs_func rhs_in, std::vector<double> _y0)
        : neqs(_y0.size()), y_init(_y0), rhs(rhs_in)
    {
        history.emplace_back(t, y_init);
    }

    // constructor that takes an vector with initial conditions
    // and another with params that are passed to the RHS function

    ODE(rhs_param_func rhs_in, std::vector<double> _y0, std::vector<double> _p)
        : neqs(_y0.size()), y_init(_y0), params(_p), rhs_param(rhs_in)
    {
        history.emplace_back(t, y_init);
    }

    // integrate the system to tmax.  Here, dt_in is the initial
    // timestep.  The timestep will be adjusted internally to get a
    // relative tolerace or rtol.

    std::vector<solution>& integrate(double dt_in, double tmax, double rtol=1.e-6) {

        // start with the suggested timestep
        double dt_new{dt_in};
        double dt{dt_in};

        while (t < tmax) {

            const auto & sol_old = history.back();

            // adaptive timestepping loop -- keep trying to take a
            // step until we achieve our desired error
            double rel_error{std::numeric_limits<double>::max()};
            int n_try{};

            std::vector<double> y_new{};

            while (rel_error > rtol) {

                dt = dt_new;
                if (t + dt > tmax) {
                    dt = tmax - t;
                }

                // take 2 half steps

                auto y_tmp = rk4_step(sol_old.y, t, 0.5*dt);
                y_new = rk4_step(y_tmp, t + 0.5*dt, 0.5*dt);

                // now take a single step to cover dt
                auto y_single = rk4_step(sol_old.y, t, dt);

                // y_new should be more accurate, so we'll keep that if
                // the error is low

                rel_error = 0.0;
                for (const auto [yd, ys] : std::views::zip(y_new, y_single)) {
                    rel_error = std::max(rel_error, std::abs((yd - ys) / yd));
                }

                // adaptive timestep algorithm
                double dt_est = adaptive_rk4::S1 * dt * std::pow(std::abs(rtol / rel_error), 0.2);
                dt_new = std::clamp(dt_est, dt / adaptive_rk4::S2, adaptive_rk4::S2 * dt);

                n_try++;
            }

            if (n_try > 1) {
                // there were resets
                n_reset += (n_try - 1);
            }

            dt_min = std::min(dt_min, dt);
            dt_max = std::max(dt_max, dt);

            t += dt;
            history.emplace_back(t, y_new);

        }
        return history;
    }

};

#endif
