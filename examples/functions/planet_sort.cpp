#include <iostream>
#include <iomanip>

#include <vector>
#include <algorithm>

struct Planet
{
    std::string name{};
    double a{};            // semi-major axis
    double e{};            // eccentricity
};

std::ostream& operator<< (std::ostream& os, const Planet& p) {

    os << std::setw(12) << p.name << " : ("
       << std::setw(8) << p.a << " , "
       << std::setw(8) << p.e << ")";

    return os;
}

int main() {

    std::vector<Planet> planets {{"Mercury",  0.3871, 0.2056},
                                 {"Venus",    0.7233, 0.0068},
                                 {"Earth",    1.0000, 0.0167},
                                 {"Mars",     1.5237, 0.0934},
                                 {"Jupiter",  5.2029, 0.0484},
                                 {"Saturn",   9.5370, 0.0539},
                                 {"Uranus",  19.189,  0.0473},
                                 {"Neptune", 30.070,  0.0086}};

    std::sort(planets.begin(), planets.end(),
              [] (const Planet& a, const Planet& b) {return a.e < b.e;});

    for (auto p : planets) {
        std::cout << p << std::endl;
    }

}