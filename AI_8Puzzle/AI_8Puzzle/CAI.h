#pragma once
#include"CNode.h"
#include<math.h>
#include <algorithm>
#include "console.h"
#include<vector>
using namespace std;


struct Move
{
	int index;
	int score;
};
class CAI1
{
private:
	CNode *current;
	int depth;
	int minValue(CNode*,int alpha,int beta,int depth);
	int maxValue(CNode* ,int alpha, int beta, int depth);
	
public:
	CAI1(int depth);
	int findMove(string,string);
	int aStarSearch(CNode*);
	int alphaBeta();
};

