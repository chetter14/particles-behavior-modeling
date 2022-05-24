#include <iostream>
#include <random>
#include <cassert>
#include "Particle.h"

using namespace Constants;


void assignStartValues(Particle (&)[particlesNumber]);
void calcLennJonesPotent(Particle (&)[particlesNumber], int);
void moveParticle(Particle&);

int main()
{
	Particle particles[particlesNumber]{ };
	
	assignStartValues(particles);

	int gap = 50;
	double totalSystemEnergy;

	for (int i = 0; i < numberOfSteps; i++)
	{
		if (i % gap == 0)
			std::cout << "\nStep number: " << i << "\n\n";

		totalSystemEnergy = 0;

		for (int i = 0; i < particlesNumber; i++)
		{
			calcLennJonesPotent(particles, i);
			totalSystemEnergy += particles[i].getEnergy();
			moveParticle(particles[i]);
		}
		
		for (Particle& particle : particles)
			particle.nullifyForcesAndEnergy();									//	to clear potential energies and forces (set them to zero)

		if (i % gap == 0)
			std::cout << "System total energy - " << totalSystemEnergy << "\n\n";
	}
	
	return 0;
}


void assignStartValues(Particle (&particles)[particlesNumber])
{
	double velProb = sqrt(2 * R * temp / molarMass) / sqrt(2);

	//	for coordinates
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniformDist(boxMinCoord + relativePosit, boxMaxCoord - relativePosit);

	//	for velocities
	std::default_random_engine generator(rd());
	std::normal_distribution<double> normalDist(velProb, velProb * 0.3);

	for (int i = 0; i < particlesNumber; i++)
	{
		particles[i].setCoordX(uniformDist(gen));
		particles[i].setCoordY(uniformDist(gen));

		particles[i].setVelX(normalDist(generator) * (i % 2 == 0 ? -1 : 1) );
		particles[i].setVelY(normalDist(generator) * (i % 2 == 0 ? 1 : -1) );
	}

	for (int i = 0; i < particlesNumber; i++)
	{
		for (int j = i + 1; j < particlesNumber; j++)
		{
			double rx = abs(particles[i].getCoordX() - particles[j].getCoordX());
			double ry = abs(particles[i].getCoordY() - particles[j].getCoordY());
			assert(sqrt(rx * rx + ry * ry) > sigma, "Particles coordinates were generated too close");			//	validation that particles won't be in touch
		}
	}

	for (Particle& particle : particles)
		std::cout << "\n" << particle << "\n";
		

	std::cout << "\n";
}

//	partical motion
void moveParticle(Particle& particle)
{
	double newAccelX = particle.getForceX() / particleMass;
	double newAccelY = particle.getForceY() / particleMass;
	particle.setAccelX(newAccelX);
	particle.setAccelY(newAccelY);

	// std::cout << "\n" << "Adding to velocity - " << particle.getAccelX() * dt << "\n";

	double newVelX = particle.getVelX() + particle.getAccelX() * dt;						//	velocity in m/s
	double newVelY = particle.getVelY() + particle.getAccelY() * dt;

	double passedDistanceX = newVelX * dt * 1e10;
	double passedDistanceY = newVelY * dt * 1e10;

	double newCoordX = particle.getCoordX() + passedDistanceX + newAccelX * pow(dt, 2) / 2 * 1e10;		//	coordinates in angstroms
	double newCoordY = particle.getCoordY() + passedDistanceY + newAccelY * pow(dt, 2) / 2 * 1e10;

	if (newCoordX > boxMaxCoord)
	{
		if (newVelX > 0)									//	if velocity vector is directed on right, then change it direction on left
			newVelX = -newVelX;
		newCoordX = boxMaxCoord - abs(passedDistanceX / 2);
	}
	else if (newCoordX < boxMinCoord)
	{
		if (newVelX < 0)
			newVelX = -newVelX;
		newCoordX = boxMinCoord + abs(passedDistanceX / 2);
	}

	if (newCoordY > boxMaxCoord)
	{
		if (newVelY > 0)
			newVelY = -newVelY;
		newCoordY = boxMaxCoord - abs(passedDistanceY / 2);
	}
	else if (newCoordY < boxMinCoord)
	{
		if (newVelY < 0)
			newVelY = -newVelY;
		newCoordX = boxMinCoord + abs(passedDistanceY / 2);
	}
		
	particle.setVelX(newVelX);
	particle.setVelY(newVelY);
	particle.setCoordX(newCoordX);
	particle.setCoordY(newCoordY);
}

//	adjust forces of two particles (OX)
void calcParticleForceX(double r, double forceX, Particle& particle, Particle& particleToCompare)
{
	if (particle.getCoordX() > particleToCompare.getCoordX())
	{
		if (r < epsilonR)
			particle.addForceX(forceX);
		else
			particle.addForceX(-forceX);
	}
	else
	{
		if (r < epsilonR)
			particle.addForceX(-forceX);
		else
			particle.addForceX(forceX);
	}
}

//	adjust forces of two particles (OY)
void calcParticleForceY(double r, double forceY, Particle& particle, Particle& particleToCompare)
{
	if (particle.getCoordY() > particleToCompare.getCoordY())
	{
		if (r < epsilonR)
			particle.addForceY(forceY);
		else
			particle.addForceY(-forceY);
	}
	else
	{
		if (r < epsilonR)
			particle.addForceY(-forceY);
		else
			particle.addForceY(forceY);
	}
}

//	calculate the potential energy and forces between the specified particle and others
void calcLennJonesPotent(Particle (&particles)[particlesNumber], int particleIndex)
{
	for (int i = 0; i < particlesNumber; i++)
	{
		if (i != particleIndex)
		{
			double rx = abs(particles[particleIndex].getCoordX() - particles[i].getCoordX());		//	distance between them OX
			double ry = abs(particles[particleIndex].getCoordY() - particles[i].getCoordY());		//	distance between them OY

			double r = sqrt(rx * rx + ry * ry);

			double potentEnergy = abs(4 * epsilon * evToJoules			/* convert to Joules */
				* (pow(sigma / r, 12) - pow(sigma / r, 6)));

			particles[particleIndex].addPotentEnergy(potentEnergy);

			double force = abs(epsilon * evToJoules			/* convert to Joules */
				* (48 * pow(sigma, 12) * pow(r, -13) * 1e10 - 24 * pow(sigma, 6) * pow(r, -7) * 1e10));			//	force in Newtons

			double forceX = force * (rx / r);
			double forceY = force * (ry / r);

			calcParticleForceX(r, forceX, particles[particleIndex], particles[i]);					//	calculation on X-axis
			calcParticleForceY(r, forceY, particles[particleIndex], particles[i]);					//	calculation on Y-axis
		}
	}
}