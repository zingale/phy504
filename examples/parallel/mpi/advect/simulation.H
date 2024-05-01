#ifndef SIMULATION_H
#define SIMULATION_H

namespace domain {
    constexpr int nx{128};
    constexpr int ny{128};
    constexpr int ng{1};

    constexpr double xmin{0.0};
    constexpr double xmax{1.0};
    constexpr double ymin{0.0};
    constexpr double ymax{1.0};
}

namespace simulation {
    constexpr double C{0.4};
    constexpr double tmax{1.0};
    constexpr double u{1.0};
    constexpr double v{1.0};
}

#endif
