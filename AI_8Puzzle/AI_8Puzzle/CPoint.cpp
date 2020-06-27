#include "CPoint.h"

CPoint::CPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CPoint::setX(int x)
{
	if(this->x!=x)
		this->x = x;
}
int CPoint::getX()
{
	return this->x;
}

void CPoint::setY(int x)
{
	if (this->y != y)
		this->y = y;
}
int CPoint::getY()
{
	return this->y;
}