#include "ofApp.h"
#include "ofxWin8Touch.h"
#include "testClass.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofxWin8TouchSetup();
	ofRegisterTouchEvents(this);
	ofBackground(0);

	STATE = PONG_GAME;
	//pongGame_setup();

	pong_game.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofNoFill();
	ofSetColor(225);

	spinnerTrack(false);
	
	ofDrawBitmapString(spinnerPos.x, 100, 100);
	ofDrawBitmapString(spinnerPos.y, 100, 120);
	ofDrawBitmapString(spinnerMarkPos.x, 100, 150);
	ofDrawBitmapString(spinnerMarkPos.y, 100, 170);

	if (STATE == MAIN_MENU) {
		ofLine(0, ofGetHeight() / 2, ofGetWidth(), ofGetHeight() / 2);
		ofLine(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());

		if (spinnerPos.x > 0 && spinnerPos.x < ofGetWidth() / 2 && spinnerPos.y>0 && spinnerPos.y < ofGetHeight() / 2) {
			gameMenu();
		}
		else if (spinnerPos.x > ofGetWidth() / 2 && spinnerPos.x < ofGetWidth() && spinnerPos.y>0 && spinnerPos.y < ofGetHeight() / 2) {
			eduMenu();
		}
		else if (spinnerPos.x > 0 && spinnerPos.x < ofGetWidth() / 2 && spinnerPos.y>ofGetHeight() / 2 && spinnerPos.y < ofGetHeight()) {
			entMenu();
		}
		else if (spinnerPos.x > ofGetWidth() / 2 && spinnerPos.x < ofGetWidth() && spinnerPos.y>ofGetHeight() / 2 && spinnerPos.y < ofGetHeight()) {
			expMenu();
		}
	}
	else if (STATE == PONG_GAME) {
		pong_game.update(ofVec2f(ofGetMouseX(), ofGetMouseY()), ofVec2f(ofGetMouseX(), ofGetMouseY()));
		pong_game.draw();

	}

}

/*
void ofApp::pongGame_setup() {
	ball_pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
	ball_vel = ofVec2f(ofRandom(1)*10+20, ofRandom(1)*10+20);
	bar_pos = ofVec2f(ofGetWidth()/12, 0);
	bar_tar_pos = ofVec2f(ofGetWidth() / 12, 0);
}

void ofApp::pongGame() {

	

	//moving bar
	ofSetColor(255);
	ofFill();
	ofDrawRectangle(bar_pos.x, bar_pos.y, 20, 200);
	bar_pos.y += (bar_tar_pos.y - bar_pos.y)*0.1;

	bar_tar_pos.y = spinnerPos.y;
	if (spinnerPos.x == -10 && spinnerPos.y == -10) {
		bar_tar_pos.y = ofGetHeight() / 2;
	}

	//ball
	ofSetColor(255);
	ofFill();
	ofSetCircleResolution(99);
	ofDrawCircle(ball_pos.x, ball_pos.y, 30);
	ball_pos += ball_vel;

	//left wall
	if (ball_pos.x - 30 <= 0) {
		ball_vel.x *= -1;
	}
	//right wall
	if (ball_pos.x + 30 >= ofGetWidth()) {
		ball_vel.x *= -1;
	}
	//top wall
	if (ball_pos.y - 30 <= 0) {
		ball_vel.y *= -1;
	}
	//bottom wall
	if (ball_pos.y + 30 >= ofGetHeight()) {
		ball_vel.y *= -1;
	}

	if (ball_pos.y > bar_pos.y - 100 && ball_pos.y < bar_pos.y + 100 && ball_pos.x - 30 <= bar_pos.x && ball_pos.x - 30 > 0) {
		ball_vel.x *= -1;
	}
}*/

void ofApp::gameMenu() {
	ofFill();
	ofDrawBitmapString("GAME MENU", ofGetWidth()/4, ofGetHeight()/4);
	displayMenu(spinnerPos.x, spinnerPos.y, spinnerAngle, 0);
	
	string menuText[] = { "game1", "game2", "game3", "game4" };
	ofSetColor(255);
	ofFill();
	ofDrawBitmapString(menuText[0], spinnerPos.x + 200, spinnerPos.y - 200);
	ofDrawBitmapString(menuText[1], spinnerPos.x - 200, spinnerPos.y - 200);
	ofDrawBitmapString(menuText[2], spinnerPos.x - 200, spinnerPos.y + 200);
	ofDrawBitmapString(menuText[3], spinnerPos.x + 200, spinnerPos.y + 200);
}

