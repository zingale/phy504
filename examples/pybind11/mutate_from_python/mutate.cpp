#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void update(py::array_t<double>& a) {

    auto a_arr = a.mutable_unchecked<2>();

    for (py::ssize_t i = 0; i < a_arr.shape(0); ++i) {
        for (py::ssize_t j = 0; j < a_arr.shape(1); ++j) {
                a_arr(i, j) *= 100;
        }
    }

}

PYBIND11_MODULE(mutate, m) {
    m.doc() = "change the of a 2-dimensional array";
    m.def("update", &update);
}

