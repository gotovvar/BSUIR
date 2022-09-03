#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Graph {
	int edge;
	int size;
	bool** matrix;
};

Graph* load_graph(const char* path)
{
	ifstream in;
	in.open(path);
	if (!in.is_open())
	{
		cout << "Error: cannot open file" << path << endl;
		exit(1);
	}

	Graph* graph = new Graph;

	in >> graph->edge;
	in >> graph->size;

	graph->matrix = new bool* [graph->size];
	for (int i = 0; i < graph->size; i++)
	{
		graph->matrix[i] = new bool[graph->edge];
	}

	for (int i = 0; i < graph->size; i++)
	{
		for (int j = 0; j < graph->edge; j++)
		{
			in >> graph->matrix[i][j];

		}

	}

	for (int i = 0; i < graph->size; i++)
	{
		for (int j = 0; j < graph->edge; j++)
		{
			cout << graph->matrix[i][j] << " ";

		}
		cout << endl;
	}

	return graph;
}

void delete_graph(Graph* graph) {
	for (int i = 0; i < graph->size; i++)
	{
		delete[] graph->matrix[i];
	}
	delete[] graph->matrix;
}

bool hamCycle(Graph* graph, int pos) {
	if (pos == graph->size)
	{
		for (int e1 = 0; e1 < graph->edge; e1++) {
			if (graph->matrix[0][e1] == 1)
				if (graph->matrix[pos - 1][e1] == 1)
					return true;
		}
		return false;
	}


	for (int e1 = 0; e1 < graph->edge; e1++)
		if (graph->matrix[pos - 1][e1] == 1)
			if (graph->matrix[pos][e1] == 1) {
				if (hamCycle(graph, pos + 1) == true)
					return true;
			}



	return false;
}

bool hamilton(Graph* graph) {
	if (hamCycle(graph, 1) == false)
	{
		cout << "The graph is not Hamiltonian\n" << endl;
		return false;
	}
	cout << "The graph is Hamiltonian\n" << endl;
	return true;

}


void run_test(int num, const char* path) {

	Graph* graph = load_graph(path);

	hamilton(graph);

	delete_graph(graph);

}


int main()
{
	run_test(1, "graph1.txt");

}




