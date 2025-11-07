#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	paddle.init();
	balls.push_back(Ball());
	// balls.push_back(Ball());
	// balls.push_back(Ball());

	for (auto& ball : balls)
		ball.init(paddle.rect);

	moveLeft = moveRight = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	float dt = ofGetLastFrameTime();
	if (moveLeft) paddle.rect.x -= paddle.speed * dt;
	if (moveRight) paddle.rect.x += paddle.speed * dt;

	paddle.rect.x = ofClamp(paddle.rect.x, 0, ofGetWidth() - paddle.rect.width);
	for (auto& ball : balls) {
		if (!ball.moving) {
			ball.pos.x = paddle.rect.x + paddle.rect.width * 0.5;
		} else {
			int steps = 3;
			float subdt = dt / steps;
			for (int s = 0; s < steps; s++) {
				ball.pos += ball.vel * dt;

				// ceil
				if (ball.pos.y - ball.radius <= 0) {
					ball.pos.y = ball.radius;
					ball.vel.y *= -1;
					// play sound
				}
				// left wall
				if (ball.pos.x - ball.radius <= 0) {
					ball.pos.x = ball.radius;
					ball.vel.x *= -1;
					// play sound
				}
				// right wall
				if (ball.pos.x + ball.radius >= ofGetWidth()) {
					ball.pos.x = ofGetWidth() - ball.radius;
					ball.vel.x *= -1;
					// play sound
				}
				// bottom wall - for test
				if (ball.pos.y + ball.radius >= ofGetHeight()) {
					ball.pos.y = ofGetHeight() - ball.radius;
					ball.vel.y *= -1;
				}

				// paddle confliction
				
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	paddle.draw();

	for (auto& ball: balls)
		ball.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) moveLeft = true;
	if (key == OF_KEY_RIGHT) moveRight = true;
	if (key == ' ') {
		for (auto& ball : balls) {
			if (!ball.moving)
				launchBall(ball);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_LEFT) moveLeft = false;
	if (key == OF_KEY_RIGHT) moveRight = false;
}

/////////////////////////////////////////////////////////
//--------------------------------------------------------------
void ofApp::launchBall(Ball& ball) {
	if (ball.moving) return;

	float ang = ofRandom(-0.6f, 0.6f);
	ofVec2f v(ang, -1 + fabs(ang));
	v.normalize();
	ball.vel = v * ball.speed;
	ball.moving = true;
}

bool ofApp::collideWithBallAndRect(const ofRectangle& rect, const Ball& ball) {
	float closestX = ofClamp(ball.pos.x, rect.getLeft(), rect.getRight());
	float closestY = ofClamp(ball.pos.y, rect.getTop(), rect.getBottom());
	float dx = ball.pos.x - closestX;
	float dy = ball.pos.y - closestY;

	return (dx * dx + dy * dy) <= (ball.radius * ball.radius);
}
