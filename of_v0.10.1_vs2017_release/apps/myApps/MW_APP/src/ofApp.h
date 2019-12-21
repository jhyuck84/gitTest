#pragma once

#include "ofMain.h"
#include "button.h"
#include "ofxBox2d.h"
#include "card.h"


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//STATE 
	int STATE;
	const int initState = 1;
	const int introState = 2;
	const int gameState = 3;
	const int finishState = 4;

	int SelectedGame;
	const int box_game = 1;
	const int card_game = 2;

	//update function
	void gameState_update();

	//draw function
	void initState_draw();
	void introState_draw();
	void gameState_draw();
	void finishState_draw();

	//mouse function
	void initState_mouseReleased();
	void introState_mouseReleased();
	void gameState_mouseReleased();
	void finishState_mouseReleased();

	//reset function

	//end function

	//image
	void image_setup();
	ofImage initState_box_start_btn_img;
	ofImage introState_game_start_btn_img;
	ofImage home_btn_img;
	ofImage retry_btn_img;
	ofImage next_btn_img;

	//button
	void button_setup();
	button initState_box_start_btn;
	button initState_card_start_btn;
	button introState_game_start_btn;
	button home_btn;
	button retry_btn;
	button next_btn;

	//Box Game
	ofxBox2d box2d;
	vector <shared_ptr<ofxBox2dRect>> boxes;

	int box_number;
	ofVec2f last_box_pre_pos;
	bool isAction;

	int fullScreenW = ofGetWidth();
	int fullScreenH = ofGetHeight();

	bool isLeft = true;

	void box_game_setup();
	void box_game_update();
	void box_game_end();
	void box_game_draw();
	void box_game_mouse_dragged();
	void box_game_mouse_released();

	//Card Game

	int cardNum = 4;
	card leftCard[4];
	card rightCard[4];

	int rightSelectedCard;
	int leftSelectedCard;

	int numWin = 0;
	float gamePlayTime = 0;
	int count = 0;

	void card_game_setup();
	void card_game_draw();
	void card_game_end();
	void card_game_mouse_released(int x, int y);
};
