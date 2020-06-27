#include "CBoard.h"
#include<time.h>


CBoard::CBoard(string playerName,string playerName1, string Assigment, string Goal)
{
	this->assigment = Assigment;
	this->goal = Goal;
	initBoard();
	showBoard();
	this->listPlayer.push_back(new CPlayer(playerName));
	this->listPlayer.push_back(new CPlayer(playerName1));
	ai = NULL;
}

int costFunc(string Assigment,string Goal)
{
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Goal[i] == Assigment[j])
			{
				count += (abs(j % 3 - i % 3) + abs(j / 3 - i / 3))*(Assigment[i]-'0');
				break;
			}
		}
	}
	return count * -1;
}

CBoard::CBoard(string playerName,string Assigment,string Goal)
{
	this->assigment = Assigment;
	this->goal = Goal;
	initBoard();
	showBoard();
	this->listPlayer.push_back(new CPlayer(playerName));
	if (costFunc(this->assigment, this->goal) < -10)
	{
		this->flag = false;
		this->randomCom = 8;
		this->randomPlayer = 4;
	}
	else
	{
		this->flag = true;
		this->randomCom = 5;
		this->randomPlayer = 5;
	}
	ai = new CAI1(5);
	r = new RandExpectimax();
}
void CBoard::initBoard()
{
	for (int i = 0; i < this->nCell; i++)
	{
		if (this->assigment[i] != '0')
		{
			this->listCell.push_back(new CCell(this->assigment[i]-'0', this->vaulePointX[i], this->vaulePointY[i]));
		}
		if(this->goal[i]!='0')
			this->listCellGoal.push_back(new CCell(this->goal[i]-'0', this->vaulePointX[i] + 25, this->vaulePointY[i]));
			
	}

}
void createPaintPoint(int charactor,int x,int y)
{
	gotoXY(x, y);
	cout << char(charactor);
}
void CBoard::showBoard()
{
	if (this->listCell.size() != 0)
	{
		for (int i = 0; i < this->nCell-1; i++)
		{
			this->listCell[i]->show();
			this->listCellGoal[i]->show();
		}
	}

	createPaintPoint(218, this->vaulePointX[0]-4 , this->vaulePointY[0] - 2);
	createPaintPoint(218, this->vaulePointX[0] - 4+25, this->vaulePointY[0] - 2);
	for (int i = 1; i <20 ; i++)
	{
		createPaintPoint(196, this->vaulePointX[0] - 4+i, this->vaulePointY[0] - 2);
		createPaintPoint(196, this->vaulePointX[0] - 4 + 25+i, this->vaulePointY[0] - 2);
	}
	createPaintPoint(191, this->vaulePointX[8] + 4, this->vaulePointY[0] - 2);
	createPaintPoint(191, this->vaulePointX[8] + 4 + 25, this->vaulePointY[0] - 2);
	for (int i = 1; i < 10; i++)
	{
		createPaintPoint(179, this->vaulePointX[0] - 4, this->vaulePointY[0] - 2+i);
		createPaintPoint(179, this->vaulePointX[8] + 4 , this->vaulePointY[0] - 2+i);
		createPaintPoint(179, this->vaulePointX[0] - 4+25, this->vaulePointY[0] - 2+i);
		createPaintPoint(179, this->vaulePointX[8] + 4 + 25, this->vaulePointY[0] - 2+i);
	}


	createPaintPoint(192, this->vaulePointX[0] - 4, this->vaulePointY[8] + 2);
	createPaintPoint(192, this->vaulePointX[0] - 4 + 25, this->vaulePointY[8] + 2);
	for (int i = 1; i < 20; i++)
	{
		createPaintPoint(196, this->vaulePointX[0] - 4 + i, this->vaulePointY[8] + 2);
		createPaintPoint(196, this->vaulePointX[0] - 4 + 25 + i, this->vaulePointY[8] + 2);
	}
	createPaintPoint(217, this->vaulePointX[8] + 4, this->vaulePointY[8] + 2);
	createPaintPoint(217, this->vaulePointX[8] + 4 + 25, this->vaulePointY[8] + 2);

}
void CBoard::swap(int x, int y)
{
	int temp = this->assigment[x];
	this->assigment[x] = this->assigment[y];
	this->assigment[y] = temp;

}
bool CBoard::moveCurrentCell(int action)
{
	int indexAssigment = this->assigment.find('0');
	if (action == 1)
		return moveLeft(indexAssigment);
	else if (action == 2)
		return moveRight(indexAssigment);
	else if (action == 3)
		return moveUp(indexAssigment);
	else if (action == 4)
		return moveDown(indexAssigment);
	return false;
}
bool CBoard::moveLeft(int indexAssigment)
{
	if (indexAssigment % 3 != 2)
	{
		for (int i = 0; i < this->nCell - 1; i++)
		{
			if (this->listCell[i]->getValue() == this->assigment[indexAssigment + 1]-'0')
			{
				this->listCell[i]->moveLeft();
				swap(indexAssigment, indexAssigment + 1);
				return true;
			}
		}
	}
	return false;
}
bool CBoard::moveRight(int indexAssigment)
{
	if (indexAssigment % 3 != 0)
	{
		for (int i = 0; i < this->nCell - 1; i++)
		{
			if (this->listCell[i]->getValue() == this->assigment[indexAssigment - 1] - '0')
			{
				this->listCell[i]->moveRight();
				swap(indexAssigment, indexAssigment - 1);
				return true;
			}
		}
	}
	return false;
}
bool CBoard::moveUp(int indexAssigment)
{
	if (indexAssigment / 3 != 2)
	{
		for (int i = 0; i < this->nCell - 1; i++)
		{
			if (this->listCell[i]->getValue() == this->assigment[indexAssigment + 3] - '0')
			{
				this->listCell[i]->moveUp();
				swap(indexAssigment, indexAssigment + 3);
				return true;
			}
		}
	}
	return false;
}
bool CBoard::moveDown(int indexAssigment)
{
	if (indexAssigment / 3 != 0)
	{
		for (int i = 0; i < this->nCell - 1; i++)
		{
			if (this->listCell[i]->getValue() == this->assigment[indexAssigment - 3] - '0')
			{
				this->listCell[i]->moveDown();
				swap(indexAssigment, indexAssigment - 3);
				return true;
			}
		}
	}
	return false;
}

