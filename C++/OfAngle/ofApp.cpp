#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);

	angle = 0.0f;
	angleVelocity = 1.0f;
}

//--------------------------------------------------------------
void ofApp::update(){
	angle += angleVelocity;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	ofPushMatrix();

	ofSetColor(80);
	float cx = ofGetWidth() * 0.5;
	float cy = ofGetHeight() * 0.5;

	ofTranslate(cx, cy);
	ofRotateDeg(angle);

	ofSetLineWidth(1);
	ofDrawLine(-100, 0, 100, 0);

	ofSetLineWidth(2);
	ofSetColor(127);
	ofDrawCircle(-100, 0, 20);
	ofDrawCircle(100, 0, 20);

	ofPopMatrix();
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
