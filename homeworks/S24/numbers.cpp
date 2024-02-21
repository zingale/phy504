#include <iostream>
#include <vector>

int main( ) {

    std::vector<double> numbers{};

    bool input_valid{true};

    // read in numbers until the user enters a negative number

    while (input_valid) {
        double num{};
        std::cout << "Enter a number (negative to quit): ";
        std::cin >> num;
        if (num > 0.0) {
            numbers.push_back(num);
        } else {
            input_valid = false;
        }
    }

    // compute the sum

    double sum{};
    for (auto e : numbers) {
        sum += e;
    }

    std::cout << "the sum of the numbers is " << sum << std::endl;

}
