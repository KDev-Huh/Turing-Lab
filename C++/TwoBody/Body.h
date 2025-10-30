#pragma once
#include "ofMain.h"
#include <vector>

class Body {
public:
	vector<pair<ofVec2f, ofColor>> trail;
	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;

	float mass;
	float radius;
	ofColor color;

	void setup(float x, float y, float m, ofColor c);
	void draw();
	void update();

	void attract(Body& body);
	void applyForce(ofVec2f force);
};
