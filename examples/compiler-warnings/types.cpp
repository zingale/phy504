#include <array>

int main() {

    std::array<double, 10> x;

    for (int i = 0; i < x.size(); ++i) {
	x[i] = i;
    }

}
