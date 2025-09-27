#pragma once

#include "ofMain.h"

#include "mover.h"
#include <vector>

class ofApp : public ofBaseApp{
	public:
		std::vector<Mover> movers;
		void setup();
		void update();
		void draw();
};
