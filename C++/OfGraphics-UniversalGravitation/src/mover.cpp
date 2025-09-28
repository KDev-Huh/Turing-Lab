#include "mover.h"

Mover::Mover(float x, float y, float m)
	: position(ofVec2f(x, y))
	, velocity(ofVec2f(0, 0))
	, acceleration(ofVec2f(0, 0))
	, mass(m)
	, radius(m * 8) { }

void Mover::applyForce(ofVec2f force)
{
	acceleration += force / mass;
}

void Mover::draw()
{
	ofFill();
	ofSetColor(127);
	ofDrawCircle(position, radius);

	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(1);
	ofDrawCircle(position, radius);
}

void Mover::update()
{
	velocity += acceleration;
	position += velocity;
}

void Mover::checkEdges()
{
	int w = ofGetWidth();
	int h = ofGetHeight();

	float& x = position.x;
	float& y = position.y;

	// bottom
	if (h < y + radius) {
		y = h - radius;
		velocity.y *= -1;
	}

	// left
	if (0 > x - radius) {
		x = radius;
		velocity.x *= -1;
	}

	// right
	if (w < x + radius) {
		x = w - radius;
		velocity.x *= -1;
	}
}
