#include <iostream>
#include <cmath>
#include <chrono>
#include <array>

#include "array.H"

constexpr int MAX_SIZE = 10000;

int main() {


    // our Array class

    Array a(MAX_SIZE, MAX_SIZE);

    auto start = clock();

    for (std::size_t irow = 0; irow < a.nrows(); ++irow) {
        for (std::size_t icol = 0; icol < a.ncols(); ++icol) {
            a(irow, icol) = std::sqrt(static_cast<double> (irow + icol + 1));
        }
    }

    auto end = clock();

    std::cout << "Array timing (row-major loop): " <<
        static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

    // again Array, but loop in the wrong order

    Array b(MAX_SIZE, MAX_SIZE);

    start = clock();

    for (std::size_t icol = 0; icol < b.ncols(); ++icol) {
        for (std::size_t irow = 0; irow < b.nrows(); ++irow) {
            b(irow, icol) = std::sqrt(static_cast<double> (irow + icol + 1));
        }
    }

    end = clock();

    std::cout << "Array timing (col-major loop): " <<
        static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

    // fixed-size array
    // Note: this is allocated on the stack and the code crashes
    // on my machine if MAX_SIZE >~ 1000
    // valgrind will also complain

    std::array<std::array<double, MAX_SIZE>, MAX_SIZE> c;

    start = clock();

    for (std::size_t irow = 0; irow < c.size(); ++irow) {
        for (std::size_t icol = 0; icol < c[irow].size(); ++icol) {
            c[irow][icol] = std::sqrt(static_cast<double> (irow + icol + 1));
        }
    }

    end = clock();

    std::cout << "fixed-sized std::array<std::array>>: " <<
        static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;


    // vector of vectors

    std::vector<std::vector<double>> d(MAX_SIZE, std::vector<double>(MAX_SIZE, 0.0));

    start = clock();

    for (std::size_t irow = 0; irow < d.size(); ++irow) {
        for (std::size_t icol = 0; icol < d[irow].size(); ++icol) {
            d[irow][icol] = std::sqrt(static_cast<double> (irow + icol + 1));
        }
    }

    end = clock();

    std::cout << "std::vector<std::vector>>: " <<
        static_cast<double>(end - start) / CLOCKS_PER_SEC << std::endl;

}
