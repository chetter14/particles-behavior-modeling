#include <iostream>
#include "Particle.h"


double Particle::getEnergy() const 
{
    return potentEnergy + Constants::particleMass * pow(sqrt(vx * vx + vy * vy + vz * vz), 2) / 2;
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
    this->forceZ = 0;
}

void Particle::addForceX(double forceX)
{
    this->forceX += forceX;
}

void Particle::addForceY(double forceY)
{
    this->forceY += forceY;
}

void Particle::addForceZ(double forceZ)
{
    this->forceZ += forceZ;
}

std::ostream& operator<<(std::ostream& out, const Particle& particle)
{
    out << "X-axis coordinate: " << particle.x << ", X-axis speed: " << particle.vx << ",\n"
        << "Y-axis coordinate: " << particle.y << ", Y-axis speed: " << particle.vy << ",\n"
        << "Z-axis coordinate: " << particle.z << ", Z-axis speed: " << particle.vz << ",\n"
        << "ForceX: " << particle.forceX << ",\n"
        << "ForceY: " << particle.forceY << ",\n"
        << "ForceZ: " << particle.forceZ << ",\n";
    return out;
}
