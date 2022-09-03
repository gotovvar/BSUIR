#pragma once
#include <iostream>

struct RBTNode
{
	bool color; // 1 = RED, 0= BLACK
	int data;
	RBTNode* left;
	RBTNode* right;
	RBTNode* parent;
};

typedef RBTNode* NodePatern;

class RBTree {
private:

	NodePatern searchTreeHelper(NodePatern node, int key);
	void fixDelete(NodePatern x);
	void rbTransplant(NodePatern u, NodePatern v);
	NodePatern minimum(NodePatern node);
	void deleteNodeHelper(NodePatern node, int key);
	void fixInsert(NodePatern k);
	void rightRotate(NodePatern x);
	void leftRotate(NodePatern x);

public:
	NodePatern root;
	NodePatern TNULL;

	RBTree();
	NodePatern searchTree(int k);
	int globalMinimum();
	int globalMaximum();
	int nearestsmaller(int k);
	int nearestlarger(int k);
	void insert(int key);
	void deleteNode(int data);
};


