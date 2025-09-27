#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	float w = ofGetWidth();
	float h = ofGetHeight();
	movers.push_back(Mover(w * 0.25, h * 0.25, 8));
	movers.push_back(Mover(w * 0.5, h * 0.25, 5));
	movers.push_back(Mover(w * 0.75, h * 0.25, 2));
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto& mover : movers) {
		mover.applyForce(ofVec2f(0, 0.2));
		mover.update();
		mover.checkEdges();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetCircleResolution(60);		// �� �ѷ��� �ִ� �� ���� �� ���� ������ �մ´�.
	ofBackground(255);
	for (auto mover : movers) {
		mover.draw();
	}
}
