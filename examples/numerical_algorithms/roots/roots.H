#ifndef ROOTS_H
#define ROOTS_H

#include <iostream>
#include <functional>
#include <cmath>

namespace Roots {
    const double ATOL = 1.e-10;   // absolute tolerance
    const double RTOL = 1.e-10;   // relative tolerance
    const int MAX_ITER = 100;
}

///
/// Apply bisection to find a root of f(x) in the range [xleft, xright]
/// Return value is 0 if root found, non-zero if there was an error
///
int bisection(double xleft, double xright,
              std::function<double(double)> f,
              double& root) {

    int ierr{0};

    double fleft = f(xleft);
    double fright = f(xright);

    if (fleft * fright > 0) {
        std::cout << "no root in interval [xleft, right]" << std::endl;
        ierr = 1;
        return ierr;
    } else if (fleft == 0 || fright == 0) {
        std::cout << "root is one of bounds" << std::endl;
        ierr = 1;
        return ierr;
    }

    double xmid = 0.5 * (xleft + xright);

    int iter{0};

    while (iter < Roots::MAX_ITER) {
        double fmid = f(xmid);

        if (fleft * fmid > 0.0) {
            // root is in [fmid, fright]
            xleft = xmid;
        } else {
            // root is in [fleft, fmid]
            xright = xmid;
        }

        double err = std::abs(xright - xleft);
        xmid = 0.5 * (xleft + xright);

        if (err < Roots::RTOL * std::abs(xmid) + Roots::ATOL) {
            ierr = 0;
            break;
        }

        iter++;
    }

    root = xmid;

    return ierr;
}

///
/// Apply Newtons's method to find a root of f(x) starting with the initial
/// guess x0.  In addition to f(x) we need to supply the derivative, dfdx(x).
/// Return value is 0 if root found, non-zero if there was an error
///
int newton(double x0,
           std::function<double(double)> f,
           std::function<double(double)> dfdx,
           double& root) {

    int ierr{1};

    double f0 = f(x0);
    double dfdx0 = dfdx(x0);

    root = x0;

    int iter{0};

    while (iter < Roots::MAX_ITER ) {

        double dx = -f0/dfdx0;

        if (std::abs(dx) < Roots::RTOL * std::abs(x0) + Roots::ATOL) {
            ierr = 0;
            root = x0;
            break;
        }

        x0 += dx;

        f0 = f(x0);
        dfdx0 = dfdx(x0);

        iter++;
    }

    return ierr;
}
#endif
