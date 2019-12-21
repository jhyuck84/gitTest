#pragma once

#include "ofMain.h"

class pongGame {
	public:
		pongGame();
		~pongGame();

		void draw();
		void update(ofVec2f spinner1, ofVec2f spinner2);
		void setup();
		void ball_init();

		ofVec2f ball_vel;
		ofVec2f ball_pos;
		float ball_size;
		bool isBallStart;
		bool isHit;
		int ballStartCnt;

		ofVec2f bar_1_pos;
		ofVec2f bar_1_tar_pos;
		ofVec2f bar_2_pos;
		ofVec2f bar_2_tar_pos;
		float bar_size;
		int home_score;
		int away_score;
};