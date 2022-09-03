#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct Tree
{
	int value;
	Tree* left;
	Tree* right;
};

Tree* init(int inf)
{
	Tree* t = new Tree;
	t->value = inf;
	t->left = t->right = NULL;
	return t;
}
void add(Tree* root, int key)
{
	Tree* prev = NULL;
	Tree* t = NULL;
	bool find = true;
	t = root;
	while (t && find)
	{
		prev = t;
		if (key == t->value)
		{
			find = false;
			cout << "Invalid Key!" << endl;
		}
		else if (key < t->value)
		{
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}
	if (find)
	{
		t = init(key);
		if (key < prev->value)
		{
			prev->left = t;
		}
		else
		{
			prev->right = t;
		}
	}
}
void view(Tree* p, int level)
{
	string str;
	if (p)
	{
		view(p->right, level + 1);
		for (int i = 0; i < level; i++)
		{
			str = str + "     ";
		}
		cout << str << p->value << "\n";
		view(p->left, level + 1);
	}
}
Tree* del_info(Tree* root, int key)
{
	Tree* dlt = root;
	Tree* Prev_Del = NULL;
	Tree* R = NULL;
	Tree* Prev_R = NULL;
	while (dlt != NULL && dlt->value != key)
	{
		Prev_Del = dlt;
		if (dlt->value > key)
		{
			dlt = dlt->left;
		}
		else
		{
			dlt = dlt->right;
		}
	}
	if (dlt == NULL)
	{
		cout << "Invalid key!" << endl;
		return root;
	}

	if (dlt->right == NULL)
	{
		R = dlt->left;
	}
	else if (dlt->left == NULL)
	{
		R = dlt->right;
	}
	else
	{
		Prev_R = dlt;
		R = dlt->left;
		while (R->right != NULL)
		{
			Prev_R = R;
			R = R->right;
		}
		if (Prev_R == dlt)
		{
			R->right = dlt->right;
		}
		else
		{
			R->right = dlt->right;
			Prev_R->right = R->left;
			R->left = Prev_R;
		}
	}
	if (dlt == root)
	{
		root = R;
	}
	else if (dlt->value < Prev_Del->value)
	{
		Prev_Del->left = R;
	}
	else
	{
		Prev_Del->right = R;
	}
	delete dlt;
	return root;
}
void del(Tree* t)
{
	if (t != NULL)
	{
		del(t->left);
		del(t->right);
		delete t;
	}
}
void run(Tree* p, int* a, int* cnt) {
	if (p)
	{
		run(p->right, a, cnt);
		a[*cnt] = p->value;
		(*cnt)++;
		run(p->left, a, cnt);
	}
}
void ballance(Tree** p, int n, int k, int* a)
{
	if (n == k)
	{
		*p = NULL;
		return;
	}
	else
	{
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->value = a[m];
		ballance(&(*p)->left, n, m, a);
		ballance(&(*p)->right, m + 1, k, a);
	}
}
int height(Tree* v)
{
	if (v == NULL)
	{
		return 0;
	}
	int left, right;
	if (v->left != NULL)
	{
		left = height(v->left);
	}
	else
	{
		left = -1;
	}
	if (v->right != NULL)
	{
		right = height(v->right);
	}
	else
	{
		right = -1;
	}
	int max = left > right ? left : right;
	return max + 1;
}

int main()
{
	int val;
	cout << "Enter an initial node value: ";
	cin >> val;
	Tree* root = init(val);
	int count;
	cout << endl << "Enter a count of leafs: ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Enter a value of " << i << " node: ";
		cin >> val;
		add(root, val);
	}
	cout << endl << "Your tree: " << endl;
	view(root, 0);
	cout << "Enter a value to delete: ";
	cin >> val;
	del_info(root, val);
	system("cls");
	cout << endl << "Your tree: " << endl;
	view(root, 0);
	cout << "The hight of the left subtree is: " << height(root->left) + 1 << endl;
	system("pause");
	system("cls");
	cout << endl << "Initial tree: " << endl;
	view(root, 0);
	count = 0;
	int arr[256];
	run(root, arr, &count);
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << endl << "Ballanced tree: " << endl;
	ballance(&root, 0, count, arr);
	view(root, 0);
	system("pause");
	del(root);
}

