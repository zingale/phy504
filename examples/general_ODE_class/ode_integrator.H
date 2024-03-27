#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>


template<int N>
struct solution {
    double t;
    std::array<double, N> y{};

    solution(double t_in, std::array<double, N>& y_in)
        : t(t_in), y(y_in) {}

};

template<int N>
class ODE {

    double t{0.0};
    std::array<double, N> y_init;
    std::vector<solution<N>> history{};
    std::function<std::array<double, N>(double, const std::array<double, N>&)> rhs;

public:

    ODE(std::function<std::array<double, N>(double, const std::array<double, N>&)> rhs_in,
        std::array<double, N> _y0)
        : y_init(_y0), rhs(rhs_in)
    {
        history.push_back(solution<N>(t, y_init));
    }

    std::vector<solution<N>>& integrate(double dt, double tmax) {

        while (t < tmax) {

            if (t + dt > tmax) {
                dt = tmax - t;
            }

            std::cout << "t, dt = " << t << " " << dt << std::endl;

            const auto & sol_old = history.back();

            // get the acceleration
            auto dydt = rhs(t, sol_old.y);

            // update the solution
            std::array<double, N> y_new{sol_old.y};
            for (int n = 0; n < y_new.size(); ++n) {
                y_new[n] += dt * dydt[n];
            }

            t += dt;

            history.push_back(solution<N>(t, y_new));

        }
        return history;
    }

};
