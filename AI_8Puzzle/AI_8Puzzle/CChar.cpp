#include "CChar.h"

CChar::CChar(int value,CPoint *point)
{
	this->value = value;
	this->point = point;
}

int CChar::getChar()
{
	return this->value;
}
CPoint* CChar::getPoint()
{
	return this->point;
}
void CChar::setPoint(int x, int y)
{
	if (this->point->getX() != x)
		this->point->setX(x);
	if (this->point->getY() != y)
		this->point->setY(y);
}