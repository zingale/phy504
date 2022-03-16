#include <vector>
#include <iostream>
#include <cassert>

#include "array.H"

// notice that we can put the function body for these member functions
// outside of the class definition.  We just need to prefix them as
// Array::


// the << operator is not part of the of the class, so it is not a member

std::ostream& operator<< (std::ostream& os, const Array& a) {

    for (int row=0; row < a.nrows(); ++row) {
        for (int col=0; col < a.ncols(); ++col) {
            os << a(row, col) << " ";
        }
        os << std::endl;
    }

    return os;
}
