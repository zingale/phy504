#include <iostream>
#include <iomanip>

#include "planet.H"

std::ostream& operator<< (std::ostream& os, const Planet& p) {

    os << std::setw(12) << p.name << " : ("
       << std::setw(8) << p.a << " , "
       << std::setw(8) << p.e << ")";

    return os;
}
