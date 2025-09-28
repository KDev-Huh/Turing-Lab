#include "ofApp.h"

ofApp::ofApp()
	: hotpink(255, 105, 180)
	, base(200)
	, gravity(ofVec2f(0.f, 0.1f))
	, wind(ofVec2f(0.1f, 0.f)) { }

//--------------------------------------------------------------
void ofApp::setup(){
	float w = ofGetWidth();
	float h = ofGetHeight();

	// mover 객체 추가 및 위치 설정
	// 코드 여기 작성
	movers.push_back(Mover(w * 0.25, 0, 8));
	movers.push_back(Mover(w * 0.5, 0, 5));
	movers.push_back(Mover(w * 0.75, 0, 2));

	for (auto & mover : movers)
		mover.position.y = base - mover.radius;


	ofSetCircleResolution(60);

	for (auto& mover : movers)
		mover.applyForce(gravity * mover.mass);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (auto& mover : movers)
	{
		// mover.applyForce();
		// 여기에 힘을 적용하는 코드 작성

		mover.update();
		mover.checkEdges();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);
	drawBaseLine();

	for (auto & mover : movers)
		mover.draw();
}

void ofApp::drawBaseLine()
{
	ofSetColor(hotpink);

	int left = ofGetWidth() * 0.1;
	int right = ofGetWidth() * 0.9;

	ofSetLineWidth(2);
	ofDrawLine(left, base, right, base);
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
