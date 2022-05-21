#include <iostream>
#include "Particle.h"


using namespace Constants;

std::ostream& operator<<(std::ostream& out, const Particle& particle)
{
    out << "X-axis coordinate: " << particle.x << ", X-axis speed: " << particle.vx << ",\n"
        << "ForceX: " << particle.forceX << ",\n";
    return out;
}
