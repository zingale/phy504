#include <iostream>
#include <vector>

// a type alias -- we can now use RealVec to mean a vector of doubles

using RealVec = std::vector<double>;

// a RealMatrix is a vector of vectors of doubles

using RealMatrix = std::vector<RealVec>;

int main() {

    RealMatrix M = {
                     {  1.0, 25.0, 0.0,  4.1},
                     { -1.0,  2.0, 4.5, -3.1},
                     { 10.0, -6.0, 3.2,  4.0}
                    };

    // add another row

    M.push_back({ 20.0, 2.0, 0.0, 5.0});

    // let's compute the trace (sum over the diagonal)

    double trace = 0.0;

    for (int i = 0; i < M.size(); ++i) {
        trace += M[i][i];
    }

    std::cout << "trace = " << trace << std::endl;

    // now the sum of all the off-diagonal terms

    double off_diag_sum = 0.0;

    for (int r = 0; r < M.size(); ++r) {
        for (int c = 0; c < M[r].size(); ++c) {
            if (r != c) {
                off_diag_sum += M[r][c];
            }
        }
    }

    std::cout << "off-diagonal sum = " << off_diag_sum << std::endl;

}