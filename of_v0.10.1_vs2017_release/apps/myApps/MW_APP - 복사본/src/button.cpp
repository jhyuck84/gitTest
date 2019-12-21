#include "button.h"



button::button()
{
}


button::~button()
{
}


void button::setup(float _x, float _y, float _w, float _h, ofImage _img)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;

	isPressed = false;
	img = _img;

}

void button::draw()
{
	ofFill();
	ofSetColor(255);
	img.draw(x, y, w, h);
}



bool button::isClick(float _mx, float _my)
{
	if (_mx > x && _mx<x + w && _my>y && _my < y + h) {
		isPressed = true;
		return true;
	}
	else {
		return false;
	}

}
