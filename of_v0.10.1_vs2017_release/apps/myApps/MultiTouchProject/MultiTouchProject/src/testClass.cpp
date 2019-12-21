#include "testClass.h"

testClass::testClass() {
	output = "Test 2 is this test!";
	isOn = false;
}

testClass::testClass(float _x, float _y, float _r) {
	output = "Test 2 is this test!";
	isOn = false;
	testClass::setCircle(_x, _y, _r);
}

testClass::~testClass() {

}

void testClass::test() {
	cout << "This is a test!" << endl;
}

void testClass::test1(string input) {
	cout << input << endl;
}

string testClass::get_output() {
	return output;
}

void testClass::setCircle(float _x, float _y, float _r) {
	x = _x;
	y = _y;
	r = _r;
}

void testClass::draw() {
	if (isOn) {
		ofSetHexColor(0xFF0000);
	}
	else {
		ofSetHexColor(0x0000FF);
	}
	ofFill();
	ofDrawCircle(x, y, r);
}

void testClass::mouseCheck(float mx, float my) {
	if (ofDist(x, y, mx, my) <= r) {
		isOn = true;
	}
	else {
		isOn = false;
	}
}