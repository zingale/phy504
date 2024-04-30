#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <cassert>
#include <iostream>
#include <stacktrace>
#include <limits>

///
/// a contiguous 2-d array
/// here the data is stored in row-major order in a 1-d memory space
/// managed as a vector.  We overload () to allow us to index this as
/// a(irow, icol)
///
/// the array index does not need to start at 0 here, instead a constructor
/// is provided that takes the starting index and ending index in each
/// dimension
///
class Array {

private:

    int _xoffset;
    int _yoffset;
    int _nx;
    int _ny;
    std::vector<double> _data;

public:

    Array (int xlo, int xhi, int ylo, int yhi, double val=0.0)
        : _xoffset{xlo}, _yoffset{ylo},
          _nx{xhi - xlo + 1}, _ny{yhi - ylo + 1},
          _data(_nx * _ny, val)
    {
        assert (_nx > 0);
        assert (_ny > 0);
    }

    inline int xsize() const { return _nx;}

    inline int ysize() const { return _ny;}

    inline int xlo() const { return _xoffset;}

    inline int ylo() const { return _yoffset;}

    inline int xhi() const { return _xoffset + _nx - 1;}

    inline int yhi() const { return _yoffset + _ny - 1;}

    inline double& operator()(int i, int j) {
        int row = i - _xoffset;
        int col = j - _yoffset;
        assert (row >= 0 && row < _nx);
        assert (col >= 0 && col < _ny);
        return _data[row * _ny + col];
    }

    inline const double& operator()(int i, int j) const {
        int row = i - _xoffset;
        int col = j - _yoffset;
        assert (row >= 0 && row < _nx);
        assert (col >= 0 && col < _ny);
        return _data[row * _ny + col];
    }

    inline const double* data() const { return _data.data(); }

    inline double* data() { return _data.data(); }

    friend std::ostream& operator<< (std::ostream& os, const Array& a);

};

inline
std::ostream& operator<< (std::ostream& os, const Array& a) {

    for (int i = a.xlo(); i <= a.xhi(); ++i) {
        for (int j = a.ylo(); j <= a.yhi(); ++j) {
            os << a(i, j) << " ";
        }
        os << std::endl;
    }

    return os;
}

#endif
