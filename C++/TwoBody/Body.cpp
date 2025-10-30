#include "Body.h"

void Body::setup(float x, float y, float m, ofColor c) {
	position = ofVec2f(x, y);
	mass = m;
	color = c;
	radius = sqrt(m) * 2;
	velocity = ofVec2f();
	acceleration = ofVec2f();
}
void Body::draw() {
	ofFill();
	ofSetColor(color);
	ofDrawCircle(position, radius);

	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(1);
	ofDrawCircle(position, radius);

	ofNoFill();
	ofBeginShape();
	for (auto& dot : trail) {
		ofSetColor(dot.second);
		ofVertex(dot.first);
	}
	ofEndShape();
}
void Body::update() {
	velocity += acceleration;
	position += velocity;
	acceleration *= 0.f;

	trail.push_back({ position, ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255))});
	if (trail.size() > 1000) trail.erase(trail.begin());
}

void Body::applyForce(ofVec2f force) {
	ofVec2f f = force / mass;
	acceleration += f;
}

void Body::attract(Body& body) {
	const float G = 1.f;
	ofVec2f force = position - body.position;
	float distance = force.length();
	distance = ofClamp(distance, 5, 25);	// distance มฆวั
	float strength = (G *mass * body.mass) / (distance * distance);
	force.scale(strength);

	body.applyForce(force);
}
