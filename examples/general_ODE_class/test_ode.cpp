#include <array>

#include "ode_integrator.H"

constexpr int N{4};

std::array<double, N> orbit(double t, const std::array<double, N>& y) {

    std::array<double, N> dydt{};

    dydt[0] = -y[0];

    return dydt;

}

int main() {

    ODE<N> o(orbit, {1.0, 0.0, 0.0, 0.0});

    auto trajectory = o.integrate(0.1, 1.0);

    for (auto s : trajectory) {
        std::cout << s.t << " ";
        for (auto e : s.y) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }
}
