#include <vector>

#include "orbit.H"

int main() {

    double tmax = 1.0;
    double dt = 0.05;
    double a = 1.0;      // 1 AU

    std::vector<double> times;
    std::vector<OrbitState> orbit_history;

    integrate(a, tmax, dt, times, orbit_history);
    write_history(times, orbit_history);

}
