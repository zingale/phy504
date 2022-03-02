#include <iostream>
#include <vector>
#include <cmath>

struct Planet {
    std::string name{};
    double a{}; // semi-major axis
    double e{}; // eccentricity
    double P{};
};

int main() {

    std::vector<Planet> planets{{"Mercury", 0.3871, 0.2056},
                                {"Venus", 0.7233, 0.0068},
                                {"Earth", 1.0000, 0.0167},
                                {"Mars", 1.5237, 0.0934},
                                {"Jupiter", 5.2029, 0.0484},
                                {"Saturn", 9.5370, 0.0539},
                                {"Uranus", 19.189, 0.0473},
                                {"Neptune", 30.070, 0.0086}};
    for (auto &p : planets) {
        p.P = std::sqrt(std::pow(p.a, 3));
    }

    for (auto p : planets) {
        std::cout << p.P << std::endl;
    }
    
}