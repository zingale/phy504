#include <iostream>
#include "array.H"
#include "grid.H"

int main() {

    constexpr int nx{15};
    constexpr int ny{10};
    constexpr int ng{0};

    constexpr double xmin{0.0};
    constexpr double xmax{1.0};
    constexpr double ymin{0.0};
    constexpr double ymax{1.0};

    constexpr int nprocs{3};

    int rank = 0;
    Grid gleft(nx, ny, ng, xmin, xmax, ymin, ymax, rank, nprocs);

    rank = 1;
    Grid gmiddle(nx, ny, ng, xmin, xmax, ymin, ymax, rank, nprocs);

    rank = 2;
    Grid gright(nx, ny, ng, xmin, xmax, ymin, ymax, rank, nprocs);

    std::cout << gleft << std::endl;
    std::cout << gmiddle << std::endl;
    std::cout << gright << std::endl;


}
