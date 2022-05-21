#include <iostream>
#include <random>
#include <ctime>
#include "Particle.h"
#include "Constants.h"


using namespace Constants;


void assignStartValues(Particle (&)[particlesNumber]);

int main()
{
	//	below for particlesNumber = 2

	Particle particles[particlesNumber];
		
	assignStartValues(particles);

	for (int i = 1; i < particlesNumber; i++)
	{
		for (int j = 0; j < i; j++)
		{
			
		}
	} 

	return 0;
}


void assignStartValues(Particle (&particles)[particlesNumber])
{
	double velProb = sqrt(2 * R * temp / molarMass);

	srand(time(NULL));

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(velProb, velProb * 0.5);

	for (int i = 0; i < particlesNumber; i++)
	{
		particles[i].setCoordX(rand() % 10 - 10);		//	logic for initial coordinates
		std::cout << particles[i].getCoordX() << "\n";

		particles[i].setVelX(distribution(generator) * (i % 2 == 0 ? -1 : 1) );
		std::cout << std::scientific << particles[i].getVelX() << "\n";
	}

}