#pragma once

#include "ofMain.h"

class Mover {
public:
	float mass;
	float radius;

	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;

	Mover(float x, float y, float r);
	void draw();
	void update();
	void checkEdges();
	void applyForce(ofVec2f force);
};
