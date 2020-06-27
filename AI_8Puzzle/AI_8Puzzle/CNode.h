#pragma once
#include<vector>
#include<iostream>
using namespace std;
class CNode
{
private:
	string state;
	int action;
	CNode* nodeParent;
	int cost;
	int depth;
	bool PlayerOrCom;
	vector<CNode*> childNode;
	string Goal;

	void swap(string &,int,int);
	void moveLeft(int);
	void moveRight(int);
	void moveUp(int);
	void moveDown(int);
	int costFunc();
	void move();
public:
	CNode(string,string);
	int getAction();
	bool isGoal();
	void setPlayerOrCom(bool);
	int getScore();
	int getCost();
	int getDepth();

	CNode* getParrent();
	bool checkExist(vector<CNode*>);
	vector<CNode*> getChilds();
};

