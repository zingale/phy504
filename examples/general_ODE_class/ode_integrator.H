#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
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
// std::array<double, N> f(double t, const std::array<double, N>& y)
//

template <int N>
using rhs_func = std::function<std::array<double, N>(double, const std::array<double, N>&)>;

template<int N>
struct solution {
    double t;
    std::array<double, N> y{};

    // constructor that takes an array of values

    solution(double t_in, std::array<double, N>& y_in)
        : t(t_in), y(y_in) {}

    // constructor that takes a vector, assumed to be length N

    solution(double t_in, std::vector<double>& y_in)
        : t(t_in)
    {
        assert(y_in.size() == N);
        std::copy(y_in.begin(), y_in.end(), y.begin());
    }

};

template<int N>
class ODE {

    double t{0.0};
    std::vector<double> y_init;
    std::vector<solution<N>> history{};
    rhs_func<N> rhs;

private:

    std::array<double, N> update_step(const std::array<double, N>& y0, double dt,
                                      std::array<double, N>& dydt) {

        std::array<double, N> y_new{y0};
        for (auto n = 0ul; n < y0.size(); ++n) {
            y_new[n] += dt * dydt[n];
        }

        return y_new;
    }

    std::array<double, N> rk4_step(const std::array<double, N>& y0, double dt) {

        // get the k1 acceleration
        auto k1 = rhs(t, y0);

        // get the k2 acceleration
        auto y_tmp = update_step(y0, 0.5*dt, k1);
        auto k2 = rhs(t + 0.5*dt, y_tmp);

        // get the k3 acceleration
        y_tmp = update_step(y0, 0.5*dt, k2);
        auto k3 = rhs(t + 0.5*dt, y_tmp);

        // get the k4 acceleration
        y_tmp = update_step(y0, dt, k3);
        auto k4 = rhs(t + dt, y_tmp);

        // compute the final update
        for (auto n = 0ul; n < y0.size(); ++n) {
            y_tmp[n] = y0[n] + (dt / 6.0) * (k1[n] + 2.0 * k2[n] + 2.0 * k3[n] + k4[n]);
        }

        return y_tmp;
    }


public:

    // constructor that takes an array with initial conditions

    ODE(rhs_func<N> rhs_in, std::array<double, N>& _y0)
        : y_init(_y0), rhs(rhs_in)
    {
        history.push_back(solution<N>(t, y_init));
    }

    // constructor that allow for an initialization list, e.g.,
    // ODE<N>(rhs, {1.0, 2.0, ...})

    ODE(rhs_func<N> rhs_in, std::initializer_list<double> _y0)
        : y_init(_y0.begin(), _y0.end()), rhs(rhs_in)
    {
        history.push_back(solution<N>(t, y_init));
    }

    std::vector<solution<N>>& integrate(double dt, double tmax) {

        while (t < tmax) {

            if (t + dt > tmax) {
                dt = tmax - t;
            }

            const auto & sol_old = history.back();

            auto y_new = rk4_step(sol_old.y, dt);
            t += dt;

            history.push_back(solution<N>(t, y_new));

        }
        return history;
    }

};
