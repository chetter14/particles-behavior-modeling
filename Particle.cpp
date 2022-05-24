#include <iostream>
#include "Particle.h"


double Particle::getEnergy() const 
{
    return potentEnergy + Constants::particleMass * pow(sqrt(vx * vx + vy * vy), 2) / 2;
}

void Particle::addPotentEnergy(double potentEnergy)
{
    this->potentEnergy += potentEnergy;
}

void Particle::nullifyForcesAndEnergy()
{
    this->potentEnergy = 0;
    this->forceX = 0;
    this->forceY = 0;
}

void Particle::addForceX(double forceX)
{
    this->forceX += forceX;
}

void Particle::addForceY(double forceY)
{
    this->forceY += forceY;
}

std::ostream& operator<<(std::ostream& out, const Particle& particle)
{
    out << "X-axis coordinate: " << particle.x << ", X-axis speed: " << particle.vx << ",\n"
        << "Y-axis coordinate: " << particle.y << ", Y-axis speed: " << particle.vy << ",\n"
        << "ForceX: " << particle.forceX << ",\n"
        << "ForceY: " << particle.forceY << ",\n";
    return out;
}
