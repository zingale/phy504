#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

void update(pybind11::array_t<double>& a) {

    auto a_arr = a.mutable_unchecked<2>();

    for (pybind11::ssize_t i = 0; i < a_arr.shape(0); ++i) {
        for (pybind11::ssize_t j = 0; j < a_arr.shape(1); ++j) {
                a_arr(i, j) *= 100;
        }
    }

}

PYBIND11_MODULE(mutate, m) {
    m.doc() = "change the of a 2-dimensional array";
    m.def("update", &update);
}