void CBoard::playGame() 
{
	int flag = true;
	if (this->listPlayer.size() >= 2)
	{
		while (flag) {
			flag=!playerVsPlayer();
		}
	}
	else
	{
		while (flag) {
			flag = !playerVsCom();
		}
	}
	return;
}

bool CBoard::playerVsPlayer()//true dừng game
{
	gotoXY(30, 15);
	cout << this->listPlayer[0]->getName() << "                                                         ";
	while (true)
	{
		if (moveCurrentCell(this->listPlayer[0]->playeTurn()) == true)
			break;
	}
	if (this->listPlayer[0]->isWin(assigment,goal) == true)
	{
		gotoXY(15, 15);
		cout<<this->listPlayer[0]->getNamePlayer();
		return true;
	}
	gotoXY(30, 15);
	cout << this->listPlayer[1]->getName() << "                                                         ";
	while (true)
	{
		if (moveCurrentCell(this->listPlayer[1]->playeTurn()) == true)
			break;
	}
	if (this->listPlayer[1]->isWin(assigment, goal) == true)
	{
		gotoXY(15, 15);
		cout << this->listPlayer[1]->getNamePlayer();
		return true;
	}
	return false;
}

string changeCoin(int index)
{
	string Coin[2] = { "500d","VND " };
	return Coin[index % 2];
}
void randCoinDisplay()
{

	int t = 0;
	while (t < 50)
	{
		gotoXY(30, 14);
		cout << changeCoin(t);
		t++;
		Sleep(80);
	}
}
bool CBoard::playerVsCom()
{
	gotoXY(15, 14);
	cout << "Rand Coin: ";
	gotoXY(15, 15);
	cout << "Current Turn: ";
	gotoXY(15, 16);
	cout << "Please choose actions ";
	while (true)
	{
		gotoXY(30, 15);
		cout << this->listPlayer[0]->getName() << "                                                         ";
		while (true)
		{
			if (moveCurrentCell(this->listPlayer[0]->playeTurn()) == true)
				break;
		}
		if (this->listPlayer[0]->isWin(assigment, goal) == true)
		{
			gotoXY(15, 19);
			cout << this->listPlayer[0]->getNamePlayer();
			return true;
		}
		if (!flag && costFunc(this->assigment, this->goal) >=-10)
		{
			this->randomPlayer = 5;
			this->randomCom = 5;
		}
		_getch();
		int randMove = r->random();
		randCoinDisplay();
		gotoXY(30, 14);
		if (randMove < this->randomPlayer)
			cout << "500d";// Người 500đ
		else
		{
			cout << "VND ";// May 500đ
			break;
		}
			
	}
	while (true)
	{
		gotoXY(30, 15);
		cout << "COM                  ";
		gotoXY(15, 16);
		cout << "                                                                       ";
		gotoXY(15, 17);
		cout << "                                                                       ";
		moveCurrentCell(this->ai->findMove(this->assigment, this->goal));
		if (isGoal() == true)
		{
			gotoXY(15, 19);
			cout << "Com win";
			return true;
		}
		if (!flag && costFunc(this->assigment, this->goal) > -10)
		{
			this->randomPlayer = 5;
			this->randomCom = 5;
		}
		Sleep(20);
		int randMove = r->random();
		randCoinDisplay();
		gotoXY(30, 14);
		if(r->random() < this->randomCom)
			cout << "VND ";
		else {
			cout << "500d";
			break;
		}
	}
	
	return false;
}

bool CBoard::isGoal()
{
	for (int i = 0; i < 9; i++)
	{
		if (this->assigment[i] != this->goal[i])
			return false;
	}
	return true;
}
