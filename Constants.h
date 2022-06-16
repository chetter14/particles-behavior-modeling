#pragma once

namespace Constants {
	
	constexpr int particlesNumber = 2;

	constexpr int boxMaxCoord = 7;				//	in angstroms
	constexpr int boxMinCoord = 0;					//	in angstroms
	constexpr int relativePosit = 0.5;

	constexpr double volume = (boxMaxCoord - boxMinCoord) * (boxMaxCoord - boxMinCoord) * (boxMaxCoord - boxMinCoord) 
		* 1e-30;	//	volume of the box ( 1e-30 - because we convert to meters)

	constexpr int numberOfSteps = 24'000'001;

	constexpr double evToJoules = 1.60218e-19;	// eV to Joules

	constexpr double particleMass = 3.3e-26;
	constexpr double epsilon = 0.31e-2;			//	глубина потенциальной ямы в eV (Neon)
	constexpr double sigma = 2.74;				//	in angstroms (Neon)
	constexpr double epsilonR = sigma * 1.117;	//	r глубины потенциальной ямы, sigma * pow(56/24, 1/8) - из формулы
	constexpr double dt = 4.5e-19;
	
	constexpr double molarMass = 20.1797e-3;		//  Neon (kg/mol)
	constexpr double R = 8.31;
	constexpr int temp = 50;					//	temperature in Kelvin
}

