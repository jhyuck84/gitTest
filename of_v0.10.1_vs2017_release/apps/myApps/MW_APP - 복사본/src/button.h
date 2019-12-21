#pragma once

#include "ofMain.h"

class button
{
public:
	button();
	~button();
	void setup(float _x, float _y, float _w, float _h, ofImage _img);
	void draw();
	bool isClick(float _mx, float _my);

	float x;
	float y;
	float w;
	float h;

	bool isPressed;
	ofImage img;

};

