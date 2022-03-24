#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>

struct Vector2d {

    double x;
    double y;

    Vector2d()
      : x{0.0}, y{0.0}
    {}

    Vector2d(double _x, double _y)
      : x{_x}, y{_y}
    {};

    Vector2d operator+(const Vector2d& vec) {
        Vector2d v_out;
        v_out.x = x + vec.x;
        v_out.y = y + vec.y;
        return v_out;
    }

    Vector2d operator-(const Vector2d& vec) {
        Vector2d v_out;
        v_out.x = x - vec.x;
        v_out.y = y - vec.y;
        return v_out;
    }

    Vector2d operator-() {
        Vector2d v_out;
        v_out.x = -x;
        v_out.y = -y;
        return v_out;
    }
};

std::ostream& operator<< (std::ostream& os, const Vector2d& v)
{
    os << v.x << "x̂" << " + " << v.y << "ŷ";
    return os;
}

#endif