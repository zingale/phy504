#ifndef POISSON_H
#define POISSON_H

#include <cassert>
#include <cmath>
#include <limits>
#include <fstream>
#include <iomanip>
#include <functional>
#include <vector>

#include "array.H"

///
/// Solve the 1-d Poisson problem on a node-centered finite-difference
/// grid with Dirichlet BCs using Gauss-Seidel smoothing
///
class Poisson {

private:

    double xmin;
    double xmax;

    double ymin;
    double ymax;

    int nx;
    int ny;

    std::vector<double> x;
    std::vector<double> y;

    Array phi;
    Array f;

    double dx;
    double dy;

public:

    Poisson(double xmin_in, double xmax_in,
            double ymin_in, double ymax_in,
            int nx_in, int ny_in)
        : xmin{xmin_in}, xmax{xmax_in}, ymin{ymin_in}, ymax{ymax_in},
          nx{nx_in}, ny{ny_in},
          x(nx_in, 0), y(ny_in, 0),
          phi(nx_in, ny_in, 0), f(nx_in, ny_in, 0)
    {

        // initialize the coordinates
        assert (xmax > xmin);
        assert (ymax > ymin);

        dx = (xmax - xmin) / static_cast<double>(nx-1);
        dy = (ymax - ymin) / static_cast<double>(ny-1);

        for (int i = 0; i < nx; ++i) {
            x[i] = xmin + static_cast<double>(i) * dx;
        }

        for (int j = 0; j < ny; ++j) {
            y[j] = ymin + static_cast<double>(j) * dy;
        }

    }

    ///
    /// set the -x Dirichlet boundary condition
    ///
    void set_xlo_bc(double val) {
        for (int j = 0; j < ny; ++j) {
            phi(0, j) = val;
        }
    }

    ///
    /// set the +x Dirichlet boundary condition
    ///
    void set_xhi_bc(double val) {
        for (int j = 0; j < ny; ++j) {
            phi(nx-1, j) = val;
        }
    }

    ///
    /// set the -y Dirichlet boundary condition
    ///
    void set_ylo_bc(double val) {
        for (int i = 0; i < nx; ++i) {
            phi(i, 0) = val;
        }
    }

    ///
    /// set the +y Dirichlet boundary condition
    ///
    void set_yhi_bc(double val) {
        for (int i = 0; i < nx; ++i) {
            phi(i, ny-1) = val;
        }
    }

    ///
    /// set the source term, f, in L phi = f
    ///
    void set_source(std::function<double(double, double)> func) {

        for (int i = 0; i < nx; ++i) {
            for (int j = 0; j < ny; ++j) {
                f(i,j) = func(x[i], y[j]);
            }
        }
    }

    ///
    /// return the number of points in x
    ///
    int nx_pts() {return nx;}

    ///
    /// return the number of points in y
    ///
    int ny_pts() {return ny;}

    ///
    /// return the x coordinate vector
    ///
    const std::vector<double>& xc() {return x;}

    ///
    /// return the y coordinate vector
    ///
    const std::vector<double>& yc() {return y;}

    ///
    /// return the source vector
    ///
    Array& get_source() {
        return f;
    }

    ///
    /// return the solution vector
    ///
    Array& get_phi() {
        return phi;
    }

    ///
    /// do Gauss-Seidel smoothing for n_smooth iterations
    ///
    void smooth(int n_smooth) {

        // perform Gauss-Seidel smoothing

        // we only operate on the interior nodes

        double fac = dx * dx * dy * dy / (dx * dx + dy * dy);
        double dx2i = 1.0 / (dx * dx);
        double dy2i = 1.0 / (dy * dy);

        for (int n = 0; n < n_smooth; ++n) {

            for (int i = 1; i < nx-1; ++i) {
                for (int j = 1; j < ny-1; ++j) {
                    phi(i,j) = 0.5 * fac * (dx2i * (phi(i-1,j) + phi(i+1,j)) +
                                            dy2i * (phi(i,j-1) + phi(i,j+1)) - f(i,j));
                }
            }
        }
    }

    ///
    /// solve the Poisson problem via relaxation until the residual
    /// norm is tol compared to the source norm
    ///
    void solve(double tol) {

        double err = std::numeric_limits<double>::max();

        double source_norm = norm(f);

        while (err > tol) {

            smooth(10);

            double r_norm = norm(residual());

            if (source_norm != 0.0) {
                err = r_norm / source_norm;
            } else {
                err = r_norm;
            }
        }

    }

    ///
    /// compute the residual
    ///
    Array residual() {
        Array r(nx, ny, 0);

        for (int i = 1; i < nx-1; ++i) {
            for (int j = 1; j < ny-1; ++j) {
                r(i,j) = f(i,j)
                    - (phi(i+1,j) - 2.0 * phi(i,j) + phi(i-1,j)) / (dx * dx)
                    - (phi(i,j+1) - 2.0 * phi(i,j) + phi(i,j-1)) / (dy * dy);
            }
        }

        return r;

    }

    ///
    /// given a vector e on our grid, return the L2 norm
    ///
    double norm(const Array& e) {
        double l2{0.0};

        for (int i = 0; i < nx; ++i) {
            for (int j = 0; j < ny; ++j) {
                l2 += e(i,j) * e(i,j);
            }
        }
        l2 = std::sqrt(dx * dy * l2);

        return l2;
    }

    ///
    /// output the solution to file fname
    ///
    void write_solution(const std::string& fname) {
        auto of = std::ofstream(fname);

        for (int i = 0; i < nx; ++i) {
            for (int j = 0; j < ny; ++j) {
                of << std::setw(20) << x[i] << " "
                   << std::setw(20) << y[j] << " "
                   << std::setw(20) << phi(i,j) << std::setw(20) << std::endl;
            }
            of << std::endl;
        }
    }

};
#endif
