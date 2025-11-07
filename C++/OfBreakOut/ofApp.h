#pragma once

#include "ofMain.h"
#include <vector>

struct Paddle {
	ofRectangle rect;
	float speed = 360.f;

	void init() {
		rect.width = 120;
		rect.height = 16;
		rect.x = ofGetWidth() * 0.5 - rect.width * 0.5;
		rect.y = ofGetHeight() - 40;
	}

	void draw() {
		ofPushMatrix();
		ofFill();
		ofSetColor(255);
		ofDrawRectRounded(rect, 8);
		ofNoFill();
		ofSetColor(0);
		ofSetLineWidth(1);
		ofDrawRectRounded(rect, 8);
		ofPopMatrix();
	}
};

struct Ball {
	ofVec2f pos;
	ofVec2f vel;
	float radius = 9;
	float speed = 300;
	bool moving = false;

	void init(const ofRectangle& rect) {
		float x = rect.x + rect.width * 0.5;
		float y = rect.y - 2 - radius;

		pos.set(x, y);
		vel.set(0, -1);

		moving = false;
	}

	void draw() const {
		ofPushMatrix();
		ofSetCircleResolution(32);		// ¿ø ¸¸µé¶§ Âï´Â Á¡ÀÇ °¹¼ö
		ofFill();
		ofSetColor(255);
		ofDrawCircle(pos, radius);

		ofNoFill();
		ofSetColor(0);
		ofSetLineWidth(1);
		ofDrawCircle(pos, radius);
		ofPopMatrix();
	}
};

class ofApp : public ofBaseApp{

	public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void launchBall(Ball& ball);
	bool collideWithBallAndRect(const ofRectangle & rect, const Ball & ball);

	Paddle paddle;
	bool moveLeft;
	bool moveRight;

	// Ball ball;
	std::vector<Ball> balls;
};
