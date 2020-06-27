#include "CNode.h"
#include "console.h"
#include<algorithm>


void CNode::swap(string &current,int i, int j)
{
	char temp = current[i];
	current[i] = current[j];
	current[j] = temp;
}
//1
void CNode::moveLeft(int index)
{
	if (index % 3 != 2)
	{
		string current = this->state;
		swap(current, index, index + 1);
		CNode *child = new CNode(current,this->Goal);
		child->action = 1;
		child->cost = child->costFunc()+ this->getDepth();
		child->depth = this->getDepth() + 1;
		child->nodeParent = this;
		this->childNode.push_back(child);
	}
}
//2
void CNode::moveRight(int index)
{
	if (index % 3 != 0)
	{
		string current = this->state;
		swap(current,index,index-1);
		CNode* child = new CNode(current, this->Goal);
		child->action = 2;
		child->cost = child->costFunc()+ this->getDepth();
		child->depth = this->getDepth() + 1;
		child->nodeParent = this;
		this->childNode.push_back(child);
	}
}
//3
void CNode::moveUp(int index)
{
	if (index / 3 != 2)
	{
		string current = this->state;
		swap(current, index, index + 3);
		CNode* child = new CNode(current, this->Goal);
		child->action = 3;
		child->cost = child->costFunc()+ this->getDepth();
		child->depth = this->getDepth() + 1;
		child->nodeParent = this;
		this->childNode.push_back(child);
	}
}
//4
void CNode::moveDown(int index)
{
	if (index / 3 != 0)
	{
		string current = this->state;
		swap(current, index, index - 3);
		CNode* child = new CNode(current, this->Goal);
		child->action = 4;
		child->cost = child->costFunc()+ this->getDepth();
		child->depth = this->getDepth() + 1;
		child->nodeParent = this;
		this->childNode.push_back(child);
	}
}

void CNode::move()
{
	int i = this->state.find('0');
	moveLeft(i);
	moveRight(i);
	moveUp(i);
	moveDown(i);
}


void CNode::setPlayerOrCom(bool check)
{
	this->PlayerOrCom = check ;
}

int CNode::getScore()
{
	if (this->isGoal() == true)
	{
		if (this->PlayerOrCom == true)
			return -10;
		else return 10;
	}
	return 0;
}

int CNode::getCost()
{
	return this->cost;
}

int CNode::getDepth()
{
	return this->depth;
}

bool CNode::checkExist(vector<CNode*> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->state==this->state)
			return true;
	}
	return false;
}

bool CNode::isGoal()
{
	if (this->state==this->Goal)
		return true;
	return false;
}
int CNode::costFunc()
{
	int count = 0;
	
	for (int i = 0; i < 9; i++)
	{
		int j = this->state.find(this->Goal[i]);
		count += (abs(j % 3 - i % 3) + abs(j / 3 - i / 3))*(this->state[j]-'0');
	}
	return count;
}



CNode::CNode(string state,string Goal)
{
	this->state = state;
	this->Goal = Goal;
	this->cost = costFunc();
	this->depth =0;
}

int CNode::getAction()
{
	return this->action;
}


vector<CNode*> CNode::getChilds()
{
	move();	
	return this->childNode;
}


CNode* CNode::getParrent()
{
	return this->nodeParent;
}