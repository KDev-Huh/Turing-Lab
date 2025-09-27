#include "mover.h"

// 헤더 파일과 cpp파일을 나누는 이유 ->
// 라이브러리로 전달할때 헤더파일을 보고 개발 및 컴파일 진행하고 실제 코드는 기계어로 넘어감
// 즉 안에 소스코드 캡슐화 가능

Mover::Mover(float x, float y, float m)
	: position(ofVec2f(x, y))
	, mass(m)
	, radius(m * 8)
	, velocity(ofVec2f(0, 0))
	, acceleration(ofVec2f(0, 0)){}

void Mover::applyForce(ofVec2f force)
{
	ofVec2f f = force / mass;		// 힘을 받아서 가속도 구하기
	acceleration += f;
}

void Mover::update()
{
	velocity += acceleration;		// 가속도를 속도에 더함
	position += velocity;
	acceleration *= 0;
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

void Mover::checkEdges()
{
	float w = ofGetWidth();
	float h = ofGetHeight();

	int x = position.x;
	int y = position.y;
	if (0 <= x && x <= 200) {
		float newForce = (x - 200) * 0.01;
		applyForce(ofVec2f(newForce, 0));
	} else if (w - 200 <= y && y <= w) {
		float newForce = ((w - 200) - x) * 0.01;
		applyForce(ofVec2f(newForce, 0));
	}
	if (h - 200 <= y && y <= h) {
		float newForce = ((h - 200) - y) * 0.01;
		applyForce(ofVec2f(0, newForce));
	}

	const float FF = 200.f;
	const float FC = 0.5f;

	float distL = position.x - radius;
	float distR = ofGetWidth() - (position.x + radius);
	float distB = ofGetHeight() - (position.y + radius);

	distL = (distL == 0) ? 1 : distL;
	distR = (distR == 0) ? 1 : distR;
	distB = (distB == 0) ? 1 : distB;

	if (distR > ofGetWidth() - FF) {
		velocity.x -= FC * (1 / distR);
	}
	if (distL < FF) {
		velocity.x += FC * (1 / distL);
	}
	if (position.y + radius > ofGetHeight()) {
		position.y = ofGetHeight() - radius;
		velocity.y *= -1;
	}
}
