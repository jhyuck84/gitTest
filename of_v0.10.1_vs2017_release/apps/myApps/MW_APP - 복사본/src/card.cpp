#include "card.h"



card::card()
{
}


card::~card()
{
}

card::card(float _x, float _y, float _w, float _h) 
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

void card::setup(float _x, float _y, float _w, float _h, int _num)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;

	cardNumber = _num;
	isOpen = false;

	cardNumFont.load("game_over.ttf", 100);

}

void card::draw()
{
	ofSetColor(0, 0, 100);
	ofFill();
	ofDrawRectangle(x, y, w, h);
	if (isOpen == true) {
		ofSetColor(255);
		ofFill();
		cardNumFont.drawString(ofToString(cardNumber), 
			x + w / 2 - cardNumFont.stringWidth(ofToString(cardNumber)) / 2, 
			y + h / 2 + cardNumFont.stringHeight(ofToString(cardNumber)) / 2);
		// ofDrawBitmapString(cardNumber, x + w / 2, y + h / 2);
	}
}

void card::setNum(int _num) {
	cardNumber = _num;
}

bool card::isSelected(float _mx, float _my) 
{
	if (!isOpen) {
		if (_mx > x && _mx<x + w && _my>y && _my < y + h) {
			isOpen = true;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void card::cardClose() {
	isOpen = false;
}