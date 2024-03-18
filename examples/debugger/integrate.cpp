#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

double f(double x) {
    return std::sin(x) * std::sin(x);
}


void integrate(int N, double xmin, double xmax, double I) {

    double dx = (xmax - xmin) / N;

    double xleft{xmin};
    double fleft = f(xleft);

    double xright{0.0};
    double fright{0.0};

    for (int n = 0; n <= N; ++n) {

        xright = xmin + (n+1) * dx;
        fright = f(xright);

        I += 1/2 * dx * (fleft + fright);

        xleft = xright;
        fleft = fright;
    }

}

int main() {

    int N{-1};

    std::cout << "enter the number of intervals: ";
    std::cin >> N;

    assert(N > 0);

    double I{0.0};

    double xmin{0.0};
    double xmax{2.0*M_PI};

    integrate(N, xmin, xmax, I);

    std::cout << "integral is " << std::setprecision(15) << I << std::endl;

}