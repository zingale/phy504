#include <iostream>
#include <vector>
#include <cmath>

#include "planet.H"
#include "solar_system.H"

void SolarSystem::add_planet(const std::string& name, const double a, const double e) {

    // make sure a planet with that name doesn't already exist

    bool found = false;
    for (auto p : planets) {
        if (p.name == name) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Error: planet already exists" << std::endl;
        return;
    }

    Planet p;
    p.name = name;
    p.a = a;
    p.e = e;

    planets.push_back(p);

}

Planet* SolarSystem::get_planet(const std::string& name) {

    Planet *planet_ptr = nullptr;

    for (auto p: planets) {
        if (p.name == name) {
            planet_ptr = &p;
            break;
        }
    }

    return planet_ptr;

}

double SolarSystem::get_period(const std::string& name) {

    double period = -1;

    Planet* planet_ptr = get_planet(name);

    if (planet_ptr) {
        double a = (*planet_ptr).a;    // alternately, planet_ptr->a

        period = std::sqrt(std::pow(a, 3) / star_mass);   
    }

    return period;
}
