#pragma once

#include "ofMain.h"
#include "card.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
		
		ofTrueTypeFont gameEndFont;

		card leftCard[9];
		card rightCard[9];

		int rightSelectedCard = -1;
		int leftSelectedCard = -1;

		int numWin = 0;
		float gamePlayTime = 0;
		int count = 0;

		int GAME_STATE = 1;
		int GAME_ON = 1;
		int GAME_END = 2;
};
