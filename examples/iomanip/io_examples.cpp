#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>

int main() {

    std::vector<double> numbers{M_PI, 0.001, 9.569299999e-6, 1234.5678, 1.25689354e10, 6.74e5};
    std::vector<std::string> words{"may", "the", "force", "be", "with", "you"};
    // default I/O

    for (auto &e : numbers) {
        std::cout << e << " "; 
    }
    std::cout << std::endl << std::endl;

    // now set precision -- note: this is sticky
    std::cout << std::setprecision(3);

    for (auto &e : numbers) {
        std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;

    // setfill and setw

    for (auto &e : numbers) {
        std::cout << std::setfill('*') << std::setw(10) << e << " ";
    }
    std::cout << std::endl << std::endl;

    

}

