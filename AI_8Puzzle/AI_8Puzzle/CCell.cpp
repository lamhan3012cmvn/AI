#include "CCell.h"

CCell::CCell(int value, int x_cellVaule, int y_cellVaule)
{
	this->value = value;
	this->x_valueCell = x_cellVaule;
	this->y_valueCell = y_cellVaule;
	
	Border.push_back(new CChar(218,new CPoint(x_cellVaule-2,y_cellVaule-1)));
	Border.push_back(new CChar(196, new CPoint(x_cellVaule - 1, y_cellVaule - 1)));
	Border.push_back(new CChar(196, new CPoint(x_cellVaule, y_cellVaule - 1)));
	Border.push_back(new CChar(196, new CPoint(x_cellVaule + 1, y_cellVaule - 1)));
	Border.push_back(new CChar(191, new CPoint(x_cellVaule + 2, y_cellVaule - 1)));

	Border.push_back(new CChar(179, new CPoint(x_cellVaule - 2, y_cellVaule )));
	Border.push_back(new CChar(179, new CPoint(x_cellVaule + 2, y_cellVaule)));

	Border.push_back(new CChar(192, new CPoint(x_cellVaule - 2, y_cellVaule + 1)));
	Border.push_back(new CChar(196, new CPoint(x_cellVaule - 1, y_cellVaule + 1)));
	Border.push_back(new CChar(196, new CPoint(x_cellVaule, y_cellVaule + 1)));
	Border.push_back(new CChar(196, new CPoint(x_cellVaule + 1, y_cellVaule + 1)));
	Border.push_back(new CChar(217, new CPoint(x_cellVaule + 2, y_cellVaule + 1)));

}
void CCell::move(int m,bool flag,int num)
{
	for (int i = 1; i <= num; i++)
	{
		this->Border.clear();
		Sleep(100);
		for (int j = 0; j < this->nClear; j++)
		{
			gotoXY(this->x_valueCell + this->clearX[j], this->y_valueCell + this->clearY[j]);
			cout << " ";
		}
		if (flag)
			this->x_valueCell += m;
		else this->y_valueCell += m;

		Border.push_back(new CChar(218, new CPoint(x_valueCell - 2, y_valueCell - 1)));
		Border.push_back(new CChar(196, new CPoint(x_valueCell - 1, y_valueCell - 1)));
		Border.push_back(new CChar(196, new CPoint(x_valueCell, y_valueCell - 1)));
		Border.push_back(new CChar(196, new CPoint(x_valueCell + 1, y_valueCell - 1)));
		Border.push_back(new CChar(191, new CPoint(x_valueCell + 2, y_valueCell - 1)));

		Border.push_back(new CChar(179, new CPoint(x_valueCell - 2, y_valueCell)));
		Border.push_back(new CChar(179, new CPoint(x_valueCell + 2, y_valueCell)));

		Border.push_back(new CChar(192, new CPoint(x_valueCell - 2, y_valueCell + 1)));
		Border.push_back(new CChar(196, new CPoint(x_valueCell - 1, y_valueCell + 1)));
		Border.push_back(new CChar(196, new CPoint(x_valueCell, y_valueCell + 1)));
		Border.push_back(new CChar(196, new CPoint(x_valueCell + 1, y_valueCell + 1)));
		Border.push_back(new CChar(217, new CPoint(x_valueCell + 2, y_valueCell + 1)));
	
		show();
	}
}
void CCell::moveLeft()
{
	move(-2,true,3);
}
void CCell::moveRight()
{
	move(2,true,3);
}
void CCell::moveUp()
{
	move(-1, false,3);
}
void CCell::moveDown()
{
	move(1, false,3);
}

void CCell::show()
{
	if (this->value != 0)
	{
		for (int i = 0; i < this->Border.size(); i++)
		{
			gotoXY(this->Border[i]->getPoint()->getX(), this->Border[i]->getPoint()->getY());
			cout << char(this->Border[i]->getChar());
		}
		gotoXY(this->x_valueCell,this->y_valueCell);
		cout << this->value;
		gotoXY(25, 25);
	}
	
}
void CCell::setValue(int x)
{
	if (this->value != x)
		this->value = x;
}
int CCell::getValue()
{
	return this->value;
}