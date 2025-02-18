module;

// includes must be in the "global fragment" and precede the main
// purview that's why we add the `module;` above.

#include <cmath>

export module Example;

export double f(double x) {
    return std::sin(x);
}
