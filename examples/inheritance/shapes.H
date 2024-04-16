#ifndef SHAPES_H
#define SHAPES_H

#include <vector>
#include <numeric>

class Quadrilateral {

protected:

    // store the side data
    // order: top, bottom, left, right

    std::vector<double> sides;

public:

    Quadrilateral()
        : sides{1.0, 1.0, 1.0, 1.0} {}

    Quadrilateral(double s1, double s2, double s3, double s4)
        : sides{s1, s2, s3, s4} {}

    double perimeter() {
        return std::accumulate(sides.cbegin(), sides.cend(), 0.0);
    }
};


class Rectangle : public Quadrilateral {

public:

    Rectangle(double width, double height)
        : Quadrilateral(width, width, height, height) {}

    double area() {
        return sides[0] * sides[2];
    }
};

#endif
