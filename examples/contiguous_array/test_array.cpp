#include <iostream>

#include "array.H"

int main() {

    Array x(10, 10);

    for (int row=0; row < x.nrows(); ++row) {
        for (int col=0; col < x.ncols(); ++col) {
            if (row == col) {
                x(row, col) = 1.0;
            }
        }
    }

    std::cout << x << std::endl;

    Array y(4, 3);

    double c{0};
    for (auto &e : y._data) {
        e = c;
        c += 1;
    }

    std::cout << y << std::endl;
    
    // this will fail the assertion
    //std::cout << x(11, 9);

}
