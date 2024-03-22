#include <iostream>
#include <vector>
#include <cassert>

using RealVec = std::vector<double>;
using RealMatrix = std::vector<RealVec>;

using Dim = RealVec::size_type;
using DataType = RealVec::value_type;

struct Matrix {

    RealMatrix data;

    // constructor
    Matrix (Dim rows, Dim cols, DataType val=0.0)
        : data(rows, RealVec(cols, val))
    {
        assert(cols > 0);
        assert(rows > 0);
    }

    const auto get_ncols() {
       return data[0].size();
    }

    const auto get_nrows() {
       return data.size();
    }
};

int main() {

    Matrix m(10, 10);

    std::cout << m.get_ncols() << " " << m.get_nrows() << std::endl;

}