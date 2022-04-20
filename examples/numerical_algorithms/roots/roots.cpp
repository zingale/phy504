#include <iostream>
#include <functional>
#include <cmath>

double bisection(double xleft, double xright, std::function<double(double)> f) {

    const double tol = 1.e-10;

    double fleft = f(xleft);
    double fright = f(xright);

    if (fleft * fright >= 0) {
        std::cout << "no root in interval [xleft, right]" << std::endl;
        abort();
    }

    double xmid = 0.5 * (xleft + xright);

    double err = std::abs(xright - xleft);
    while (err > tol * std::abs(xmid)) {
        double fmid = f(xmid);

        if (fleft * fmid > 0.0) {
            // root is in [fmid, fright]
            xleft = xmid;
        } else {
            // root is in [fleft, fmid]
            xright = xmid;
        }

        err = std::abs(xright - xleft);
        xmid = 0.5 * (xleft + xright);

    }

    return xmid;
}

int main() {

    double r = bisection(-5.0, 5.0,
                         [](double x) {return x*x*x + x*x - 1.0;});

    std::cout << r << std::endl;

}