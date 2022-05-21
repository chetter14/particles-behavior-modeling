#include <iostream>
#include <random>
#include <cassert>
#include "Particle.h"


using namespace Constants;


void assignStartValues(Particle (&)[particlesNumber]);
void calculLennJonesPotent(Particle (&)[particlesNumber]);
void moveParticle(Particle&);

int main()
{
	//	below for particlesNumber = 2

	Particle particles[particlesNumber]{ };
	
	assignStartValues(particles);

	int gap = 50;
	double totalSystemEnergy;

	for (int i = 0; i < numberOfSteps; i++)
	{
		if (i % gap == 0)
			std::cout << "\nStep number: " << i << "\n\n";

		totalSystemEnergy = 0;

		for (Particle& particle : particles)
		{
			calculLennJonesPotent(particles);
			totalSystemEnergy += particle.getEnergy();
			moveParticle(particle);

			if (i % gap == 0)
				std::cout << particle << "\n";
		}

		if (i % gap == 0)
			std::cout << "System total energy - " << totalSystemEnergy << "\n\n";
	}
	
	return 0;
}


void assignStartValues(Particle (&particles)[particlesNumber])
{
	double velProb = sqrt(2 * R * temp / molarMass);

	//	for coordinates
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniformDist(boxMinCoordX + relativePosit, boxMaxCoordX - relativePosit);

	//	for velocities
	std::default_random_engine generator(rd());
	std::normal_distribution<double> normalDist(velProb, velProb * 0.3);

	for (int i = 0; i < particlesNumber; i++)
	{
		particles[i].setCoordX(uniformDist(gen));
		particles[i].setVelX(normalDist(generator) * (i % 2 == 0 ? -1 : 1) );
	}

	for (int i = 0; i < particlesNumber; i++)
	{
		for (int j = i + 1; j < particlesNumber; j++)
		{
			double r = abs(particles[i].getCoordX() - particles[j].getCoordX());
			assert(r > sigma, "Particles coordinates were generated too close");			//	validation that particles won't be in touch
		}
	}

	for (const Particle& particle: particles)
		std::cout << "\n" << particle << "\n";

	std::cout << "\n";
}

//	partical motion
void moveParticle(Particle& particle)
{
	double newAccelX = particle.getForceX() / particleMass;
	particle.setAccelX(newAccelX);

	// std::cout << "\n" << "Adding to velocity - " << particle.getAccelX() * dt << "\n";

	double newVelX = particle.getVelX() + particle.getAccelX() * dt;						//	velocity in m/s

	double passedDistance = newVelX * dt * 1e10;
	double newCoordX = particle.getCoordX() + passedDistance + newAccelX * pow(dt, 2) / 2 * 1e10;		//	coordinates in angstroms

	if (newCoordX > boxMaxCoordX)
	{
		newVelX = -newVelX;
		newCoordX = boxMaxCoordX - abs(passedDistance / 2);
	}
	else if (newCoordX < boxMinCoordX)
	{
		newVelX = -newVelX;
		newCoordX = boxMinCoordX + abs(passedDistance / 2);
	}
		
	particle.setVelX(newVelX);
	particle.setCoordX(newCoordX);

	// std::cout << particle << "\n";
}

//	calculate the potential energy and forces between all the particles
void calculLennJonesPotent(Particle (&particles)[particlesNumber])
{
	for (int i = 1; i < particlesNumber; i++)
	{
		for (int j = 0; j < i; j++)
		{
			double particleOneCoordX = particles[i].getCoordX();
			double particleTwoCoordX = particles[j].getCoordX();
			double r = abs(particleOneCoordX - particleTwoCoordX);					//	distance between 

			double potentEnergy = abs(4 * epsilon * 1.60218e-19			/* convert to Joules */
				* (pow(sigma / r, 12) - pow(sigma / r, 6)));

			particles[j].setPotentialEnergy(potentEnergy);
			particles[i].setPotentialEnergy(potentEnergy);

			double force = abs(epsilon * 1.60218e-19			/* convert to Joules */
				* (48 * pow(sigma, 12) * pow(r, -13) * 1e10 - 24 * pow(sigma, 6) * pow(r, -7) * 1e10));			//	force in Newtons

			if (particleOneCoordX > particleTwoCoordX)
			{
				if (r < epsilonR)
				{
					particles[i].setForceX(force);
					particles[j].setForceX(-force);
				}
				else 
				{
					particles[i].setForceX(-force);
					particles[j].setForceX(force);
				}
			}
			else
			{
				if (r < epsilonR)
				{
					particles[i].setForceX(-force);
					particles[j].setForceX(force);
				}
				else
				{
					particles[i].setForceX(force);
					particles[j].setForceX(-force);
				}
			}		
		}
	}
}