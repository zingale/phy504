#include <iostream>
#include <vector>
#include <cmath>

#include "planet.H"
#include "solar_system.H"

Planet* SolarSystem::get_planet(const std::string& name) {

    Planet *planet_ptr{nullptr};

    for (auto p: planets) {
        if (p.name == name) {
            planet_ptr = &p;
            break;
        }
    }

    return planet_ptr;

}

void SolarSystem::add_planet(const std::string& name, const double a, const double e) {

    // make sure a planet with that name doesn't already exist
    // if the pointer returned here is not null, then the planet exists

    auto planet_ptr = get_planet(name);

    if (planet_ptr) {
        std::cout << "Error: planet already exists" << std::endl;
        return;
    }

    Planet p;
    p.name = name;
    p.a = a;
    p.e = e;

    planets.push_back(p);

}

double SolarSystem::get_period(const std::string& name) {

    double period = -1;

    auto planet_ptr = get_planet(name);

    double a{};
    if (planet_ptr) {
        a = planet_ptr->a;    // alternately, planet_ptr->a
        std::cout << "here: " << a << std::endl;
        period = std::sqrt(std::pow(a, 3.0) / star_mass);
    }

    return period;
}
