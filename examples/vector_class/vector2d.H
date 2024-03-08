#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>

class Vector2d {

private:

    // our member data

    double x;
    double y;

public:

    // default constructor

    Vector2d()
        : x{0.0}, y{0.0}
    {}

    // another constructor

    Vector2d(double _x, double _y)
        : x{_x}, y{_y}
    {}

    // setters

    inline void set_x(double _x) {x = _x;}

    inline void set_y(double _y) {y = _y;}

    // operators

    // add two vectors

    Vector2d operator+(const Vector2d& vec) {
        Vector2d v_out;
        v_out.x = x + vec.x;
        v_out.y = y + vec.y;
        return v_out;
    }

    // subtract two vectors

    Vector2d operator-(const Vector2d& vec) {
        Vector2d v_out;
        v_out.x = x - vec.x;
        v_out.y = y - vec.y;
        return v_out;
    }

    // unary minus

    Vector2d operator-() {
        Vector2d v_out;
        v_out.x = -x;
        v_out.y = -y;
        return v_out;
    }

    // << is not a class member, but needs access to the member data

    friend std::ostream& operator<< (std::ostream& os, const Vector2d& v);
};

inline
std::ostream& operator<< (std::ostream& os, const Vector2d& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

#endif
