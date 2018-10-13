#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle();
	void Upate();
	void Draw();

private:

	float radius;
	float deg;
	float z;

	float deg_step;
	float z_step;

	std::deque<ofPoint> logs;
};