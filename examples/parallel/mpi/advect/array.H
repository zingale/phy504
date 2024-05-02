#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <cassert>
#include <iostream>
#include <stacktrace>
#include <limits>

///
/// a contiguous 2-d array -- here the data is stored in row-major
/// order in a 1-d memory space managed as a vector.  The array index
/// does not need to start at 0 here, instead a constructor is
/// provided that takes the starting index and ending index in each
/// dimension
///
class Array {

public:

    int nx;
    int ny;

private:

    int _xoffset;
    int _yoffset;
    std::vector<double> _data;

public:

    Array (int xlo, int xhi, int ylo, int yhi, double val=0.0)
        : nx{xhi - xlo + 1}, ny{yhi - ylo + 1}, _xoffset{xlo}, _yoffset{ylo},
          _data(nx * ny, val)
    {
        assert (nx > 0);
        assert (ny > 0);
    }

    inline int xlo() const { return _xoffset;}
    inline int ylo() const { return _yoffset;}

    inline int xhi() const { return _xoffset + nx - 1;}
    inline int yhi() const { return _yoffset + ny - 1;}

    inline double& operator()(int i, int j) {
        int row = i - _xoffset;
        int col = j - _yoffset;
        assert (row >= 0 && row < nx);
        assert (col >= 0 && col < ny);
        return _data[row * ny + col];
    }

    inline const double& operator()(int i, int j) const {
        int row = i - _xoffset;
        int col = j - _yoffset;
        assert (row >= 0 && row < nx);
        assert (col >= 0 && col < ny);
        return _data[row * ny + col];
    }

    inline const double* data() const { return _data.data(); }

    inline double* data() { return _data.data(); }

};
#endif
