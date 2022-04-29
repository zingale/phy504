#include <iostream>
#include <chrono>

#include "poisson2d.H"

const double TOL = 1.e-10;

int main() {

    auto start = std::chrono::system_clock::now();

    const int N = 128;

    auto p = Poisson(0.0, 1.0, 0.0, 1.0, N, N);

    p.set_source([] (double x, double y)
                 {return -2.0 * ((1.0 - 6.0 * x * x) * y * y * (1.0 - y * y) +
                                 (1.0 - 6.0 * y * y) * x * x * (1.0 - x * x));});

    p.set_xlo_bc(0.0);
    p.set_xhi_bc(0.0);
    p.set_ylo_bc(0.0);
    p.set_yhi_bc(0.0);

    p.solve(TOL);

    std::cout << "error = "
        << p.true_error([] (double x, double y)
                        {return (x*x - x*x*x*x) * (y*y*y*y - y*y);}) << std::endl;
    

    auto end = std::chrono::system_clock::now();

    std::cout << "time to solution: " << 
        std::chrono::duration_cast<std::chrono::milliseconds>(end -start).count() / 1000.0 << " s" << std::endl;


    p.write_solution("poisson.txt");
}
