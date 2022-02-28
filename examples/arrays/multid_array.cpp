#include <iostream>
#include <array>
#include <iomanip>

enum ArrayDims {kcols = 4,
                krows = 3};

using _1DArray = std::array<double, ArrayDims::kcols>;

using FixedSizedMatrix = std::array<_1DArray, ArrayDims::krows>;

int main() {

    FixedSizedMatrix M{0.0};

    double val{0.0};
    for (auto &r : M) {
        for (auto &c : r) {
            c = val++;
        }
    }

    for (auto r : M) {
        for (auto c : r) {
            std::cout << std::setw(4) << c << " ";
        }
        std::cout << std::endl;
    }
}
