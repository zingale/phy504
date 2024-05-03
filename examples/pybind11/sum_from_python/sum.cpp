#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

double sum(pybind11::array_t<double>& a) {

    auto a_arr = a.unchecked<2>();

    double suma{0.0};

    for (pybind11::ssize_t i = 0; i < a_arr.shape(0); ++i) {
        for (pybind11::ssize_t j = 0; j < a_arr.shape(1); ++j) {
                suma += a_arr(i, j);
        }
    }

    return suma;

}

PYBIND11_MODULE(sum, m) {
    m.doc() = "sum the elements of a 2-dimensional array";
    m.def("sum", &sum);
}

