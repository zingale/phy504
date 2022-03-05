#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Planet
{
    std::string name{};
    double a{};            // semi-major axis
    double e{};            // eccentricity
};

int main() {

    std::vector<Planet> planets;

    std::ifstream data_file;

    data_file.open("planets.txt");

    if (! data_file.is_open()) {
        std::cout << "Error opening the file" << std::endl;
        return 1;
    }

    // this doesn't work as expected, since .eof() is only set _after_
    // a failed read

    while (! data_file.eof()) {
        Planet p;
        data_file >> p.name;
        data_file >> p.a;
        data_file >> p.e;

        planets.push_back(p);
    }

    data_file.close();

    for (auto p : planets) {
        std::cout << std::setw(12) << p.name << std::setw(12) << p.a << std::setw(12) << p.e << std::endl;
    }

}
