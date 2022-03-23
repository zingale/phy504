#include <iostream>
#include <vector>
#include <cmath>

#include "planet.H"
#include "solar_system.H"

void SolarSystem::add_planet(const std::string& name, const double a, const double e) {

    // make sure a planet with that name doesn't already exist
    // if the pointer returned here is not null, then the planet exists

    for (auto p : planets) {
        if (name == p.name) {
            std::cout << "planet already exists" << std::endl;
            return;
        }
    }

    Planet p;
    p.name = name;
    p.a = a;
    p.e = e;

    planets.push_back(p);

}

void SolarSystem::print_planets() {

    for (auto p : planets) {
        std::cout << p << std::endl;
    }
}