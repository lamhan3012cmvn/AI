#pragma once
#include"CPoint.h"
class CChar
{
private:
	int value;
	CPoint *point;
public:
	CChar(int value,CPoint *point);
	int getChar();
	CPoint* getPoint();
	void setPoint(int x, int y);
};

