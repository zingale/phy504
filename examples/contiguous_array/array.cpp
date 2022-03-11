#include <vector>
#include <iostream>
#include <cassert>

// a contiguous 2-d array
// here the data is stored in row-major order in a 1-d memory space
// managed as a vector.  We overload () to allow us to index this as
// a(irow, icol)

struct Array {

    std::vector<double> _data;
    std::size_t _rows;
    std::size_t _cols;
    Array (std::size_t rows, std::size_t cols, double val=0.0)
        : _rows{rows},
          _cols{cols}
          //_data(rows * cols, val)
    {
        assert (rows > 0);
        assert (cols > 0);

        // we do the initialization of _data here so we can first assert
        // on the rows and cols.  If we placed it in the initialization list,
        // then it would be created before we could check.

        _data.resize(rows * cols, val);
    }
    
    // note the "const" after the argument list here -- this means
    // that this can be called on a const Array, while the first
    // "const" refers to the return type

    const std::size_t ncols() const { return _cols;}
    const std::size_t nrows() const { return _rows;}

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;

};


double& Array::operator()(int row, int col) {
    assert (row >= 0 && row < _rows);
    assert (col >= 0 && col < _cols);

    return _data[row*_cols + col];
}  

const double& Array::operator()(int row, int col) const {
    assert (row >= 0 && row < _rows);
    assert (col >= 0 && col < _cols);

    return _data[row*_cols + col];
}  

std::ostream& operator<< (std::ostream& os, const Array& a) {

    for (int row=0; row < a.nrows(); ++row) {
        for (int col=0; col < a.ncols(); ++col) {
            os << a(row, col) << " ";
        }
        os << std::endl;
    }

    return os;
}

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

    // this will fail the assertion
    std::cout << x(11, 9);

}
