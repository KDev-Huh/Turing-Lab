#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	const float distance = 150.f;
	bodyA.setup(ofGetWidth() * 0.5, ofGetHeight() * 0.5 + distance, 50, ofColor(20, 80, 255));
	bodyB.setup(ofGetWidth() * 0.5, ofGetHeight() * 0.5 - distance, 50, ofColor(255, 80, 20));
	ofSetCircleResolution(60);

	bodyA.velocity = ofVec2f(1, -1);
	bodyB.velocity = ofVec2f(-1, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
	bodyA.attract(bodyB);
	bodyB.attract(bodyA);

	bodyA.update();
	bodyB.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	bodyA.draw();
	bodyB.draw();

	ofNoFill();
	ofSetLineWidth(1);
	ofSetColor(230, 183, 64);
	ofDrawLine(bodyA.position, bodyB.position);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
