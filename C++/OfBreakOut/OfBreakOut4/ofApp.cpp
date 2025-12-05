#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Breakout with Pooling + Particles");
	ofSetFrameRate(60);
	ofBackground(18, 18, 30);

	// brick info
	BRICK_INFO = {
		{ ofColor(242, 85, 96), 1 },
		{ ofColor(86, 174, 87), 2 },
		{ ofColor(69, 177, 232), 3 },
		{ ofColor(233, 196, 106), 4 },
		{ ofColor(170, 110, 255), 5 },
		{ ofColor(255, 153, 51), 6 },
	};

	font.load("verdana.ttf", 20, true, true, true);

	// Load sounds int into bin/data
	bounceSound.load("bounce.mp3");
	loseLifeSound.load("lose_life.wav");
	brickSound.load("bounce.mp3");
	wallSound.load("bounce.mp3");

	// 풀 초기화
	itemPool.resize(64);
	for (int i = 0; i < 64; i++) {
		itemPool[i].id = 1;
		itemPool[i].active = false;
	}

	particlePool.resize(800);
	for (auto & p : particlePool)
		p.active = false;

	paddle.init();
	balls.push_back(Ball());
	// balls.push_back(Ball());
	// balls.push_back(Ball());

	for (auto& ball : balls)
		ball.init(paddle.rect);

	moveLeft = moveRight = false;

	resetGame();
}

void ofApp::resetGame()
{
	live = 3;
	score = 0;
	level = 1;

	paddle.init();
	prevPaddleX = paddle.rect.x;

	Ball ball = Ball();
	ball.moving = false;
	balls.push_back(ball);
	items.clear();

	for (auto & it : itemPool)
		it.deactivate();

	resetLevel();
}

void ofApp::resetLevel()
{
	bricks.clear();
	items.clear();
	int rows = BASE_ROWS + (level - 1);
	float padding = 6.f;
	float totalPad = padding * (BRICK_COLS + 1);
	float brickW = (ofGetWidth() - totalPad) / (float)BRICK_COLS;
	float brickH = 22.0f;

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < BRICK_COLS; c++) {
			float x = padding + c * (brickW + padding);
			float y = 60 + r * (brickH + padding);

			auto info = BRICK_INFO[r % BRICK_INFO.size()];
			bricks.emplace_back(x, y, brickW, brickH, info.first, info.second);
		}
	}

	balls.front().moving = false;
	balls.front().pos.set(paddle.rect.getCenter().x, paddle.rect.y - balls.front().radius - 2);

	float ang = ofRandom(-0.6, 0.6);
	ofVec2f v(ang, -1 + fabs(ang));
	v.normalize();
	balls.front().vel = v * balls.front().speed;
}

//--------------------------------------------------------------
void ofApp::update(){
	float dt = ofGetLastFrameTime();
	prevPaddleX = paddle.rect.getX();

	if (moveLeft) paddle.rect.x -= paddle.speed * dt;
	if (moveRight) paddle.rect.x += paddle.speed * dt;

	paddle.rect.x = ofClamp(paddle.rect.x, 0, ofGetWidth() - paddle.rect.width);

	paddleVelX = paddle.rect.getX() - prevPaddleX;

	for (auto& ball : balls) {
		if (!ball.moving) {
			ball.pos.x = paddle.rect.x + paddle.rect.width * 0.5;
		} else {
			int steps = 3;
			float subdt = dt / steps;
			for (int s = 0; s < steps; s++) {
				ball.pos += ball.vel * dt;

				// ceil
				if (ball.pos.y - ball.radius <= 0) {
					ball.pos.y = ball.radius;
					ball.vel.y *= -1;
					// play sound
				}
				// left wall
				if (ball.pos.x - ball.radius <= 0) {
					ball.pos.x = ball.radius;
					ball.vel.x *= -1;
					// play sound
				}
				// right wall
				if (ball.pos.x + ball.radius >= ofGetWidth()) {
					ball.pos.x = ofGetWidth() - ball.radius;
					ball.vel.x *= -1;
					// play sound
				}
				// bottom wall - for test
				if (ball.pos.y + ball.radius >= ofGetHeight()) {
					ball.pos.y = ofGetHeight() - ball.radius;
					ball.vel.y *= -1;
				}

				// paddle confliction
				if (collideWithBallAndRect(paddle.rect, ball) && ball.vel.y > 0)
				{
					float rel = (ball.pos.x - paddle.rect.getCenter().x) / (paddle.rect.width / 2.f);

					ofVec2f normal(0, -1);
					normal.x += paddleVelX * 0.01f;
					normal.normalize();

					ofVec2f incoming = ball.vel.getNormalized();
					float d = incoming.dot(normal);
					ofVec2f reflex = incoming - 2.0f * d * normal;

					reflex.x += rel * 0.6f;
					reflex.normalize();

					ball.vel = reflex * ball.speed;

					bounceSound.play();
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	paddle.draw();

	// draw bricks
	for (auto & b : bricks)
		b.draw();


	for (auto& ball: balls)
		ball.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) moveLeft = true;
	if (key == OF_KEY_RIGHT) moveRight = true;
	if (key == ' ') {
		for (auto& ball : balls) {
			if (!ball.moving)
				launchBall(ball);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_LEFT) moveLeft = false;
	if (key == OF_KEY_RIGHT) moveRight = false;
}

/////////////////////////////////////////////////////////
//--------------------------------------------------------------
void ofApp::launchBall(Ball& ball) {
	if (ball.moving) return;

	float ang = ofRandom(-0.6f, 0.6f);
	ofVec2f v(ang, -1 + fabs(ang));
	v.normalize();
	ball.vel = v * ball.speed;
	ball.moving = true;
}

bool ofApp::collideWithBallAndRect(const ofRectangle& rect, const Ball& ball) {
	float closestX = ofClamp(ball.pos.x, rect.getLeft(), rect.getRight());
	float closestY = ofClamp(ball.pos.y, rect.getTop(), rect.getBottom());
	float dx = ball.pos.x - closestX;
	float dy = ball.pos.y - closestY;

	return (dx * dx + dy * dy) <= (ball.radius * ball.radius);
}
