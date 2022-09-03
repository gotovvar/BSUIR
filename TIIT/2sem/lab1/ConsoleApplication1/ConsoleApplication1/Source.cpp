#include "Header.h"
using namespace std;

RBTree::RBTree() {
	TNULL = new RBTNode;
	TNULL->color = 0;
	TNULL->left = nullptr;
	TNULL->right = nullptr;
	root = TNULL;
}

int RBTree::globalMinimum() {
	if (root == TNULL)
		return NULL;
	NodePatern node = root;
	while (node->left != TNULL)
		node = node->left;
	return node->data;
}

int RBTree::globalMaximum() {
	if (root == TNULL)
		return NULL;
	NodePatern node = root;
	while (node->right != TNULL)
		node = node->right;
	return node->data;
}

NodePatern RBTree::searchTreeHelper(NodePatern node, int key) {
	if (node == TNULL || key == node->data) 
		return node;

	if (key < node->data) 
		return searchTreeHelper(node->left, key);
	return searchTreeHelper(node->right, key);
}

int RBTree::nearestsmaller(int k) {
	if (k < globalMinimum() || root == TNULL)
		return NULL;
	else 
		while (true) {
			k--;
			if (searchTree(k) != TNULL)
				return searchTree(k)->data;
		}
}

int RBTree::nearestlarger(int k) {
	if (k > globalMaximum() || root == TNULL)
		return NULL;
	else 
		while (true) {
			k++;
			if (searchTree(k) != TNULL)
				return searchTree(k)->data;
		}
}

NodePatern RBTree::searchTree(int k) {
	if (root == TNULL)
		return TNULL;
	else
		return searchTreeHelper(this->root, k);
}

void RBTree::insert(int key) {
	if (searchTree(key) != TNULL)
		return;
	else {
		NodePatern node = new RBTNode;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1; // new node must be red

		NodePatern y = nullptr;
		NodePatern x = this->root;

		while (x != TNULL) {
			y = x;
			if (node->data < x->data) 
				x = x->left;
			else 
				x = x->right;
		}

		// y is parent of x
		node->parent = y;
		if (y == nullptr) 
			root = node;
		else if (node->data < y->data) 
			y->left = node;
		else 
			y->right = node;

		// if new node is a root node, simply return
		if (node->parent == nullptr) {
			node->color = 0;
			return;
		}

		// if the grandparent is null, simply return
		if (node->parent->parent == nullptr) 
			return;

		// Fix the tree
		fixInsert(node);
	}
}

void RBTree::fixInsert(NodePatern k) {
	NodePatern u;
	while (k->parent->color == 1) {
		if (k->parent == k->parent->parent->right) {
			u = k->parent->parent->left; // uncle
			if (u->color == 1) {
				// case 3.1
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			}
			else {
				if (k == k->parent->left) {
					// case 3.2.2
					k = k->parent;
					rightRotate(k);
				}
				// case 3.2.1
				k->parent->color = 0;
				k->parent->parent->color = 1;
				leftRotate(k->parent->parent);
			}
		}
		else {
			u = k->parent->parent->right; // uncle

			if (u->color == 1) {
				// mirror case 3.1
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			}
			else {
				if (k == k->parent->right) {
					// mirror case 3.2.2
					k = k->parent;
					leftRotate(k);
				}
				// mirror case 3.2.1
				k->parent->color = 0;
				k->parent->parent->color = 1;
				rightRotate(k->parent->parent);
			}
		}
		if (k == root) 
			break;
	}
	root->color = 0;
}

void RBTree::leftRotate(NodePatern x) {
	NodePatern y = x->right;
	x->right = y->left;
	if (y->left != TNULL) 
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == nullptr) 
		this->root = y;
	else if (x == x->parent->left) 
		x->parent->left = y;
	else 
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

void RBTree::rightRotate(NodePatern x) {
	NodePatern y = x->left;
	x->left = y->right;
	if (y->right != TNULL) 
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == nullptr) 
		this->root = y;
	else if (x == x->parent->right) 
		x->parent->right = y;
	else 
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}

void RBTree::deleteNode(int data) {
	if (searchTree(data) == TNULL)
		return;
	else
		deleteNodeHelper(this->root, data);
}	
void RBTree::deleteNodeHelper(NodePatern node, int key) {
	// find the node containing key
	NodePatern z = TNULL;
	NodePatern x, y;
	while (node != TNULL) {
		if (node->data == key) 
			z = node;
		if (node->data <= key) 
			node = node->right;
		else 
			node = node->left;
	}

	y = z;	
	int y_original_color = y->color;
	if (z->left == TNULL) {
		x = z->right;
		rbTransplant(z, z->right);
	}
	else if (z->right == TNULL) {
		x = z->left;
		rbTransplant(z, z->left);
	}
	else {
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) {
			x->parent = y;
		}
		else {
			rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	if (y_original_color == 0) {
		fixDelete(x);
	}
}

NodePatern RBTree::minimum(NodePatern node) {
	while (node->left != TNULL) {
		node = node->left;
	}
	return node;
}

void RBTree::rbTransplant(NodePatern u, NodePatern v) {
	if (u->parent == nullptr) 
		root = v;
	else if (u == u->parent->left) 
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

void RBTree::fixDelete(NodePatern x) {
	NodePatern s;
	while (x != root && x->color == 0) {
		if (x == x->parent->left) {
			s = x->parent->right;
			if (s->color == 1) {
				// case 3.1
				s->color = 0;
				x->parent->color = 1;
				leftRotate(x->parent);
				s = x->parent->right;
			}

			if (s->left->color == 0 && s->right->color == 0) {
				// case 3.2
				s->color = 1;
				x = x->parent;
			}
			else {
				if (s->right->color == 0) {
					// case 3.3
					s->left->color = 0;
					s->color = 1;
					rightRotate(s);
					s = x->parent->right;
				}

				// case 3.4
				s->color = x->parent->color;
				x->parent->color = 0;
				s->right->color = 0;
				leftRotate(x->parent);
				x = root;
			}
		}
		else {
			s = x->parent->left;
			if (s->color == 1) {
				// case 3.1
				s->color = 0;
				x->parent->color = 1;
				rightRotate(x->parent);
				s = x->parent->left;
			}

			if (s->left->color == 0 && s->right->color == 0) {
				// case 3.2
				s->color = 1;
				x = x->parent;
			}
			else {
				if (s->left->color == 0) {
					// case 3.3
					s->right->color = 0;
					s->color = 1;
					leftRotate(s);
					s = x->parent->left;
				}

				// case 3.4
				s->color = x->parent->color;
				x->parent->color = 0;
				s->left->color = 0;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = 0;
}