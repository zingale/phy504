#include <iostream>

#include "roots.H"

int main() {

    int ierr{0};
    double root{0.0};

    ierr = bisection(-5.0, 5.0,
                     [] (double x) {return x*x*x + x*x - 1.0;}, root);

    if (ierr == 0) {
        std::cout << root << std::endl;
    } else {
        std::cout << "root not found" << std::endl;
    }

    ierr = bisection(-5.0, 5.0,
                     [] (double x) {return x*x;}, root);

    if (ierr == 0) {
        std::cout << root << std::endl;
    } else {
        std::cout << "root not found" << std::endl;
    }

    ierr = newton(-1.0,
                  [] (double x) {return x*x;}, [] (double x) {return 2*x;}, root);

    if (ierr == 0) {
        std::cout << root << std::endl;
    } else {
        std::cout << "root not found" << std::endl;
    }

}
