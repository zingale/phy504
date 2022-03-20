#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

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

    Planet* get_planet(const std::string& name);

    double get_period(const std::string& name);

    //double get_perihelion_dist(const std::string& name);

    //double get_aphelion_dist(const std::string& name);    

};

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


int main() {

    SolarSystem ss(2.0);

    ss.add_planet("alpha", 1.0);
    ss.add_planet("beta", 1.5, 0.1);
    ss.add_planet("gamma", 3.0, 0.24);

    // this generates an error
    //ss.add_planet("alpha", 2.0);

    std::cout << "period of alpha = " << ss.get_period("alpha") << std::endl;
    
    // this is not a valid planet
    std::cout << "period of alpha = " << ss.get_period("delta") << std::endl;

}