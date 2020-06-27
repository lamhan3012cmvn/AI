#include "RandExpectimax.h"
#include<algorithm>
#include<time.h>
Node* RandExpectimax::newNode(int v)
{
	Node* temp = new Node;
	temp->value = v;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

float RandExpectimax::expectimax(Node* node, bool is_max)
{
	if (node->left == NULL
		&& node->right == NULL) {
		return node->value;
	}

	// Maximizer node. Chooses the max from the 
	// left and right sub-trees 
	if (is_max) {
		return max(
			expectimax(
				node->left, false),
			expectimax(node->right, false));
	}

	// Chance node. Returns the average of 
	// the left and right sub-trees 
	else {
		return (
			expectimax(node->left, true)
			+ expectimax(node->right, true))
			/ 2.0;
	}
}

void RandExpectimax::createNode(Node* node, int depth)
{
	return;
}
int RandExpectimax::random()
{
	Node* root = newNode(0);
	//int depth = 0;
	/*createNode(root->left,depth);
	createNode(root->right, depth);
	*/
	//depth=1;
	root->left = newNode(0);
	root->right = newNode(0);
	//depth=2;
	srand(time(NULL));

	root->left->left=newNode(rand()%10+1);
	root->left->right= newNode(rand() % 10 + 1);
	root->right->left= newNode(rand() % 10 + 1);
	root->right->right= newNode(rand() % 10 + 1);
	return  expectimax(root, true);
}
