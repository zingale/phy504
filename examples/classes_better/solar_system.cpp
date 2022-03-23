#include <iostream>
#include <vector>
#include <cmath>

#include "planet.H"
#include "solar_system.H"

int SolarSystem::get_planet(const std::string& name, Planet& p_return) {

    // istatus = 1 means the planet doesn't exist

    int istatus = 1;

    for (auto p: planets) {
        if (p.name == name) {
            p_return.name = p.name;
            p_return.a = p.a;
            p_return.e = p.e;
            istatus = 0;
            break;
        }
    }

    return istatus;

}

void SolarSystem::add_planet(const std::string& name, const double a, const double e) {

    // make sure a planet with that name doesn't already exist
    // if the pointer returned here is not null, then the planet exists

    Planet p_check;
    int istatus = get_planet(name, p_check);

    if (! istatus) {
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

    Planet p;
    int istatus = get_planet(name, p);

    if (! istatus) {
        period = std::sqrt(std::pow(p.a, 3.0) / star_mass);
    }

    return period;
}
