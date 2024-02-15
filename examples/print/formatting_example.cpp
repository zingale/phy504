#include <print>
#include <string>

int main() {

    double x{1.0};
    int i{2};
    std::string a{"example"};

    std::println("x = {}, i = {}, a = {}", x, i, a);

    std::println("x = {:5.2f}, i = {:03d}, a = {:^20}", x, i, a);

}
