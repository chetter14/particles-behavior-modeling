#pragma once

class Particle {
	double x;		//	x coordinate
	double vx;		//	velocity on x-axis
	double ax;		//	acceleration on x-axis

public:
	Particle() : x{0}, vx{0}, ax{0} { }
	~Particle() { }

	void setCoordX(double x) { this->x = x; }
	double getCoordX() const { return x; }

	void setVelX(double vx) { this->vx = vx; }
	double getVelX() const { return vx; }

	void setAccelX(double vx) { this->ax = ax; }
	double getAccelX() const { return ax; }
};