#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <iostream>

struct Planet
{
    std::string name{};
    double a{};            // semi-major axis
    double e{};            // eccentricity
};

std::ostream& operator<< (std::ostream& os, const Planet& p);


#endif
