#pragma once

namespace Constants {
	
	constexpr int particlesNumber = 2;

	constexpr int boxMaxCoordX = 10;			//	in angstrems
	constexpr int boxMinCoordX = -10;			//	in angstrems

	constexpr int numberOfSteps = 175;

	constexpr double particleMass = 1.67e-27;
	constexpr double epsilon = 0.25;			//	глубина потенциальной ямы в eV
	constexpr double sigma = 10;				//	in angstrems (энергия взаимодействия = 0)
	constexpr double dt = 6e-15;				
	
	constexpr double molarMass = 4.002e-3;			//  Helium (kg/mol)
	constexpr double R = 8.31;
	constexpr int temp = 100;					//	temperature in Kelvin
}



