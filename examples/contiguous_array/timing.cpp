#include <iostream>
#include <chrono>
#include <array>

#include "array.H"

constexpr int MAX_SIZE = 1000;

int main() {


    // our Array class

    Array a(MAX_SIZE, MAX_SIZE);

    auto start = clock();

    for (int irow = 0; irow < a.nrows(); ++irow) {
        for (int icol = 0; icol < a.ncols(); ++icol) {
            a(irow, icol) = static_cast<double> (irow + icol + 1);
        }
    }

    auto end = clock();

    std::cout << "Array timing (row-major loop): " <<
        static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

    // again Array, but loop in the wrong order

    Array b(MAX_SIZE, MAX_SIZE);

    start = clock();

    for (int icol = 0; icol < b.ncols(); ++icol) {
        for (int irow = 0; irow < b.nrows(); ++irow) {
            b(irow, icol) = static_cast<double> (irow + icol + 1);
        }
    }

    end = clock();

    std::cout << "Array timing (col-major loop): " <<
        static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

    // fixed-size array

    std::array<std::array<double, MAX_SIZE>, MAX_SIZE> c;

    start = clock();

    for (int irow = 0; irow < c.size(); ++irow) {
        for (int icol = 0; icol < c[irow].size(); ++icol) {
            c[irow][icol] = static_cast<double> (irow + icol + 1);
        }
    }

    end = clock();

    std::cout << "fixed-sized std::array<std::array>>: " <<
        static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

}
