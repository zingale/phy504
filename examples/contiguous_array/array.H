#ifndef ARRAY_H
#define ARRAY_H

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

    inline std::size_t ncols() const { return _cols;}
    inline std::size_t nrows() const { return _rows;}

    inline double& operator()(int row, int col);
    inline const double& operator()(int row, int col) const;

};


// the << operator is not part of the of the class, so it is not a member

std::ostream& operator<< (std::ostream& os, const Array& a);

inline double& Array::operator()(int row, int col) {
    assert (row >= 0 && row < _rows);
    assert (col >= 0 && col < _cols);

    return _data[row*_cols + col];
}

inline const double& Array::operator()(int row, int col) const {
    assert (row >= 0 && row < _rows);
    assert (col >= 0 && col < _cols);

    return _data[row*_cols + col];
}


#endif
