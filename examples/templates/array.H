#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <iostream>
#include <cassert>
#include <limits>

// a contiguous 2-d array
// here the data is stored in row-major order in a 1-d memory space
// managed as a vector.  We overload () to allow us to index this as
// a(irow, icol)

template <typename T>
class Array {

private:

    std::size_t _rows;
    std::size_t _cols;
    std::vector<T> _data;

public:

    Array (std::size_t rows, std::size_t cols, T val=0.0)
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

    inline std::size_t ncols() const { return _cols;}
    inline std::size_t nrows() const { return _rows;}

    inline T& operator()(int row, int col) {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data[row*_cols + col];
    }

    inline const T& operator()(int row, int col) const {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data[row*_cols + col];
    }

    T min() const {
        T arr_min{std::numeric_limits<T>::max()};
        for (const auto& e : _data) {
            arr_min = std::min(arr_min, e);
        }
        return arr_min;
    }

    T max() const {
        T arr_max{std::numeric_limits<T>::lowest()};
        for (const auto& e : _data) {
            arr_max = std::max(arr_max, e);
        }
        return arr_max;
    }

};

// the << operator is not part of the of the class, so it is not a member

template <typename T>
std::ostream& operator<< (std::ostream& os, const Array<T>& a) {

    for (std::size_t row=0; row < a.nrows(); ++row) {
        for (std::size_t col=0; col < a.ncols(); ++col) {
            os << a(row, col) << " ";
        }
        os << std::endl;
    }

    return os;
}

#endif
