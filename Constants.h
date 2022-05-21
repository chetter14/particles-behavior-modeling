#pragma once

namespace Constants {
	
	constexpr int particlesNumber = 2;

	constexpr int boxMaxCoordX = 30;			//	in angstroms
	constexpr int boxMinCoordX = 0;				//	in angstroms
	constexpr int relativePosit = 3;

	constexpr int numberOfSteps = 701;

	constexpr double particleMass = 3.3e-27;
	constexpr double epsilon = 0.31e-2;			//	глубина потенциальной ямы в eV (Neon)
	constexpr double sigma = 2.74;				//	in angstroms (Neon)
	constexpr double epsilonR = sigma * 1.117;	//	r глубины потенциальной ямы, sigma * pow(56/24, 1/8) - из формулы
	constexpr double dt = 1e-14;
	
	constexpr double molarMass = 20.179e-3;		//  Neon (kg/mol)
	constexpr double R = 8.31;
	constexpr int temp = 50;					//	temperature in Kelvin
}



