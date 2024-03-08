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
};

OrbitState rhs(const OrbitState& state);
void write_history(const std::vector<OrbitState>& history);
std::vector<OrbitState> integrate(const double a, const double tmax, const double dt_in);

const double GM = 4.0 * M_PI * M_PI;   // G * Mass in AU, year, solar mass units


#endif
