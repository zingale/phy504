#include <vector>
#include <cassert>

#include "planet.H"

struct SolarSystem {

    double star_mass;
    std::vector<Planet> planets;

    SolarSystem(const double mass)
       : star_mass{mass}
    {
        assert(mass > 0.0);
    }

    void add_planet(const std::string& name, const double a, const double e=0.0);

    const Planet* get_planet(const std::string& name);

    double get_period(const std::string& name);

};
