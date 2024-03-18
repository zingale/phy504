#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

double rhs(double t, double y) {
    double dydt = -y;
    return dydt;
}

double true_y(double y0, double t) {
    return y0 * std::exp(-t);
}

double integrate(double y0, double dt, double tmax) {

    double t = 0.0;

    double y = y0;

    while (t < tmax) {

        if (t + dt > tmax) {
            dt = tmax - t;
        }

        y += dt * rhs(t, y);
        t += dt;

    }

    return y;

}

double integrate_rk2(double y0, double dt, double tmax) {

    double t = 0.0;

    double y = y0;

    while (t < tmax) {

        if (t + dt > tmax) {
            dt = tmax - t;
        }

        double ytmp = y + 0.5 * dt * rhs(t, y);

        y += dt * rhs(t + 0.5*dt, ytmp);

        t += dt;

    }

    return y;

}

int main() {

    double y0 = 1.0;
    double dt = 0.1;
    double tmax = 1.0;

    double err_euler;
    double err_rk2;

    std::cout << std::setprecision(6) << std::scientific;

    std::cout << "#" << std::setw(20) << "dt" << std::setw(20) << "Euler" << std::setw(20) << "RK2" << std::endl;
    for (int i = 0; i < 10; ++i) {
        err_euler = std::abs(integrate(y0, dt, tmax) - true_y(y0, tmax));
        err_rk2 = std::abs(integrate_rk2(y0, dt, tmax) - true_y(y0, tmax));
        std::cout << std::setw(20) << dt << std::setw(20) << err_euler << std::setw(20) << err_rk2 << std::endl;

        dt /= 2;
    }

}