#ifndef ORBIT_H
#define ORBIT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct OrbitState {
    double t;
    double x;
    double y;
    double vx;
    double vy;

    // we have 2 constructors

    OrbitState()
        : t{0.0}, x{0.0}, y{0.0}, vx{0.0}, vy{0.0}
    {}

    OrbitState(double _t, double _x, double _y, double _vx, double _vy)
        : t{_t}, x{_x}, y{_y}, vx{_vx}, vy{_vy}
    {}

    // operators

    OrbitState operator+(const OrbitState& orbit) {
        OrbitState orbit_new(t + orbit.t, 
                             x + orbit.x, y + orbit.y,
                             vx + orbit.vx, vy + orbit.vy);
        return orbit_new;
    }

    OrbitState operator-(const OrbitState& orbit) {
        OrbitState orbit_new(t - orbit.t,
                             x - orbit.x, y - orbit.y,
                             vx - orbit.vx, vy - orbit.vy);
        return orbit_new;
    }

    OrbitState operator*(double a) {
        OrbitState orbit_new(t * a, x * a, y * a, vx * a, vy * a);
        return orbit_new;
    }

    friend OrbitState operator*(double a, const OrbitState& orbit);

};

inline
OrbitState operator*(double a, const OrbitState& orbit) {

    OrbitState orbit_new(orbit.t * a,
                         orbit.x * a, orbit.y * a,
                         orbit.vx * a, orbit.vy * a);
    return orbit_new;

}

OrbitState rhs(const OrbitState& state);

void write_history(const std::vector<OrbitState>& history);

std::vector<OrbitState>
integrate(const double a,
          const double tmax, const double dt_in);

const double GM = 4.0 * M_PI * M_PI;   // G * Mass in AU, year, solar mass units


#endif
