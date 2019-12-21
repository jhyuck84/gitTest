#include "pongGame.h"

pongGame::pongGame() {

}

pongGame::~pongGame() {

}

void pongGame::setup() {
	ball_pos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	ball_vel = ofVec2f(ofRandom(1) * 10 + 20, ofRandom(1) * 10 + 20);
	ball_size = 30;

	bar_1_pos = ofVec2f(ofGetWidth() / 12, 0);
	bar_1_tar_pos = ofVec2f(ofGetWidth() / 12, 0);

	bar_2_pos = ofVec2f(ofGetWidth() - ofGetWidth() / 12, 0);
	bar_2_tar_pos = ofVec2f(ofGetWidth() - ofGetWidth() / 12, 0);
	bar_size = 200;

	isHit = false;
	isBallStart = false;
	ballStartCnt = 0;

	home_score = 0;
	away_score = 0;
}



void pongGame::draw() {
	ofSetColor(255);
	ofFill();
	ofDrawRectangle(bar_1_pos.x, bar_1_pos.y, 20, bar_size);
	ofDrawRectangle(bar_2_pos.x, bar_2_pos.y, 20, bar_size);

	ofSetColor(255);
	ofFill();
	ofSetCircleResolution(99);
	ofDrawCircle(ball_pos.x, ball_pos.y, ball_size);

	ofDrawBitmapString(ofToString(home_score)+" : "+ofToString(away_score), ofGetWidth()/2, 50);
}

void pongGame::update(ofVec2f spinner1, ofVec2f spinner2) {

	if (ballStartCnt < 50) {
		ballStartCnt++;
	}
	else {
		isBallStart = true;
	}

	//bar damper
	bar_1_pos.y += (bar_1_tar_pos.y - bar_1_pos.y)*0.1;
	bar_2_pos.y += (bar_2_tar_pos.y - bar_2_pos.y)*0.1;

	//bar position update
	bar_1_tar_pos.y = spinner1.y;
	if (spinner1.x == -10 && spinner1.y == -10) {
		bar_1_tar_pos.y = ofGetHeight() / 2;
	}

	bar_2_tar_pos.y = spinner2.y;
	if (spinner2.x == -10 && spinner2.y == -10) {
		bar_2_tar_pos.y = ofGetHeight() / 2;
	}

	//ball position update
	if (isBallStart) {
		ball_pos += ball_vel;
	}
	//left wall
	if (ball_pos.x - ball_size <= 0) {
		ball_init();
		away_score += 1;
	}
	//right wall
	if (ball_pos.x + ball_size >= ofGetWidth()) {
		ball_init();
		home_score += 1;
	}
	//top wall
	if (ball_pos.y - ball_size <= 0) {
		ball_vel.y *= -1;
	}
	//bottom wall
	if (ball_pos.y + ball_size >= ofGetHeight()) {
		ball_vel.y *= -1;
	}

	//bar interaction
	if (!isHit) {
		if (ball_pos.y > bar_1_pos.y && ball_pos.y < bar_1_pos.y + bar_size
			&& ball_pos.x - ball_size <= bar_1_pos.x+20 && ball_pos.x - ball_size > bar_1_pos.x) {
			ball_vel.x *= -1;
			isHit = true;
		}

		if (ball_pos.y > bar_2_pos.y && ball_pos.y < bar_2_pos.y + bar_size
			&& ball_pos.x + ball_size >= bar_2_pos.x && ball_pos.x + ball_size < bar_2_pos.x+20) {
			ball_vel.x *= -1;
			isHit = true;
		}
	}
	else {
		if (ball_pos.x > ofGetWidth() / 4 && ball_pos.x < ofGetWidth() / 4 * 3) {
			isHit = false;
		}
	}

}

void pongGame::ball_init() {
	ball_pos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSeedRandom();

	float ball_speed = 30;
	float angle = ofRandom(1)*PI / 2 - PI / 4;

	if (ofRandom(1) > 0.5) {
		angle = ofMap(angle, -PI/4, PI/4, PI/4*3, PI/4*5);
	}

	ball_vel = ofVec2f(ball_speed*cos(angle), ball_speed*sin(angle));
	ballStartCnt = 0;
	isBallStart = false;
}