#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	cout << ofGetWidth() << endl;
	cout << ofGetHeight() << endl;


	ofSetVerticalSync(true);
	ofBackground(0xfdefc2);

	gameover.load("game_over.ttf", 300);
	
	ofHideCursor();

}

//--------------------------------------------------------------
void ofApp::update(){

	box2d.update();

	ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
	ofRemove(circles, ofxBox2dBaseShape::shouldRemoveOffScreen);
	//box2d.setGravity(ofMap(ofGetMouseX(), 0, ofGetWidth(), -50, 50), 
	//	ofMap(ofGetMouseY(), 0, ofGetHeight(), -50, 50));


	/*for (auto &box : boxes) {
		if (box->isSleeping() == false) {
			isAllStop = false;
		}
	}*/

	if (isAction) {
		if (boxes.size() > box_number) {
			auto &box = boxes.back();
			ofVec2f last_box_cur_pos = box->getPosition();

			int index = 0;
			for (auto &tbox : boxes) {
				if (tbox->getPosition().y > ofGetHeight() - 100 * index) {
					cout << "game over" << endl;
					isAction = false;
					GAME_STATE = GAME_OVER;
				}
				index++;
			}
			/*
			if (last_box_cur_pos.y > ofGetHeight() - 100) {
				cout << "game over" << endl;
				isAction = false;
			}*/

			if (last_box_cur_pos.y < ofGetHeight() - 100 * box_number && last_box_cur_pos.y > ofGetHeight() - 100 * (box_number + 1)) {
				if (ofDist(last_box_pre_pos.x, last_box_pre_pos.y, last_box_cur_pos.x, last_box_cur_pos.y) < 0.1) {
					box_number++;
					isAction = false;
					if (box_number == 5) {
						GAME_STATE = GAME_SUCCESS;
					}
				}
			}
			last_box_pre_pos = last_box_cur_pos;

		}
	}

	

	if (boxes.size() == box_number) {
		float w = 100;
		float h = 100;
		auto box = make_shared<ofxBox2dRect>();
		box->setPhysics(3.0, 0.2, 1.0);
		if (isLeft) {
			box->setup(box2d.getWorld(), ofGetWidth() / 4, 100, w, h);
		}
		else {
			box->setup(box2d.getWorld(), ofGetWidth() / 4*3, 100, w, h);
		}
		boxes.push_back(box);
		isLeft = !isLeft;
	}
	
	

	/*
	if (boxes.size() > 0) {
		auto &box = boxes.back();
		ofVec2f last_box_cur_pos = box->getPosition();

		if (ofDist(last_box_pre_pos.x, last_box_pre_pos.y, last_box_cur_pos.x, last_box_cur_pos.y) < 1) {
			isAllStop = true;
		}
		last_box_pre_pos = last_box_cur_pos;
		//cout << box->getPosition().y << endl;
	}
	
	if (isAllStop) {
		for (auto &box : boxes) {
			ofVec2f pos = box->getPosition();

			
			if (pos.y < ofGetHeight() - 100 * box_number) {
				box_number++;
			}
		}
	}*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (GAME_STATE == GAME_ON) {
		for (auto &circle : circles) {
			ofFill();
			ofSetHexColor(0x90d4e3);
			circle->draw();
		}

		int order = 0;
		for (auto &box : boxes) {
			ofFill();
			if (order % 2 == 0) {
				ofSetHexColor(0xe63b8b);
			}
			else {
				ofSetHexColor(0x50a4ff);
			}
			box->draw();
			order++;
		}

		for (int i = 0; i < 30; i++) {
			ofFill();
			ofSetHexColor(0x000000);
			ofDrawLine(0, ofGetHeight() - 100 * (i + 1), ofGetWidth(), ofGetHeight() - 100 * (i + 1));
		}


		//ofDrawBitmapString(box_number, 100, 100);

		gameover.drawString(ofToString(box_number), ofGetWidth() / 2, 600);
		ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 10);
	}

	else if (GAME_STATE == GAME_SUCCESS) {
		string txt = "Congratulations, You Win!";
		gameover.drawString(txt, ofGetWidth() / 2 - gameover.stringWidth(txt)/2, ofGetHeight() / 2);
	}

	else if (GAME_STATE == GAME_OVER) {
		string txt = "Game Over, Press The Screen To Restart";
		gameover.drawString(txt, ofGetWidth() / 2 - gameover.stringWidth(txt) / 2, ofGetHeight() / 2);
	}

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'q') {
		auto circle = make_shared<ofxBox2dCircle>();
		circle->setPhysics(3.0, 0.53, 1.0);
		circle->setup(box2d.getWorld(), mouseX, mouseY, ofRandom(4, 20));
		circles.push_back(circle);
	}

	if (key == 'w') {
		float w = 100;
		float h = 100;
		auto box = make_shared<ofxBox2dRect>();
		box->setPhysics(3.0, 0.2, 1.0);
		box->setup(box2d.getWorld(), mouseX, mouseY, w, h);
		boxes.push_back(box);
	}

	if (key == 'f') {
		ofToggleFullscreen();
		cout << ofGetWidth() << endl;
		cout << ofGetHeight() << endl;
	}

	if (key == 's') {
		box2d.init();
		box2d.setGravity(0, 30);
		box2d.createGround();
		box2d.createBounds();
		box2d.setFPS(60);
		box2d.registerGrabbing();


		box_number = 1;
		isAction = false;

		float w = 100;
		float h = 100;
		auto box = make_shared<ofxBox2dRect>();
		box->setPhysics(3.0, 0.2, 1.0);
		box->setup(box2d.getWorld(), fullScreenW / 2, fullScreenH - 100, w, h);
		boxes.push_back(box);
	}

	if (key == 'r') {
		boxes.clear();
		box_number = 1;
		isAction = false;

		float w = 100;
		float h = 100;
		auto box = make_shared<ofxBox2dRect>();
		box->setPhysics(3.0, 0.2, 1.0);
		box->setup(box2d.getWorld(), fullScreenW / 2, fullScreenH - 100, w, h);
		boxes.push_back(box);

		GAME_STATE = GAME_ON;
		//ofRemove(boxes, true);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	ofFill();
	ofSetHexColor(0x000000);
	ofDrawCircle(x, y, 20);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	isAction = true;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
