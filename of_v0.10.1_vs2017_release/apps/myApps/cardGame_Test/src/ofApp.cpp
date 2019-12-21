#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gameEndFont.load("game_over.ttf", 300);


	int cardWidth = 200;
	int cardHeight = 300;
	int cardGap = 50;
	for (int i = 0; i < 9; i++) {
		int row = i % 3;
		int col = i / 3;
		leftCard[i].setup((ofGetWidth()*0.25 - cardWidth - cardGap)+(cardWidth+cardGap)*row, 
			(ofGetHeight()*0.5-cardHeight-cardGap)+(cardHeight+cardGap)*col, cardWidth, cardHeight, i+1);

		rightCard[i].setup((ofGetWidth()*0.75 - cardWidth - cardGap) + (cardWidth + cardGap)*row,
			(ofGetHeight()*0.5 - cardHeight - cardGap) + (cardHeight + cardGap)*col, cardWidth, cardHeight, i+1);
	}

	for (int i = 0; i < 10; i++) {
		int rNum1 = int(ofRandom(9));
		int rNum2 = int(ofRandom(9));

		int tempNum = leftCard[rNum1].cardNumber;
		leftCard[rNum1].setNum(leftCard[rNum2].cardNumber);
		leftCard[rNum2].setNum(tempNum);
		

		rNum1 = int(ofRandom(9));
		rNum2 = int(ofRandom(9));

		tempNum = rightCard[rNum1].cardNumber;
		rightCard[rNum1].setNum(rightCard[rNum2].cardNumber);
		rightCard[rNum2].setNum(tempNum);

	}

	ofResetElapsedTimeCounter();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (GAME_STATE == GAME_ON) {

		string txt = ofToString(int(ofGetElapsedTimef()));
		gameEndFont.drawString(txt, ofGetWidth()/2, 250);

		for (int i = 0; i < 9; i++) {
			leftCard[i].draw();
			rightCard[i].draw();
		}

		if (leftSelectedCard != -1 && rightSelectedCard != -1) {
			if (leftCard[leftSelectedCard].cardNumber == rightCard[rightSelectedCard].cardNumber) {
				//win
				leftSelectedCard = -1;
				rightSelectedCard = -1;
				numWin++;
				if (numWin == 9) {
					gamePlayTime = ofGetElapsedTimef();
					GAME_STATE = GAME_END;
				}
			}

			else {
				count++;
				if (count > 50) {

					leftCard[leftSelectedCard].cardClose();
					rightCard[rightSelectedCard].cardClose();
					leftSelectedCard = -1;
					rightSelectedCard = -1;
					count = 0;
				}
			}
		}
	}
	else if (GAME_STATE == GAME_END) {
		string txt = "Congratulations, You Finished In";
		gameEndFont.drawString(txt, ofGetWidth() / 2 - gameEndFont.stringWidth(txt) / 2, ofGetHeight() / 2);

		txt = ofToString(gamePlayTime);
		gameEndFont.drawString(txt, ofGetWidth() / 2 - gameEndFont.stringWidth(txt) / 2, ofGetHeight() / 2+150);

	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'f') {
		ofToggleFullscreen();
		cout << ofGetWidth() << endl;
		cout << ofGetHeight() << endl;
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (leftSelectedCard == -1) {
		for (int i = 0; i < 9; i++) {
			if (leftCard[i].isSelected(x, y)) {
				leftSelectedCard = i;
				return;
			}
		}
	}

	if (rightSelectedCard == -1) {
		for (int i = 0; i < 9; i++) {
			if (rightCard[i].isSelected(x, y)) {
				rightSelectedCard = i;
				return;
			}
		}
	}
	/*
	if(openCardNum == 0){
		for (int i = 0; i < 40; i++) {
			if (cards[i].isSelected(x, y)) {
				openCardNum++;
				selectedCard[0] = i;
				return;
			}
		}
	}
	else if (openCardNum == 1) {
		for (int i = 0; i < 40; i++) {
			if (cards[i].isSelected(x, y)) {
				openCardNum++;
				selectedCard[1] = i;
				return;
			}
		}
	}*/
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
