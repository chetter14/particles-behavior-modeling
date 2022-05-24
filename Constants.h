#pragma once

namespace Constants {
	
	constexpr int particlesNumber = 10;

	constexpr int boxMaxCoord = 50;				//	in angstroms
	constexpr int boxMinCoord = 0;				//	in angstroms
	constexpr int relativePosit = 4;

	constexpr int numberOfSteps = 801;

	constexpr double evToJoules = 1.60218e-19;	// eV to Joules

	constexpr double particleMass = 3.3e-26;
	constexpr double epsilon = 0.31e-2;			//	глубина потенциальной ямы в eV (Neon)
	constexpr double sigma = 2.74;				//	in angstroms (Neon)
	constexpr double epsilonR = sigma * 1.117;	//	r глубины потенциальной ямы, sigma * pow(56/24, 1/8) - из формулы
	constexpr double dt = 5e-15;
	
	constexpr double molarMass = 20.179e-3;		//  Neon (kg/mol)
	constexpr double R = 8.31;
	constexpr int temp = 50;					//	temperature in Kelvin
}



