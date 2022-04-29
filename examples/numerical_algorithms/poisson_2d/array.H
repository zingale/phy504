#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <iostream>
#include <cassert>
#include <limits>

///
/// a contiguous 2-d array
/// here the data is stored in row-major order in a 1-d memory space
/// managed as a vector.  We overload () to allow us to index this as
/// a(irow, icol)
///
class Array {

private:

    std::size_t _rows;
    std::size_t _cols;
    std::vector<double> _data;

public:

    Array (std::size_t rows, std::size_t cols, double val=0.0)
        : _rows{rows},
          _cols{cols},
          _data(rows * cols, val)
    {
        // we do the asserts here after the initialization of _data
        // in the initialization list, but if the size is zero, we'll
        // abort here anyway.

        assert (rows > 0);
        assert (cols > 0);

    }

    // note the "const" after the argument list here -- this means
    // that this can be called on a const Array, while the first
    // "const" refers to the return type

    ///
    /// get the number of columns
    ///
    inline std::size_t ncols() const { return _cols;}

    ///
    /// get the number of rows
    ///
    inline std::size_t nrows() const { return _rows;}

    inline double& operator()(int row, int col) {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data[row*_cols + col];
    }

    inline const double& operator()(int row, int col) const {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data[row*_cols + col];
    }

    ///
    /// return a flattened view of the data region -- this can be used with
    /// a range-for loop, e.g. `for (auto &e : a.flat()) {...}`
    ///
    inline std::vector<double>& flat() { return _data; }

    ///
    /// set the array element i in the flattened index space
    ///
    inline double& flat(int i) { return _data[i]; }

    ///
    /// return the global minimum of the array
    ///
    double min() {
        double current_min = std::numeric_limits<double>::max();

        for (auto e : _data) {
            if (e < current_min) {
                current_min = e;
            }
        }
        return current_min;
    }

    ///
    /// return the global maximum of the array
    ///
    double max() {
        double current_max = std::numeric_limits<double>::lowest();

        for (auto e : _data) {
            if (e > current_max) {
                current_max = e;
            }
        }
        return current_max;
    }

    friend std::ostream& operator<< (std::ostream& os, const Array& a);

};

// the << operator is not part of the of the class, so it is not a member

std::ostream& operator<< (std::ostream& os, const Array& a) {

    for (std::size_t row=0; row < a.nrows(); ++row) {
        for (std::size_t col=0; col < a.ncols(); ++col) {
            os << a(row, col) << " ";
        }
        os << std::endl;
    }

    return os;
}

#endif