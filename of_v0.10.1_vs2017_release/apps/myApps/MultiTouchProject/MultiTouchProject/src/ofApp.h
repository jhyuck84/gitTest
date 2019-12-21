#pragma once

#include "ofMain.h"
#include "testClass.h"
#include "pongGame.h"

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


		//Touch Functions
		void touchDown(ofTouchEventArgs & touch);
		void touchMoved(ofTouchEventArgs & touch);
		void touchUp(ofTouchEventArgs & touch);
		void touchDoubleTap(ofTouchEventArgs & touch);
		void touchCancelled(ofTouchEventArgs & touch);
		map<int, ofTouchEventArgs> touchMap;

		void spinnerTrack(bool ShowUI);

		void gameMenu();
		void eduMenu();
		void entMenu();
		void expMenu();

		

		void displayMenu(float x, float y, float angle, int Section);

		ofVec2f spinnerPos;
		ofVec2f spinnerMarkPos;
		float spinnerAngle;

		int STATE;
		int MAIN_MENU = 0;
		int PONG_GAME = 11;

		//pong game
		pongGame pong_game;
		
		/*
		void pongGame();
		void pongGame_setup();
		ofVec2f ball_vel;
		ofVec2f ball_pos;
		ofVec2f bar_pos;
		ofVec2f bar_tar_pos;*/

};
