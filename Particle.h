#pragma once
#include "Constants.h"

class Particle {
	double x, y;		//	x and y coordinates in angstroms

	double vx, vy;		//	velocity on OX and OY
	double ax, ay;		//	acceleration on OX and OY

	double potentEnergy;
	double kineticEnergy;

	double forceX, forceY;

public:
	Particle() : x{ 0 }, y{ 0 }, vx{ 0 }, vy{ 0 }, ax{ 0 }, ay{ 0 }, potentEnergy{ 0 },
		kineticEnergy{ 0 }, forceX{ 0 }, forceY{ 0 } { }
	~Particle() { }

	void setCoordX(double x) { this->x = x; }
	double getCoordX() const { return x; }

	void setCoordY(double y) { this->y = y; }
	double getCoordY() const { return y; }


	void setVelX(double vx) { this->vx = vx; }
	double getVelX() const { return vx; }

	void setVelY(double vy) { this->vy = vy; }
	double getVelY() const { return vy; }


	void setAccelX(double ax) { this->ax = ax; }
	double getAccelX() const { return ax; }

	void setAccelY(double ay) { this->ay = ay; }
	double getAccelY() const { return ay; }


	void setPotentialEnergy(double potentEnergy) { this->potentEnergy = potentEnergy; }
	double getPotentialEnergy() const { return potentEnergy; }

	void setKineticEnergy(double kinEnergy) { this->kineticEnergy = kinEnergy; }
	double getKineticEnergy() const { return kineticEnergy; }


	void setForceX(double forceX) { this->forceX = forceX; }
	double getForceX() const { return forceX; }

	void setForceY(double forceY) { this->forceY = forceY; }
	double getForceY() const { return forceY; }


	double getEnergy() const;

	void addPotentEnergy(double);
	void nullifyForcesAndEnergy();

	void addForceX(double);
	void addForceY(double);

	friend std::ostream& operator<< (std::ostream& out, const Particle& particle);
};