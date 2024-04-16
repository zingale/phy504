#include <iostream>

#include "array.H"

int main() {

    Array x(10, 10);

    for (std::size_t row=0; row < x.nrows(); ++row) {
        for (std::size_t col=0; col < x.ncols(); ++col) {
            if (row == col) {
                x(row, col) = 1.0;
            }
        }
    }

    std::cout << x << std::endl;

    // copy constructor;
    Array y = x;

    std::cout << y << std::endl;

    // this will fail the assertion
    //std::cout << x(11, 9);

}