void ofApp::eduMenu() {
	ofDrawBitmapString("EDU MENU", ofGetWidth() /4*3, ofGetHeight() / 4);
	displayMenu(spinnerPos.x, spinnerPos.y, spinnerAngle, 1);

	string menuText[] = { "math", "science", "art", "english" };
	ofSetColor(255);
	ofFill();
	ofDrawBitmapString(menuText[0], spinnerPos.x + 200, spinnerPos.y - 200);
	ofDrawBitmapString(menuText[1], spinnerPos.x - 200, spinnerPos.y - 200);
	ofDrawBitmapString(menuText[2], spinnerPos.x - 200, spinnerPos.y + 200);
	ofDrawBitmapString(menuText[3], spinnerPos.x + 200, spinnerPos.y + 200);
}

void ofApp::entMenu() {
	ofDrawBitmapString("ENT MENU", ofGetWidth() / 4, ofGetHeight() /4*3);
	displayMenu(spinnerPos.x, spinnerPos.y, spinnerAngle, 2);

	string menuText[] = { "Video", "Music", "Internet", "SNS" };
	ofSetColor(255);
	ofFill();
	ofDrawBitmapString(menuText[0], spinnerPos.x + 200, spinnerPos.y - 200);
	ofDrawBitmapString(menuText[1], spinnerPos.x - 200, spinnerPos.y - 200);
	ofDrawBitmapString(menuText[2], spinnerPos.x - 200, spinnerPos.y + 200);
	ofDrawBitmapString(menuText[3], spinnerPos.x + 200, spinnerPos.y + 200);
}

void ofApp::expMenu() {
	ofDrawBitmapString("EXP MENU", ofGetWidth() /4*3, ofGetHeight() /4*3);
	string menuText[] = { "game1", "game2", "game3", "game4" };
	displayMenu(spinnerPos.x, spinnerPos.y, spinnerAngle, 3);
}

void ofApp::spinnerTrack(bool showUI) {
	ofVec2f box_pos[10];
	float box_angle[10];
	for (int i = 0; i < 10; i++) {
		box_pos[i] = ofVec2f(-1, -1);
		box_angle[i] = -999;
	}
	int box_counter = 0;

	for (auto i = touchMap.begin(); i != touchMap.end(); ++i) {

		for (auto j = i; j != touchMap.end(); ++j) {
			if (i != j) {
				auto &touch1 = i->second;
				auto &touch2 = j->second;

				ofSetColor(225);
				if (showUI) {
					ofLine(touch1.x, touch1.y, touch2.x, touch2.y);
				}
				float dist = ofDist(touch1.x, touch1.y, touch2.x, touch2.y);

				ofVec2f pos;
				pos.set((touch1.x + touch2.x) / 2, (touch1.y + touch2.y) / 2);
				float angle = atan2(touch2.y - touch1.y, touch2.x - touch1.x);


				int id;
				id = 0;

				//ofDrawBitmapString(dist, pos.x, pos.y);

				//if (dist > 150 && dist < 200) {
				//	id = 1;
				//}
				if (dist > 300 && dist < 350) {
					id = 2;
				}

				if (id != 0) {
					if (id == 1) {
						ofSetColor(0, 255, 0, 80);
					}
					else {
						ofSetColor(0, 0, 255, 80);
					}

					ofPushMatrix();
					ofTranslate(pos.x, pos.y);
					ofRotateZRad(angle);
					ofFill();
					ofSetRectMode(OF_RECTMODE_CENTER);
					ofPopMatrix();

					box_pos[box_counter] = ofVec2f(pos.x, pos.y);
					box_angle[box_counter] = angle;
					box_counter++;

				}
			}

		}
		//ofDrawBitmapString(box_counter, 100, 100);
		for (int i = 0; i < box_counter; i++) {
			//ofDrawBitmapString(box_pos[i], 100, 120+i*20);
		}
	}

	int rcnt = 0;
	for (int i = 0; i < box_counter; i++) {
		bool isOverlap = false;
		for (int j = i; j < box_counter; j++) {
			if (i != j) {
				float d = ofDist(box_pos[i].x, box_pos[i].y, box_pos[j].x, box_pos[j].y);
				if (d < 50) {
					isOverlap = true;
				}
			}
		}
		if (!isOverlap) {
			rcnt++;

			ofSetColor(255, 255, 255, 100);
			ofFill();

			float dot_angle = ofRadToDeg(box_angle[i]);
			//ofDrawBitmapString(dot_angle, 500, 100);
			spinnerAngle = dot_angle;

			if (showUI) {
				for (int j = 0; j < 4; j++) {
					ofPath path;
					if (j == 0) {

						if (dot_angle > 0 && dot_angle < 90) {
							path.setFillColor(ofColor(0, 0, 255));
						}
						else {
							path.setFillColor(ofColor(0, 0, 255, 50));
						}

						path.moveTo(box_pos[i].x + 400, box_pos[i].y);
						path.setArcResolution(99);
						path.arc(box_pos[i].x, box_pos[i].y, 400, 400, 0, 90);
						path.lineTo(box_pos[i].x, box_pos[i].y);
						path.draw();
					}
					else if (j == 1) {

						if (dot_angle > -90 && dot_angle < 0) {
							path.setFillColor(ofColor(255, 0, 0));
						}
						else {
							path.setFillColor(ofColor(255, 0, 0, 50));
						}

						path.moveTo(box_pos[i].x, box_pos[i].y - 400);
						path.setArcResolution(99);
						path.arc(box_pos[i].x, box_pos[i].y, 400, 400, 270, 0);
						path.lineTo(box_pos[i].x, box_pos[i].y);
						path.draw();
					}
					else if (j == 2) {

						if (dot_angle > -180 && dot_angle < -90) {
							path.setFillColor(ofColor(0, 255, 0));
						}
						else {
							path.setFillColor(ofColor(0, 255, 0, 50));
						}

						path.moveTo(box_pos[i].x - 400, box_pos[i].y);
						path.setArcResolution(99);
						path.arc(box_pos[i].x, box_pos[i].y, 400, 400, 180, 270);
						path.lineTo(box_pos[i].x, box_pos[i].y);
						path.draw();
					}
					else if (j == 3) {

						if (dot_angle > 90 && dot_angle < 180) {
							path.setFillColor(ofColor(255, 255, 0));
						}
						else {
							path.setFillColor(ofColor(255, 255, 0, 50));
						}

						path.moveTo(box_pos[i].x, box_pos[i].y + 400);
						path.setArcResolution(99);
						path.arc(box_pos[i].x, box_pos[i].y, 400, 400, 90, 180);
						path.lineTo(box_pos[i].x, box_pos[i].y);
						path.draw();
					}
				}
			}



			float markX = box_pos[i].x + 300 * cos(box_angle[i]);
			float markY = box_pos[i].y + 300 * sin(box_angle[i]);

			ofSetColor(255);
			ofFill();
			ofSetCircleResolution(99);
			ofDrawCircle(box_pos[i].x, box_pos[i].y, 10);

			spinnerPos = box_pos[i];
			spinnerMarkPos = ofVec2f(markX, markY);
		}
	}
	if (rcnt == 0) {
		spinnerPos = ofVec2f(-10, -10);
		spinnerMarkPos = ofVec2f(0, 0);
		spinnerAngle = -999;
	}

}

