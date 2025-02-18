#include <iostream>
#include <mdspan>
#include <vector>

class Array2D {

    int nx;
    int ny;
    std::vector<double> _data;
    std::mdspan<double, std::dextents<size_t, 2>> _span;

public:

    Array2D(const int _nx, const int _ny) :
        nx(_nx), ny(_ny),
        _data(_nx*ny, 0.0),
        _span(_data.data(), std::dextents<size_t, 2>(_nx, _ny))
    {}

    const std::mdspan<double, std::dextents<size_t, 2>> get_span() const {
        return _span;
    }

};

int main() {

    Array2D a(5, 3);
    auto a_view = a.get_span();

    std::cout << "size = " << a_view.size() << std::endl;
    std::cout << "extents = " << a_view.extent(0) << " " << a_view.extent(1) << std::endl;

    a_view[0, 0] = 1.0;
    a_view[1, 2] = 2.0;

    for (int irow = 0; irow < a_view.extent(0); irow++) {
        for (int jcol = 0; jcol < a_view.extent(1); jcol++) {
            std::cout << a_view[irow, jcol] << " ";
        }
        std::cout << std::endl;
    }
}
