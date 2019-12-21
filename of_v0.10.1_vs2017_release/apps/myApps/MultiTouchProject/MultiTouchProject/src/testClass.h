#pragma once

#include "ofMain.h"

class testClass {

public:
	testClass();
	testClass(float _x, float _y, float _r);
	~testClass();
	void test();
	void test1(string input);
	void draw();
	void setCircle(float _x, float _y, float _r);
	void mouseCheck(float mx, float my);

	bool isOn;
	float x;
	float y;
	float r;

	string get_output();

	string output;

};
