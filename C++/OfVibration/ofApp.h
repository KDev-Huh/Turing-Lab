#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawBall(float x, float y, float radius);
		void mouseScrolled(ofMouseEventArgs & args) override;

		float radius { 20.f };
		float nx, ny;
		float timing;
		float barLen { 120.f };
		float angle;
};
