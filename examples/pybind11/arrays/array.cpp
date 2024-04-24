#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>


namespace py = pybind11;

py::array_t<double> hilbert(const int N) {

    // construct the numpy array we will return
    // we need to specify the strides manually

    constexpr size_t elsize = sizeof(double);
    size_t shape[2]{N, N};
    size_t strides[2]{N * elsize, elsize};
    auto H = py::array_t<double>(shape, strides);
    auto H_view = H.mutable_unchecked<2>();

    for (int i = 0; i < H.shape(0); ++i) {
        for (int j = 0; j < H.shape(1); ++j) {
            H_view(i, j) = 1.0 / (static_cast<double>(i + j) + 1.0);
        }
    }

    return H;
}


PYBIND11_MODULE(array, m) {
    m.doc() = "simple example of creating a NumPy array (Hilbert matrix) in C++";
    m.def("hilbert", &hilbert);
}

