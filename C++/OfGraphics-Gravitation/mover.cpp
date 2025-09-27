#include "mover.h"

// ��� ���ϰ� cpp������ ������ ���� ->
// ���̺귯���� �����Ҷ� ��������� ���� ���� �� ������ �����ϰ� ���� �ڵ�� ����� �Ѿ
// �� �ȿ� �ҽ��ڵ� ĸ��ȭ ����

Mover::Mover(float x, float y, float m)
	: position(ofVec2f(x, y))
	, mass(m)
	, radius(m * 8)
	, velocity(ofVec2f(0, 0))
	, acceleration(ofVec2f(0, 0)){}

void Mover::applyForce(ofVec2f force)
{
	ofVec2f f = force / mass;		// ���� �޾Ƽ� ���ӵ� ���ϱ�
	acceleration += f;
}

void Mover::update()
{
	velocity += acceleration;		// ���ӵ��� �ӵ��� ����
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