void ofApp::displayMenu(float x, float y, float angle, int Section) {

	ofColor baseColor;
	ofColor selectedColor;

	//game
	if (Section == 0) {
		baseColor = ofColor(0, 0, 255, 50);
		selectedColor = ofColor(0, 0, 255);
	}
	//edu
	else if (Section == 1) {
		baseColor = ofColor(0, 255, 0, 50);
		selectedColor = ofColor(0, 255, 0);
	}
	//ent
	else if (Section == 2) {
		baseColor = ofColor(255, 0, 0, 50);
		selectedColor = ofColor(255, 0, 0);

	}
	//exp
	else if (Section == 3) {
		//baseColor = ofColor(0, 0, 255, 50);
		//selectedColor = ofColor(0, 0, 255);

	}

	
	for (int j = 0; j < 4; j++) {
		ofPath path;
		if (j == 0) {

			if (angle > 0 && angle < 90) {
				path.setFillColor(selectedColor);
			}
			else {
				path.setFillColor(baseColor);
			}

			path.moveTo(x + 400, y);
			path.setArcResolution(99);
			path.arc(x, y, 400, 400, 0, 90);
			path.lineTo(x, y);
			path.draw();

			
		}
		else if (j == 1) {

			if (angle > -90 && angle < 0) {
				path.setFillColor(selectedColor);
			}
			else {
				path.setFillColor(baseColor);
			}

			path.moveTo(x, y - 400);
			path.setArcResolution(99);
			path.arc(x, y, 400, 400, 270, 0);
			path.lineTo(x, y);
			path.draw();
		}
		else if (j == 2) {

			if (angle > -180 && angle < -90) {
				path.setFillColor(selectedColor);
			}
			else {
				path.setFillColor(baseColor);
			}

			path.moveTo(x - 400, y);
			path.setArcResolution(99);
			path.arc(x, y, 400, 400, 180, 270);
			path.lineTo(x, y);
			path.draw();
		}
		else if (j == 3) {

			if (angle > 90 && angle < 180) {
				path.setFillColor(selectedColor);
			}
			else {
				path.setFillColor(baseColor);
			}

			path.moveTo(x, y + 400);
			path.setArcResolution(99);
			path.arc(x, y, 400, 400, 90, 180);
			path.lineTo(x, y);
			path.draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch) {
	touchMap[touch.id] = touch;
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch) {
	touchMap[touch.id] = touch;
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch) {
	touchMap.erase(touch.id);
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch) {

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch) {
	touchMap.erase(touch.id);
}
