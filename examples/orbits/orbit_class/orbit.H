#ifndef ORBIT_H
#define ORBIT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct OrbitState {
    double x;
    double y;
    double vx;
    double vy;

    OrbitState()
        : x{0.0}, y{0.0}, vx{0.0}, vy{0.0}
    {}

    OrbitState(double _x, double _y, double _vx, double _vy)
        : x{_x}, y{_y}, vx{_vx}, vy{_vy}
    {}

    OrbitState operator+(const OrbitState& orbit) {
        OrbitState orbit_new(x + orbit.x, y + orbit.y,
                             vx + orbit.vx, vy + orbit.vy);
        return orbit_new;
    }

    OrbitState operator-(const OrbitState& orbit) {
        OrbitState orbit_new(x - orbit.x, y - orbit.y,
                             vx - orbit.vx, vy - orbit.vy);
        return orbit_new;
    }

    OrbitState operator*(double a) {
        OrbitState orbit_new(x * a, y * a, vx * a, vy * a);
        return orbit_new;
    }

    friend OrbitState operator*(double a, const OrbitState& orbit);

};

inline
OrbitState operator*(double a, const OrbitState& orbit) {

    OrbitState orbit_new(orbit.x * a, orbit.y * a,
                         orbit.vx * a, orbit.vy * a);
    return orbit_new;

}

OrbitState rhs(const OrbitState& state);

void write_history(const std::vector<double> times,
                   const std::vector<OrbitState>& history);

void integrate(const double a,
               const double tmax, const double dt_in,
               std::vector<double>& times,
               std::vector<OrbitState>& orbit_history);

const double GM = 4.0 * M_PI * M_PI;   // G * Mass in AU, year, solar mass units


#endif
