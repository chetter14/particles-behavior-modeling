#pragma once
#include "Constants.h"

class Particle {
	double x, y, z;		//	x, y and z coordinates in angstroms

	double vx, vy, vz;		//	velocity on OX, OY and OZ
	double ax, ay, az;		//	acceleration on OX, OY and OZ

	double potentEnergy;
	double kineticEnergy;

	double forceX, forceY, forceZ;

public:
	Particle() : x{ 0 }, y{ 0 }, z{ 0 }, vx{ 0 }, vy{ 0 }, vz{ 0 }, ax{ 0 }, ay{ 0 }, az{ 0 }, potentEnergy{ 0 },
		kineticEnergy{ 0 }, forceX{ 0 }, forceY{ 0 }, forceZ{ 0 } { }
	~Particle() { }

	void setCoordX(double x) { this->x = x; }
	double getCoordX() const { return x; }

	void setCoordY(double y) { this->y = y; }
	double getCoordY() const { return y; }

	void setCoordZ(double z) { this->z = z; }
	double getCoordZ() const { return z; }


	void setVelX(double vx) { this->vx = vx; }
	double getVelX() const { return vx; }

	void setVelY(double vy) { this->vy = vy; }
	double getVelY() const { return vy; }

	void setVelZ(double vz) { this->vz = vz; }
	double getVelZ() const { return vz; }


	void setAccelX(double ax) { this->ax = ax; }
	double getAccelX() const { return ax; }

	void setAccelY(double ay) { this->ay = ay; }
	double getAccelY() const { return ay; }

	void setAccelZ(double az) { this->az = az; }
	double getAccelZ() const { return az; }


	void setPotentialEnergy(double potentEnergy) { this->potentEnergy = potentEnergy; }
	double getPotentialEnergy() const { return potentEnergy; }

	void setKineticEnergy(double kinEnergy) { this->kineticEnergy = kinEnergy; }
	double getKineticEnergy() const { return kineticEnergy; }


	void setForceX(double forceX) { this->forceX = forceX; }
	double getForceX() const { return forceX; }

	void setForceY(double forceY) { this->forceY = forceY; }
	double getForceY() const { return forceY; }

	void setForceZ(double forceZ) { this->forceZ = forceZ; }
	double getForceZ() const { return forceZ; }


	double getEnergy() const;

	void addPotentEnergy(double);
	void nullifyForcesAndEnergy();

	void addForceX(double);
	void addForceY(double);
	void addForceZ(double);

	friend std::ostream& operator<< (std::ostream& out, const Particle& particle);
};