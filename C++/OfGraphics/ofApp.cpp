#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofBackground(255);		// ���� ����, �ϳ��� ���� ������ �������� �� ������ ����
	ofSetCircleResolution(50);		// �� �׸��� ���� ���� -> 5���� ���� �׷���
	stdDev.set("Standard Derivation", 40, 10, 200);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSleepMillis(1);

	ofColor color;
	color.setHsb(floor(ofRandom(256)), 180, 220);

	ofSetColor(color);

	float r = ofRandom(2, 6);
	float x = ofRandomGaussian((double)(ofGetWidth() / 2), (double)(stdDev));
	float y = ofRandomGaussian((double)(ofGetHeight() / 2), (double)(stdDev));
	
	ofDrawCircle(x, y, r);		// �� �׸���(x��ǥ, y��ǥ, ������)
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
