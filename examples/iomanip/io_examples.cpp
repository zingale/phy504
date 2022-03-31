#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>

int main() {

    std::vector<double> numbers{M_PI, 0.001, 9.569299999e-6, 1234.5678, 1.25689354e10, 6.74e5};
    std::vector<std::string> words{"may", "the", "force", "be", "with", "you"};
    
    // save the current I/O flags

    std::ios cout_state(nullptr);
    cout_state.copyfmt(std::cout);

    // default I/O

    std::cout << "default I/O" << std::endl;

    for (auto &e : numbers) {
        std::cout << e << " "; 
    }
    std::cout << std::endl << std::endl;

    // scientific

    std::cout << "scientific" << std::endl;

    std::cout << std::scientific; 
    for (auto &e : numbers) {
        std::cout << e << " "; 
    }
    std::cout << std::endl << std::endl;

    // fixed

    std::cout << "fixed" << std::endl;

    std::cout << std::fixed; 
    for (auto &e : numbers) {
        std::cout << e << " "; 
    }
    std::cout << std::endl << std::endl;

    // defaultfloat

    std::cout << "defaultfloat" << std::endl;

    std::cout << std::defaultfloat;
    for (auto &e : numbers) {
        std::cout << e << " "; 
    }
    std::cout << std::endl << std::endl;

    // now set precision -- note: this is sticky

    std::cout << "setprecision" << std::endl;

    std::cout << std::setprecision(3);

    for (auto &e : numbers) {
        std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;

    // setfill and setw

    std::cout << "setfill / setw" << std::endl;

    std::cout << std::setfill('*');

    for (auto &e : numbers) {
        std::cout << std::setw(10) << e << " ";
    }
    std::cout << std::endl << std::endl;

    // reset

    std::cout << "reset" << std::endl;

    std::cout.copyfmt(cout_state);

    for (auto &e : numbers) {
        std::cout << e << " "; 
    }
    std::cout << std::endl << std::endl;

    // now let's output stuff in columns -- we are assuming that words and numbers are the same length

    assert(words.size() == numbers.size());

    for (int i = 0; i < words.size(); ++i) {
        std::cout << std::setw(10) << words[i] << " " << std::setw(15) << numbers[i] << std::endl;
    }


    std::cout << "left" << std::endl;

    assert(words.size() == numbers.size());

    for (int i = 0; i < words.size(); ++i) {
        std::cout << std::setw(10) << std::left << words[i] << " " << std::setw(15) << std::right << numbers[i] << std::endl;
    }

}

