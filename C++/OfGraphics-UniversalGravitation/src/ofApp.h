#pragma once

#include "ofMain.h"
#include "mover.h"
#include <vector>

class ofApp : public ofBaseApp{
public:
	vector<Mover> movers;
	float base;
	
	const ofColor hotpink;

	const ofVec2f gravity;
	const ofVec2f wind;
	ofApp();

	void setup();
	void update();
	void draw();
	void drawBaseLine();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);	
};
