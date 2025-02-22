#include "gplot++.h"
#include <cmath>
#include <iostream>
#include <numbers>

int main(void) {
  Gnuplot gnuplot{};
  std::vector<double> x, y, z;

  for (double angle = 0; angle < 6 * std::numbers::pi; angle += 0.1) {
    x.push_back(cos(angle));
    y.push_back(sin(angle));
    z.push_back(angle / 2 * std::numbers::pi);
  }

  gnuplot.plot3d(x, y, z);
  gnuplot.show();
}
