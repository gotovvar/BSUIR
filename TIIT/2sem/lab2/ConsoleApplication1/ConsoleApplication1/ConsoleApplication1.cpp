#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

struct edge {int start, finish, cost;};

int main()
{

	ifstream in("maze.in");
	ofstream out("maze.out");

	int n, m;
	in >> n;
	in >> m;

	vector<edge> e;
	for (int i = 0; i < m; i++)
	{
		edge a;
		in >> a.start >> a.finish >> a.cost;
		a.start--;
		a.finish--;
		e.push_back(a);
	}
	vector<int> length (n, INT_MIN);
	vector<int> p (n, -1);
	length[0] = 0;
	bool x;
	for (int i = 0; i < n; i++) {
		x = false;
		for (int j = 0; j < m; j++)
			if ((length[e[j].start] > INT_MIN) && (length[e[j].finish] < length[e[j].start] + e[j].cost))
			{
				length[e[j].finish] = length[e[j].start] + e[j].cost;
				p[e[j].finish] = e[j].start;
				x = true;
			}
	}
	
	vector<int> path;
	int k = 0;
	for (int i = n - 1; i != -1; i = p[i])
	{
		k++;
		path.push_back(i);
		if (k > n) break;
	}
	if (length[n - 1] == INT_MIN) 
		out << ":(";
	else
		if ((x != false) && ((path.back() != 0) || (path.front() != n - 1) || (k > n))) 
			out << ":)";
		else 
			out << length[n - 1];
	return 0;
}