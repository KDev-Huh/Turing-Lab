#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
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

	for (auto & ball : balls)
		ball.init(paddle.rect);

	moveLeft = moveRight = false;

	resetGame();
}

void ofApp::resetGame() {
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

void ofApp::resetLevel() {
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
void ofApp::update() {
	float dt = ofGetLastFrameTime();
	prevPaddleX = paddle.rect.getX();

	if (moveLeft) paddle.rect.x -= paddle.speed * dt;
	if (moveRight) paddle.rect.x += paddle.speed * dt;

	paddle.rect.x = ofClamp(paddle.rect.x, 0, ofGetWidth() - paddle.rect.width);

	paddleVelX = paddle.rect.getX() - prevPaddleX;

	for (auto & ball : balls) {
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
				/*if (ball.pos.y + ball.radius >= ofGetHeight()) {
					ball.pos.y = ofGetHeight() - ball.radius;
					ball.vel.y *= -1;
				}*/

				// paddle confliction
				if (collideWithBallAndRect(paddle.rect, ball) && ball.vel.y > 0) {
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

				for (auto& b : bricks) {
					if (!b.alive()) continue;
					if (collideWithBallAndRect(b.rect, ball)) {
						b.hp--;

						if (!b.alive())
							score += 10;
						else
							score++;

						if (!b.alive() && ofRandom(0, 1) < 1.0f) {
							spawnItem(b.rect.getCenter());
						}

						// 충돌면 판단: ball의 중심과 각 면까지의 거리 중 최소값
						float left = ball.pos.x - b.rect.getLeft();
						float right = b.rect.getRight() - ball.pos.x;
						float top = ball.pos.y - b.rect.getTop();
						float bottom = b.rect.getBottom() - ball.pos.y;

						float minDist = std::min({ left, right, top, bottom });

						if (minDist == left) {
							ball.pos.x = b.rect.getLeft() - ball.radius;
							ball.vel.x *= -1;
						} else if (minDist == right) {
							ball.pos.x = b.rect.getRight() + ball.radius;
							ball.vel.x *= -1;
						} else if (minDist == top) {
							ball.pos.y = b.rect.getTop() - ball.radius;
							ball.vel.y *= -1;
						} else {
							ball.pos.y = b.rect.getBottom() + ball.radius;
							ball.vel.y *= -1;
						}

						// 파편 생성
						int pcount = 12 + (int)ofRandom(0, 8);
						for (int pi = 0; pi < pcount; pi++) {
							for (auto& pp : particlePool) {
								if (!pp.active) {
									pp.activate(ball.pos.x, ball.pos.y, b.color);
									break;
								}
							}
						}

						brickSound.play();
						break;
					}
				}

				// ball out
				if (ball.pos.y - ball.radius > ofGetHeight()) {
					--live;
					ball.moving = false;
					ball.speed = 360 + (level - 1) * 30;
					ball.pos.set(paddle.rect.getCenter().x, paddle.rect.getCenter().y - ball.radius - 2);
					loseLifeSound.play();
					break;
				}
			}
		}

		// item: move, pickup, return to pool
		for (int i = (int)items.size() - 1; i >= 0; --i) {
			items[i].rect.y += 140 * dt;
			if (items[i].rect.intersects(paddle.rect)) {
				if (items[i].type == "expand") {
					paddle.rect.width = std::min(paddle.rect.x * 1.3, ofGetWidth() * 0.6);
				} else if (items[i].type == "slow") {
					ball.speed = std::max(180.0f, ball.speed * 0.8f);
					ball.vel.normalize();
					ball.vel *= ball.speed;
				} else if (items[i].type == "life") {
					live++;
				}

				// deactive items in pool
				int id = items[i].id;
				if (id >= 0 && id < (int)itemPool.size())
					itemPool[id].deactivate();

				items.erase(items.begin() + i);
			} else if (items[i].rect.getTop() > ofGetHeight()) {
				int id = items[i].id;
				if (id >= 0 && id < (int)itemPool.size())
					itemPool[id].deactivate();

				items.erase(items.begin() + i);
			} else {
				int id = items[i].id;
				if (id >= 0 && id < (int)itemPool.size())
					itemPool[id].rect = items[i].rect;
			}
		}

		// Particle Update
		for (auto& p : particlePool) {
			p.update(dt);
		}

		// level up?
		bool allDead = true;
		for (auto& b : bricks)
			if (b.alive()) {
				allDead = false;
				break;
			}

		if (allDead) {
			level++;
			ball.speed = 360 + (level - 1) * 40;
			resetLevel();
		}

		// update bricks color
		for (auto& b : bricks) {
			if (b.alive()) {
				int idx = ofClamp(b.hp - 1, 0, (int)BRICK_INFO.size() - 1);
				b.color = BRICK_INFO[idx].first;
			}
		}
	}
}

void ofApp::spawnItem(ofVec3f p)
{
	for (auto& ip : itemPool) {
		if (!ip.active) {
			int r = (int)ofRandom(0, 3);
			string t = (r == 0 ? "expand" : (r == 1 ? "slow" : "life"));

			ip.activate(ip.id, p.x, p.y, t);
			items.push_back(ip);
			break;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	paddle.draw();

	// draw bricks
	for (auto & b : bricks)
		b.draw();

	for (auto & ball : balls)
		ball.draw();

	// particle additive glow
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	for (auto & p : particlePool)
		p.draw();
	ofDisableBlendMode();

	// item
	for (auto & it : items)
		it.draw();

	// HUD
	ofSetColor(255);
	font.drawString("Score: " + ofToString(score), 10, 30);
	font.drawString("Lives: " + ofToString(live), ofGetWidth() - 140, 30);
	font.drawString("Level: " + ofToString(level), ofGetWidth() / 2 - 40, 30);

	if (live <= 0) {
		string msg = "GAME OVER - PRESS R to restart or ESC to quit";
		ofRectangle bbox = font.getStringBoundingBox(msg, 0, 0);
		font.drawString(msg, ofGetWidth() / 2 - bbox.width / 2, ofGetHeight() / 2);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_LEFT) moveLeft = true;
	if (key == OF_KEY_RIGHT) moveRight = true;
	if (key == ' ') {
		for (auto & ball : balls) {
			if (!ball.moving)
				launchBall(ball);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == OF_KEY_LEFT) moveLeft = false;
	if (key == OF_KEY_RIGHT) moveRight = false;
}

/////////////////////////////////////////////////////////
//--------------------------------------------------------------
void ofApp::launchBall(Ball & ball) {
	if (ball.moving) return;

	float ang = ofRandom(-0.6f, 0.6f);
	ofVec2f v(ang, -1 + fabs(ang));
	v.normalize();
	ball.vel = v * ball.speed;
	ball.moving = true;
}

bool ofApp::collideWithBallAndRect(const ofRectangle & rect, const Ball & ball) {
	float closestX = ofClamp(ball.pos.x, rect.getLeft(), rect.getRight());
	float closestY = ofClamp(ball.pos.y, rect.getTop(), rect.getBottom());
	float dx = ball.pos.x - closestX;
	float dy = ball.pos.y - closestY;

	return (dx * dx + dy * dy) <= (ball.radius * ball.radius);
}
