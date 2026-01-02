#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(18, 18, 30);
}

//--------------------------------------------------------------
void ofApp::update(){
	nx = ofGetWidth() * 0.5;
	ny = ofGetHeight() * 0.5;

	angle *= 0.99;
	if (abs(angle) < 0.05)
		angle = 0;

	timing += angle;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(nx, ny);

	ofRotateDeg(timing);

	ofSetLineWidth(3);
	ofSetColor(0);
	ofDrawLine(barLen * -0.5, 0, barLen * 0.5, 0);

	drawBall(barLen * -0.5, 0, radius);
	drawBall(barLen * 0.5, 0, radius);
}

void ofApp::drawBall(float x, float y, float radius) {
	ofSetColor(127);
	ofDrawCircle(x, y, radius);
}

void ofApp::mouseScrolled(ofMouseEventArgs& args) {
	angle += args.scrollY;
}
