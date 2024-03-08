#include "orbit.H"

int main() {

    double tmax = 1.0;
    double dt = 0.05;
    double a = 1.0;      // 1 AU

    auto orbit_history = integrate(a, tmax, dt);
    write_history(orbit_history);

}
