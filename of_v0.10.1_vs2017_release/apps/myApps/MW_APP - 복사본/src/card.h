#pragma once

#include "ofMain.h"

class card
{
public:
	card();
	card(float _x, float _y, float _w, float _h);
	~card();
	void setup(float _x, float _y, float _w, float _h, int num);
	void draw();
	void setNum(int _num);
	bool isSelected(float _mx, float _my);
	void cardClose();

	float x;
	float y;
	float w;
	float h;
	bool isOpen;

	ofTrueTypeFont cardNumFont;

	int cardNumber;
};

