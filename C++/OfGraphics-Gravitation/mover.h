#pragma once

#include "ofMain.h"

class Mover {
public:
	float mass;		// ����
	float radius;	// ������
	ofVec2f position;		// ��ġ
	ofVec2f velocity;		// �ӵ�
	ofVec2f acceleration;	// ���ӵ�

	// ofVec2f => 2���� ���� Ŭ����(3������ ofVec3f)

	Mover(float x, float y, float m);
	void applyForce(ofVec2f force);
	void update();
	void draw();
	void checkEdges();
};
