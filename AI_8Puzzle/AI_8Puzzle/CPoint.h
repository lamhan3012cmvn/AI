#pragma once
class CPoint
{
private:
	int x;
	int y;
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	CPoint(int x, int y);
};

