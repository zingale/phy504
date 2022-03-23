#include <iostream>
#include "solar_system.H"

int main() {

    SolarSystem ss(2.0);

    ss.add_planet("alpha", 1.0);
    ss.add_planet("beta", 1.5, 0.1);
    ss.add_planet("gamma", 3.0, 0.24);

    // this generates an error
    //ss.add_planet("alpha", 2.0);

    std::cout << "period of alpha = " << ss.get_period("alpha") << std::endl;

}
