#pragma once

#include "ofMain.h"
#include <vector>

struct Brick {
	ofRectangle rect;
	ofColor color;
	int hp;
	Brick() { };
	Brick(float x, float y, float w, float h, const ofColor & c, int hpi)
		: rect(x, y, w, h)
		, color(c)
		, hp(hpi) { }
	bool alive() const { return hp > 0; }
	void draw() const {
		ofPushStyle();
		if (!alive()) return;
		ofSetColor(color);
		ofDrawRectangle(rect);
		ofNoFill();
		ofSetColor(0);
		ofDrawRectangle(rect);
		ofPopStyle();
	}
};

struct Paddle {
	ofRectangle rect;
	float speed = 380.f;

	void init() {
		rect.width = 120;
		rect.height = 16;
		rect.x = ofGetWidth() * 0.5 - rect.width * 0.5;
		rect.y = ofGetHeight() - 40;
	}

	void draw() {
		ofPushMatrix();
		ofFill();
		ofSetColor(255);
		ofDrawRectRounded(rect, 8);
		ofNoFill();
		ofSetColor(0);
		ofSetLineWidth(1);
		ofDrawRectRounded(rect, 8);
		ofPopMatrix();
	}
};

struct Ball {
	ofVec2f pos;
	ofVec2f vel;
	float radius = 9;
	float speed = 200;
	bool moving = false;

	void init(const ofRectangle& rect) {
		float x = rect.x + rect.width * 0.5;
		float y = rect.y - 2 - radius;

		pos.set(x, y);
		vel.set(0, -1);

		moving = false;
	}

	void draw() const {
		ofPushMatrix();
		ofSetCircleResolution(32);		// ¿ø ¸¸µé¶§ Âï´Â Á¡ÀÇ °¹¼ö
		ofFill();
		ofSetColor(255);
		ofDrawCircle(pos, radius);

		ofNoFill();
		ofSetColor(0);
		ofSetLineWidth(1);
		ofDrawCircle(pos, radius);
		ofPopMatrix();
	}
};

struct ItemInstance {
	int id = -1;
	ofRectangle rect;
	std::string type;
	bool active = false;

	void activate(int _id, float x, float y, const std::string& t) {
		id = _id;
		rect.set(x - 10, y - 10, 20, 20);
		type = t;
		active = true;
	}

	void deactivate() { active = false; }
	void draw() const {
		if (!active) return;

		ofPushStyle();
		if (type == "expand")
			ofSetColor(150, 255, 150);
		else if (type == "slow")
			ofSetColor(150, 150, 255);
		else
			ofSetColor(255, 150, 150);

		ofFill();
		ofDrawRectangle(rect);
		ofSetColor(0);
		ofDrawRectangle(rect);
		ofPopStyle();
	}
};

struct Particle {
	bool active = false;

	ofVec2f pos;
	ofVec2f vel;
	float ttl = 0;
	ofColor color;

	void activate(float x, float y, const ofColor& c)
	{
		active = true;
		pos.set(x, y);

		float speed = ofRandom(80, 260);
		float ang = ofRandom(0, TWO_PI);
		vel.set(cos(ang) * speed, sin(ang) * speed);
		ttl = ofRandom(0.4f, 1.0f);
		color = c;
	}

	void update(float dt) {
		if (!active) return;

		ttl -= dt;
		if (ttl <= 0) {
			active = false;
			return;
		}

		vel *= (1.0f - 1.5f * dt);
		vel.y += 180.0 * dt;
		pos += vel * dt;
	}

	void draw() const {
		if (!active) return;
		float alpha = ofMap(ttl, 0, 1, 0, 200, true);
		ofPushStyle();
		ofSetColor(color, (int)alpha);
		ofDrawCircle(pos, 2 + (1.8 - ttl));
		ofPopStyle();
	}
};

class ofApp : public ofBaseApp{

	public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void launchBall(Ball& ball);
	bool collideWithBallAndRect(const ofRectangle & rect, const Ball & ball);

	Paddle paddle;
	bool moveLeft;
	bool moveRight;

	// Ball ball;
	std::vector<Ball> balls;

	const int BRICK_COLS = 10;
	vector<Brick> bricks;
	vector<pair<ofColor, int>> BRICK_INFO;

	vector<ItemInstance> itemPool;
	vector<ItemInstance> items;
	vector<Particle> particlePool;

	deque<ofVec2f> paddleTrail;
	int live = 3;
	int score = 0;
	int level = 1;

	float prevPaddleX = 0.f;
	float paddleVelX = 0.f;

	ofTrueTypeFont font;
	ofSoundPlayer bounceSound, loseLifeSound, brickSound, wallSound;
};
