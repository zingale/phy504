#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <iostream>
#include <cassert>
#include <memory>
#include <cstring>

// a contiguous 2-d array

// here the data is stored in row-major order in a 1-d memory space
// managed as a vector.  We overload () to allow us to index this as
// a(irow, icol)

struct Array {

    std::size_t _rows;
    std::size_t _cols;
    std::unique_ptr<double []> _data;

    Array (std::size_t rows, std::size_t cols, double val=0.0)
        : _rows{rows},
          _cols{cols}
    {
        // we do the asserts here after the initialization of _data
        // in the initialization list, but if the size is zero, we'll
        // abort here anyway.

        assert (rows > 0);
        assert (cols > 0);

        _data = std::make_unique<double []> (rows * cols);

        for (int i = 0; i < rows * cols; ++i) {
            _data.get()[i] = val;
        }

    }

    ~Array() = default;

    // copy constructor

    Array(const Array& src)
        : _rows{src._rows},
          _cols{src._cols}
    {
        _data = std::make_unique<double []> (_rows * _cols);
        std::memcpy(_data.get(), src._data.get(),
                    _rows * _cols * sizeof(double));
    }

    // assignment operator
    // we won't consider this, because in reality we should probably
    // enforce that they are the same size
    Array& operator= (const Array& src) = delete;

    // move constructor

    Array(Array&& src)
        : _rows{src._rows},
          _cols{src._cols},
          _data(nullptr)
    {
        std::swap(_rows, src._rows);
        std::swap(_cols, src._cols);
        _data.swap(src._data);
    }

    // note the "const" after the argument list here -- this means
    // that this can be called on a const Array

    inline std::size_t ncols() const { return _cols;}
    inline std::size_t nrows() const { return _rows;}

    inline double& operator()(int row, int col) {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data.get()[row*_cols + col];
    }

    inline const double& operator()(int row, int col) const {
        assert (row >= 0 && row < _rows);
        assert (col >= 0 && col < _cols);
        return _data.get()[row*_cols + col];
    }

};

// the << operator is not part of the of the class, so it is not a member

inline
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
