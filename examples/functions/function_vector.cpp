#include <iostream>
#include <vector>

std::vector<double> f1(const std::vector<double>& v_in) {

    std::vector<double> v_out;

    for (auto e : v_in) {
        v_out.push_back(2.0 * e);
    }

    return v_out;

}

void f2(const std::vector<double>& v_in, std::vector<double>& v_out) {

    v_out.clear();

    for (auto e : v_in) {
        v_out.push_back(2.0 * e);
    }

}

std::vector<double>& f3(const std::vector<double>& v_in) {

    std::vector<double> v_out;

    for (auto e : v_in) {
        v_out.push_back(2.0 * e);
    }

    return v_out;

}

int main() {

    std::vector<double> v_old{0.0, 1.0, 2.0, 3.0, 4.0, 5.0};

    auto v_new1 = f1(v_old);

    for (auto e : v_new1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::vector<double> v_new2{};

    f2(v_old, v_new2);

    for (auto e : v_new2) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    auto v_new3 = f3(v_old);

    for (auto e : v_new3) {
        std::cout << e << " ";
    }
    std::cout << std::endl;


}