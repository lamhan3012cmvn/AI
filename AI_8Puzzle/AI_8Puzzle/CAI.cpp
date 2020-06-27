#include "CAI.h"
#include <time.h>
#include <conio.h>


//left=1;
//right=2;
//up=3;
//down=4;
// người chơi

CNode* findMaxInListAndPop(vector<CNode*> &List)
{/*
	int index = -1;
	int maxValue = INT16_MAX;
	for (int i = 0; i < List.size(); i++)
	{
		if (maxValue > List[i]->getCost())
		{
			maxValue = List[i]->getCost();
			index = i;
		}
	}
	if (index == -1)
		return NULL;
	CNode* current = List[index];
	List.erase(List.begin() + index);
	return current;*/
	CNode* current = List[0];
	List.erase(List.begin() + 0);
	return current;
}

int solution(CNode* current)
{
	while (current->getParrent()->getParrent()!=NULL)
	{
		current = current->getParrent();
	}
	return current->getAction();
}
int findIndex(vector<CNode*> list,int find)
{
	if (list.size() == 0) return 0;
	else if (list.size() == 1) return list[0]->getCost() >= find ? 0 : 1;
	for (int i = 1; i < list.size(); i++)
	{
		if (find >= list[i - 1]->getCost() && find <= list[i]->getCost())
			return i;
		
	}
	return find<list[0]->getCost() ? 0 : find > list[list.size() - 1]->getCost() ? list.size(): list.size();
	
}
int CAI1::aStarSearch(CNode* root)
{
	vector<CNode*> LOpen;
	vector<CNode*> LClose;
	LOpen.push_back(root);
	
	while (LOpen.size()>0)
	{
		CNode* current = findMaxInListAndPop(LOpen);
		LClose.push_back(current);
		vector<CNode*> childs = current->getChilds();//done
		for (int i = 0; i < childs.size(); i++)
		{
			
			if (childs[i]->isGoal())
			{	
				return solution(childs[i]);
			}		
			if (!childs[i]->checkExist(LOpen) && !childs[i]->checkExist(LClose))
			{
				//LOpen.push_back(childs[i]);
				LOpen.insert(LOpen.begin() + findIndex(LOpen, childs[i]->getCost()), childs[i]);
			}
				
		}
	}
}
int CAI1::minValue(CNode *nextCurrent,int alpha, int beta, int depth)
{
	int score = nextCurrent->getScore();
	
	if (depth > this->depth || score!=0)
		return score;
	int bestScore = 1000;
	depth++;
	vector<CNode*> legalMoves = nextCurrent->getChilds();
	for (int i = 0; i < legalMoves.size(); i++)
	{
		legalMoves[i]->setPlayerOrCom(true);
		bestScore = min(bestScore, maxValue(legalMoves[i], alpha, beta, depth));
		beta = min(beta, bestScore);
		if (beta <= alpha)
		{
			return bestScore;
		}
	}
	return bestScore;
}
int CAI1::maxValue(CNode* nextCurrent,int alpha, int beta,int depth)
{
	int score = nextCurrent->getScore();

	if (depth > this->depth || score!=0)
		return score;
	int bestScore = -1000;
	depth++;
	vector<CNode*> legalMoves = nextCurrent->getChilds();
	for (int i = 0; i < legalMoves.size(); i++)
	{
		legalMoves[i]->setPlayerOrCom(false);
		bestScore = max(bestScore, minValue(legalMoves[i], alpha, beta, depth));
		alpha = max(alpha , bestScore);
		if (beta <= alpha)
		{
			return bestScore;
		}
	}
	return bestScore;
}
int CAI1::alphaBeta()
{
	Move bestMove;
	bestMove.score = -1000;
	int alpha = INT16_MIN;
	int beta = INT16_MAX;

	int score;
	int depth = 0;
	vector<CNode*> LegalMove = this->current->getChilds();
	for (int i = 0; i < LegalMove.size(); i++)
	{
		LegalMove[i]->setPlayerOrCom(false);
		score = minValue(LegalMove[i], alpha, beta, depth);

		if (score > bestMove.score)
		{
			bestMove.score = score;
			bestMove.index = LegalMove[i]->getAction();
		}
	}
	if (bestMove.score == 0)
	{
		int max = INT16_MIN;
		int move = rand() % 3 + 1;
		for (int i = 0; i < LegalMove.size(); i++)
		{
			if (max < LegalMove[i]->getCost())
			{
				max = LegalMove[i]->getCost();
				move = LegalMove[i]->getAction();
			}
		}
		return move;
	}
	return bestMove.index;
}
int CAI1::findMove(string state,string goal)
{

	this->current = new CNode(state, goal);
	//if (current->getCost() <= -10)
	//{
		return this->aStarSearch(current);
	/*}
	else {
		return alphaBeta();
	}*/
}

CAI1::CAI1(int depth)
{
	this->depth = depth;
	current = NULL;
}
