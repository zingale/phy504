#include <iostream>

#include "array.H"

int main() {

    Array<double> x(5, 5);

    for (std::size_t row=0; row < x.nrows(); ++row) {
        for (std::size_t col=0; col < x.ncols(); ++col) {
            if (row == col) {
                x(row, col) = 1.5;
            }
        }
    }

    std::cout << x << std::endl;

    Array<int> y(5, 5);

    for (std::size_t row=0; row < y.nrows(); ++row) {
        for (std::size_t col=0; col < y.ncols(); ++col) {
            if (row == col) {
                y(row, col) = 1.5;
            }
        }
    }

    std::cout << y << std::endl;


}
