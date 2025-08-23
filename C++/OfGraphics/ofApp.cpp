#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofBackground(255);		// 배경색 지정, 하나의 값을 넣으면 나머지도 그 색으로 지정
	ofSetCircleResolution(50);		// 원 그릴때 점의 갯수 -> 5개는 대충 그려라
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
	
	ofDrawCircle(x, y, r);		// 원 그리기(x좌표, y좌표, 반지름)
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
