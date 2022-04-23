#include <iostream>
#include <vector>
#include <cassert>

///
/// Solve the 1-d Poisson problem with Dirichlet BCs using Gauss-Seidel smoothing
///
class Poisson {

private:

    std::vector<double> x;
    std::vector<double> phi;
    std::vector<double> f;

    int N;

    double xmin;
    double xmax;

    double dx;

public:

    Poisson(double xmin_in, double xmax_in, int N_in)
        : xmin{xmin_in}, xmax{xmax_in}, N{N_in}, x(N_in, 0), phi(N_in, 0), f(N_in, 0)
    {

        // initialize the coordinates
        assert (xmax > xmin);

        dx = (xmax - xmin) / static_cast<double>(N-1);

        for (int i = 0; i < N; ++i) {
            x[i] = xmin + static_cast<double>(i) * dx;
        }

    }

    void set_left_bc(double val) {x[0] = val;}

    void set_right_bc(double val) {x[N-1] = val;}

    std::vector<double>& get_source() {
        return f;
    }

    std::vector<double>& get_phi() {
        return phi;
    }

    void smooth(int n_smooth) {

        // perform Gauss-Seidel smoothing

        // we only operate on the interior nodes

        for (int i = 0; i < n_smooth; ++i) {

            for (int j = 1; j < N-1; ++j) {
                x[j] = 0.5 * (x[j-1] + x[j+1] - dx * dx * f[j]);
            }
        }
    }

};