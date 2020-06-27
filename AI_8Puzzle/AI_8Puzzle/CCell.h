#pragma once
#include<list>
#include<iostream>
#include<vector>
#include"CChar.h"
#include"console.h"
using namespace std;
class CCell
{
private:
	int value;
	int x_valueCell;
	int y_valueCell;
	vector<CChar*>Border;
	int clearX[13] = {-2,-1,0,1,2,-2,2,-2,-1,0,1,2,0 };
	int clearY[13] = {-1,-1,-1,-1,-1,0,0,1,1,1,1,1,0};
	int nClear = 13;
	void move(int m,bool isFlagX,int num);
public:
	CCell(int value, int x_valueCell, int y_valueCell);
	
	void moveLeft();
	void moveUp();
	void moveDown();
	void moveRight();
	void show();
	void setValue(int x);
	int getValue();
};

