#include <iostream>
#include <vector>
#include <mdspan>

int main() {

    // create a vector with 12 elements
    std::vector<double> _v(12, 0.0);

    // create a 2-d view (4 rows x 3 columns) into it
    auto M = std::mdspan(_v.data(), 4, 3);

    // loop over rows and columns and fill the matrix
    for (std::size_t i = 0; i < M.extent(0); ++i) {
        for (std::size_t j = 0; j < M.extent(1); ++j) {
            M[i, j] = static_cast<double>(100*i + j);
        }
    }

    // output
    for (std::size_t i = 0; i < M.extent(0); ++i) {
        for (std::size_t j = 0; j < M.extent(1); ++j) {
            std::cout << M[i, j] << " ";
        }
        std::cout << std::endl;
    }

}
