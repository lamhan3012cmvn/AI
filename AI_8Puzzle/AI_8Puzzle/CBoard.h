#pragma once
#include"CCell.h"
#include<conio.h>
#include"CPlayer.h"
#include"CAI.h"
#include"RandExpectimax.h"
class CBoard
{
private:
	//14-8=6
	int vaulePointX[9] = { 40,46,52,40,46,52,40,46,52 };
	int vaulePointY[9] = { 3,3,3,6,6,6,9,9,9 };
	string assigment;
	string goal = "012345678";
	int nCell = 9;
	vector<CCell*> listCell;
	vector<CCell*> listCellGoal;
	vector< CPlayer* > listPlayer;
	CAI1 *ai;
	RandExpectimax* r;

	int randomPlayer;
	int randomCom;
	bool flag;
	void initBoard();
	void showBoard();
	void swap(int x, int y);
	bool moveCurrentCell(int action);
	bool moveLeft(int);
	bool moveRight(int);
	bool moveUp(int);
	bool moveDown(int);
	bool playerVsPlayer();
	bool playerVsCom();
	bool isGoal();
public:
	CBoard(string playerName, string playerName1, string Assigment, string Goal);
	CBoard(string playerName,string Assigment, string Goal);
	void playGame();
};

