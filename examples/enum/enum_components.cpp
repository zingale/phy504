#include <iostream>
#include <vector>
#include <array>

enum field  {density, momentum, energy, ncomp};

int main() {

    std::array<std::array<double, ncomp>, 10> data{};

    for (auto & state : data) {
	state[density] = 1.0;
	state[momentum] = 2.0;
	state[energy] = 0.5 * state[momentum] * state[momentum] / state[density];
    }

    std::cout << "number of states = " << data.size() << std::endl;

    std::cout << data[3][density] << " "
	      << data[3][momentum] << " "
	      << data[3][energy] << std::endl;

}
