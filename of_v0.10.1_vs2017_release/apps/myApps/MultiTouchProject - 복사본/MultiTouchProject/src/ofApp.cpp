#include "ofApp.h"
#include "ofxWin8Touch.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofxWin8TouchSetup();
	ofRegisterTouchEvents(this);
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofNoFill();
	ofSetColor(225);

	
	//cout << touchMap.count << endl;

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
				ofLine(touch1.x, touch1.y, touch2.x, touch2.y);
				float dist = ofDist(touch1.x, touch1.y, touch2.x, touch2.y);

				ofVec2f pos;
				pos.set((touch1.x+touch2.x)/2, (touch1.y + touch2.y) / 2);
				float angle = atan2(touch2.y-touch1.y, touch2.x - touch1.x);

				
				//ofDrawBitmapString(dist, pos.x, pos.y);

				int id;
				id = 0;
				
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
					//ofRect(0, 0, 500, 500);
					ofPopMatrix();

					box_pos[box_counter] = ofVec2f(pos.x, pos.y);
					box_angle[box_counter] = angle;
					box_counter++;
				}
			}

		}
		ofDrawBitmapString(box_counter, 100, 100);
		for (int i = 0; i < box_counter; i++) {
			ofDrawBitmapString(box_pos[i], 100, 120+i*20);
		}
		
		
		//ofNoFill();
		//ofSetColor(225);
		//ofDrawBitmapString(rcnt, 100, 160);
		
		
		/*auto &touch = i->second;
		ofPushMatrix();
		ofTranslate(touch.x, touch.y);
		ofEllipse(0, 0, 50, 50);
		ofPopMatrix();
		*/
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

			//ofSetColor(255, 0, 0, 30);
			//ofFill();
			//ofSetCircleResolution(99);
			//ofDrawCircle(box_pos[i].x, box_pos[i].y, 300);

			ofSetColor(255, 255, 255, 100);
			ofFill();
			//ofDrawBitmapString(rcnt, box_pos[i].x, box_pos[i].y);
			float dot_angle = ofRadToDeg(box_angle[i]);
			ofDrawBitmapString(dot_angle, 500, 100);
			for (int j = 0; j < 4; j++) {
				ofPath path;
				if (j == 0) {
				
					if (dot_angle > 0 && dot_angle < 90) {
						path.setFillColor(ofColor(0, 0, 255));
					}
					else {
						path.setFillColor(ofColor(0, 0, 255, 50));
					}

					path.moveTo(box_pos[i].x+400, box_pos[i].y);
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

					path.moveTo(box_pos[i].x, box_pos[i].y-400);
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

					path.moveTo(box_pos[i].x-400, box_pos[i].y);
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

					path.moveTo(box_pos[i].x, box_pos[i].y+400);
					path.setArcResolution(99);
					path.arc(box_pos[i].x, box_pos[i].y, 400, 400, 90, 180);
					path.lineTo(box_pos[i].x, box_pos[i].y);
					path.draw();
				}
			}



			float markX = box_pos[i].x + 300 * cos(box_angle[i]);
			float markY = box_pos[i].y + 300 * sin(box_angle[i]);

			ofSetColor(255);
			ofFill();
			ofSetCircleResolution(99);
			ofDrawCircle(markX, markY, 10);
		}
	}
	
	
	/*
	for (auto &i : touchMap) {
		
		auto &touch = i.second;
		ofPushMatrix();
		ofTranslate(touch.x, touch.y);
		ofEllipse(0, 0, 50,50);
		ofPopMatrix(); 
		sum++;
	}*/

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
