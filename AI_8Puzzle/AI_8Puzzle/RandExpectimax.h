#pragma once
#include<iostream>
using namespace std;
struct Node
{
	int value;
	Node* left, * right;
};
class RandExpectimax
{
private:
	Node* newNode(int);
	float expectimax(Node*, bool);
	void createNode(Node*, int);
public:
	int random();
};

