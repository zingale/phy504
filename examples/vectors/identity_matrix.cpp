#include <iostream>
#include <vector>
#include <iomanip>

// a type alias -- we can now use RealVec to mean a vector of doubles

using RealVec = std::vector<double>;

// a RealMatrix is a vector of vectors of doubles

using RealMatrix = std::vector<RealVec>;

int main() {

    RealMatrix I;

    int N;

    std::cout << "enter the size of the matrix N: ";
    std::cin >> N;
    std::cout << std::endl;

    for (int r = 0; r < N; ++r) {
        RealVec row;
        for (int c = 0; c < N; ++c) {
            double e = 0.0;
            if (r == c) {
                e = 1.0;
            }
            row.push_back(e);
        }
        I.push_back(row);
    }

    for (int r = 0; r < I.size(); ++r) {
        for (int c = 0; c < I[r].size(); ++c) {
            std::cout << std::setw(4) << I[r][c] << " ";
        }
        std::cout << std::endl;
    }

}