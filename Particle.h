#pragma once
#include "Constants.h"

class Particle {
	double x;		//	x coordinate in angstroms
	double vx;		//	velocity on x-axis
	double ax;		//	acceleration on x-axis

	double potentialEnergy;
	double kineticEnergy;

	double forceX;

public:
	Particle() : x{ 0 }, vx{ 0 }, ax{ 0 }, potentialEnergy{ 0 }, kineticEnergy{ 0 }, forceX{ 0 } { }
	~Particle() { }

	void setCoordX(double x) { this->x = x; }
	double getCoordX() const { return x; }

	void setVelX(double vx) { this->vx = vx; }
	double getVelX() const { return vx; }

	void setAccelX(double ax) { this->ax = ax; }
	double getAccelX() const { return ax; }

	void setPotentialEnergy(double potEnergy) { this->potentialEnergy = potEnergy; }
	double getPotentialEnergy() const { return potentialEnergy; }

	void setKineticEnergy(double kinEnergy) { this->kineticEnergy = kinEnergy; }
	double getKineticEnergy() const { return kineticEnergy; }

	void setForceX(double force) { this->forceX = force; }
	double getForceX() const { return forceX; }

	double getEnergy() const { return potentialEnergy + Constants::particleMass * pow(vx, 2) / 2; }

	friend std::ostream& operator<< (std::ostream& out, const Particle& particle);
};