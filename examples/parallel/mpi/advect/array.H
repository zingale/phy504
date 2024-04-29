#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <iostream>
#include <stacktrace>
#include <limits>

void myassert(bool test) {
    if (! test) {
        std::cout << std::stacktrace::current() << std::endl;
        abort();
    }
}


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

        
        myassert (_nx > 0);
        myassert (_ny > 0);

    }

    Array (int xlo, int xhi, int ylo, int yhi, double val=0.0)
        : _xoffset{xlo}, _yoffset{ylo},
          _nx{xhi - xlo + 1}, _ny{yhi - ylo + 1},
          _data(_nx * _ny, val)
    {
        // we do the asserts here after the initialization of _data
        // in the initialization list, but if the size is zero, we'll
        // abort here anyway.

        myassert (_nx > 0);
        myassert (_ny > 0);

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

    ///
    /// get the lower x index
    ///
    inline int xlo() const { return _xoffset;}

    ///
    /// get the lower y index
    ///
    inline int ylo() const { return _yoffset;}

    ///
    /// get the upper x index
    ///
    inline int xhi() const { return _xoffset + _nx - 1;}

    ///
    /// get the upper y index
    ///
    inline int yhi() const { return _yoffset + _ny - 1;}

    inline double& operator()(int i, int j) {
        int row = i - _xoffset;
        int col = j - _yoffset;
        myassert (row >= 0 && row < _nx);
        myassert (col >= 0 && col < _ny);
        return _data[row * _ny + col];
    }

    inline const double& operator()(int i, int j) const {
        int row = i - _xoffset;
        int col = j - _yoffset;
        myassert (row >= 0 && row < _nx);
        myassert (col >= 0 && col < _ny);
        return _data[row * _ny + col];
    }

    ///
    /// return a flattened view of the data region -- this can be used with
    /// a range-for loop, e.g. `for (auto &e : a.flat()) {...}`
    ///
    inline std::vector<double>& flat() { return _data; }

    ///
    /// return the global minimum of the array
    ///
    inline double min() const {
        double current_min = std::numeric_limits<double>::max();

        for (auto e : _data) {
            current_min = std::min(current_min, e);
        }
        return current_min;
    }

    ///
    /// return the global maximum of the array
    ///
    inline double max() const {
        double current_max = std::numeric_limits<double>::lowest();

        for (auto e : _data) {
            current_max = std::max(current_max, e);
        }
        return current_max;
    }

    friend std::ostream& operator<< (std::ostream& os, const Array& a);

};

// the << operator is not part of the of the class, so it is not a member

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
