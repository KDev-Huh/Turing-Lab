#pragma once

#include "ofMain.h"

class Mover {
public:
	float mass;		// 질량
	float radius;	// 반지름
	ofVec2f position;		// 위치
	ofVec2f velocity;		// 속도
	ofVec2f acceleration;	// 가속도

	// ofVec2f => 2차원 백터 클래스(3차원은 ofVec3f)

	Mover(float x, float y, float m);
	void applyForce(ofVec2f force);
	void update();
	void draw();
	void checkEdges();
};
