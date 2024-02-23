#include <iostream>
#include <iomanip>
#include <sstream>
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

    std::ifstream data_file("planets.txt");

    if (! data_file.is_open()) {
        std::cout << "Error opening the file" << std::endl;
        return 1;
    }

    std::string line{};

    while (std::getline(data_file, line)) {
        Planet p;
        std::stringstream ss(line);
        ss >> p.name >> p.a >> p.e;
        planets.push_back(p);

    }

    data_file.close();

    for (auto p : planets) {
        std::cout << std::setw(12) << p.name
                  << std::setw(12) << p.a
                   << std::setw(12) << p.e << std::endl;
    }

}