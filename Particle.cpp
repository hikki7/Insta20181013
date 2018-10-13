#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle() {

	this->radius = 300;
	this->deg = (int)(ofRandom(360) / 10) * 10;
	this->z = (int)(ofRandom(600) / 20) * 20 - 300;
}

//--------------------------------------------------------------
Particle::~Particle() {

}

//--------------------------------------------------------------
void Particle::Upate() {

	if (ofGetFrameNum() % 20 == 0) {

		int r = ofRandom(4);
		switch (r) {
		case 0:

			this->deg_step = 0.5;
			this->z_step = 0.0;
			break;
		case 1:

			this->deg_step = -0.5;
			this->z_step = 0.0;
			break;
		case 2:

			this->deg_step = 0.0;
			this->z_step = 1.0;
			break;
		case 3:

			this->deg_step = 0.0;
			this->z_step = -1.0;
			break;
		default:

			this->deg_step = 0.0;
			this->z_step = 0.0;
			break;
		}
	}

	if (this->z <= -300) {
		
		this->deg_step = 0.0;
		this->z_step = 1.0;
	}
	else if (this->z >= 300) {
		
		this->deg_step = 0.0;
		this->z_step = -1.0;
	}

	this->deg += this->deg_step;
	this->z += this->z_step;

	ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);
	this->logs.push_front(point);
	while (this->logs.size() > 45) { this->logs.pop_back(); }
}

//--------------------------------------------------------------
void Particle::Draw() {

	ofFill();
	ofDrawSphere(this->logs.front(), 3);

	ofNoFill();
	ofBeginShape();
	for (ofPoint& log : this->logs) {

		ofVertex(log);
	}
	ofEndShape();
}