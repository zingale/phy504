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

    Array (int nx, int ny, double val=0.0)
        : _xoffset{0}, _yoffset{0},
          _nx{nx}, _ny{ny},
          _data(_nx * _ny, val)
    {
        // we do the asserts here after the initialization of _data
        // in the initialization list, but if the size is zero, we'll
        // abort here anyway.

        assert (_nx > 0);
        assert (_ny > 0);

    }

    Array (int xlo, int xhi, int ylo, int yhi, double val=0.0)
        : _xoffset{xlo}, _yoffset{ylo},
          _nx{xhi - xlo + 1}, _ny{yhi - ylo + 1},
          _data(_nx * _ny, val)
    {
        // we do the asserts here after the initialization of _data
        // in the initialization list, but if the size is zero, we'll
        // abort here anyway.

        assert (_nx > 0);
        assert (_ny > 0);

    }

    // note the "const" after the argument list here -- this means
    // that this can be called on a const Array, while the first
    // "const" refers to the return type

    ///
    /// get x length
    ///
    inline int nx() const { return _nx;}

    ///
    /// get y length
    ///
    inline int ny() const { return _ny;}


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

    inline const double& operator()(int row, int col) const {
        int row = i - _xoffset;
        int col = j - _yoffset;
        assert (row >= 0 && row < _nx);
        assert (col >= 0 && col < _ny);
        return _data[row * _ny + col];
    }

    ///
    /// return a flattened view of the data region -- this can be used with
    /// a range-for loop, e.g. `for (auto &e : a.flat()) {...}`
    ///
    inline std::vector<double>& flat() { return _data; }

    ///
    /// set the array element i in the flattened index space
    ///
    inline double& flat(int i) {
        assert (i >= 0 && i < _nx * _ny);
        return _data[i];
    }

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

    for (int i = a.xlo(); i <= a.xhi(); ++i) {
        for (int j = a.ylo(); j <= a.yhi(); ++j) {
            os << a(i, j) << " ";
        }
        os << std::endl;
    }

    return os;
}

#endif