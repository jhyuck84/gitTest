#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

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


		ofxBox2d								box2d;
		//ofxBox2dEdge							edgeLine;
		vector <shared_ptr<ofxBox2dCircle>>		circles;
		vector <shared_ptr<ofxBox2dRect>>		boxes;

		int box_number;
		ofVec2f last_box_pre_pos;
		bool isAction;

		int fullScreenW = 1920; 
		int fullScreenH = 1080;

		bool isLeft = true;

		ofTrueTypeFont gameover;

		int GAME_STATE = 1;
		int GAME_ON = 1;
		int GAME_SUCCESS = 2;
		int GAME_OVER = 3;
		
};
