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

    // copy constructor
    Array (const Array& src) = default;

    // assignment operator
    Array& operator= (const Array& src) = default;

    // destructor
    ~Array() = default;

    // note the "const" after the argument list here -- this means
    // that this can be called on a const Array

    ///
    /// get the number of columns
    ///
    inline std::size_t ncols() const { return _cols;}

    ///
    /// get the number of rows
    ///
    inline std::size_t nrows() const { return _rows;}

    ///
    /// get the total number of elements in the array
    ///
    inline std::size_t nelements() const { return _cols * _rows;}

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

    ///
    /// return a flattened view of the data region -- this can be used with
    /// a range-for loop, e.g. `for (auto &e : a.flat()) {...}`
    ///
    inline std::vector<T>& flat() { return _data; }

    ///
    /// set an array element in the flattened index space
    ///
    inline T& flat(int element) {
        assert (element >= 0 && element < _rows * _cols);
        return _data[element];
    }

    ///
    /// get an array element in the flattened index space for
    /// a const array
    ///
    inline const T& flat(int element) const {
        assert (element >= 0 && element < _rows * _cols);
        return _data[element];
    }

    ///
    /// return the global minimum of the array
    ///
    T min() const {
        T arr_min{std::numeric_limits<T>::max()};
        for (const T& e : _data) {
            arr_min = std::min(arr_min, e);
        }
        return arr_min;
    }

    ///
    /// return the global maximum of the array
    ///
    T max() const {
        T arr_max{std::numeric_limits<T>::lowest()};
        for (const T& e : _data) {
            arr_max = std::max(arr_max, e);
        }
        return arr_max;
    }

};

// the << operator is not part of the of the class, so it is not a member

template <typename T>
inline
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
