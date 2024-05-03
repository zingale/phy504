#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <cmath>

double f(double x) {
    return std::sin(x);
}

PYBIND11_MODULE(vectorize, m) {
    m.doc() = "simple example of creating a function f(x) in C++";
    m.def("f", pybind11::vectorize(f));
}

