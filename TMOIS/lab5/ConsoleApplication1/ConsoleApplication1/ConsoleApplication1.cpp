#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Correspondence
{
private:
	class Graph
	{
	public:
		string x, y;
		Graph(string, string);
		string GetX();
		string GetY();
		void SetX(string);
		void SetY(string);
	};
	vector<Graph> graph;
	vector<string> X;
	vector<string> Y;
public:
	Correspondence();
	void Print();
	Correspondence intersection(Correspondence&);
	Correspondence union_(Correspondence&);
	Correspondence difference(Correspondence&);
	Correspondence composition(Correspondence&);
	Correspondence inversion();
	vector<string> image(vector<string>);
	vector<string> prototype(vector<string>);
	Correspondence constriction(vector<string>);
	Correspondence continuation();
	bool check_sim(string, string, vector<Graph>);
	void SetX(vector<string>);
	void SetY(vector<string>);
	void SetGraph(vector<Graph>);
	void MakeGraph();
	void MakeGraph1();
};

Correspondence::Correspondence()
{

}
void Correspondence::Print()
{
	cout << "Область отправления: ";
	for (int i = 0; i < X.size(); i++)
	{
		cout << X[i] << " ";
	}
	cout << "\nОбласть прибытия: ";
	for (int i = 0; i < Y.size(); i++)
	{
		cout << Y[i] << " ";
	}
	cout << "\nГрафик: ";
	for (int i = 0; i < graph.size(); i++)
	{
		cout << "<" << graph[i].GetX() << "," << graph[i].GetY() << ">";
		if (i + 1 != graph.size())
		{
			cout << ',';
		}
	}
	cout << "\n----------------------------------------------\n";
}
Correspondence Correspondence::intersection(Correspondence& other)
{
	Correspondence answer;
	vector<string> answerX;
	vector<string> answerY;
	vector<Graph> answerGraph;
	for (int i = 0; i < this->X.size(); i++)
	{
		for (int j = 0; j < other.X.size(); j++)
		{
			if (this->X[i] == other.X[j])
			{
				answerX.push_back(this->X[i]);
			}
		}
	}
	for (int i = 0; i < this->Y.size(); i++)
	{
		for (int j = 0; j < other.Y.size(); j++)
		{
			if (this->Y[i] == other.X[j])
			{
				answerY.push_back(this->Y[i]);
			}
		}
	}
	for (int i = 0; i < this->graph.size(); i++)
	{
		for (int j = 0; j < other.graph.size(); j++)
		{
			if (this->graph[i].GetX() == other.graph[j].GetX() && this->graph[i].GetY() == other.graph[j].GetY())
			{
				Graph temp(this->graph[i].GetX(), this->graph[i].GetY());
				answerGraph.push_back(temp);
			}
		}
	}
	answer.SetGraph(answerGraph);
	answer.SetX(answerX);
	answer.SetY(answerY);
	return answer;
}
Correspondence Correspondence::union_(Correspondence& other)
{
	Correspondence answer;
	vector<string> answerX = this->X;
	vector<string> answerY = this->Y;
	vector<Graph> answerGraph = this->graph;
	for (int i = 0; i < other.X.size(); i++)
	{
		bool check = true;
		for (int j = 0; j < this->X.size(); j++)
		{
			if (this->X[j] == other.X[i])
			{
				check = false;
			}
		}
		if (check)
		{
			answerX.push_back(other.X[i]);
		}
	}
	for (int i = 0; i < other.Y.size(); i++)
	{
		bool check = true;
		for (int j = 0; j < this->Y.size(); j++)
		{
			if (this->Y[j] == other.Y[i])
			{
				check = false;
			}
		}
		if (check)
		{
			answerY.push_back(other.Y[i]);
		}
	}
	for (int i = 0; i < other.graph.size(); i++)
	{
		bool check = true;
		for (int j = 0; j < this->graph.size(); j++)
		{
			if (this->graph[j].GetX() == other.graph[i].GetX() && this->graph[j].GetY() == other.graph[i].GetY())
			{
				check = false;
			}
		}
		if (check)
		{
			Graph temp(other.graph[i].GetX(), other.graph[i].GetY());
			answerGraph.push_back(temp);
		}
	}
	answer.SetGraph(answerGraph);
	answer.SetX(answerX);
	answer.SetY(answerY);
	return answer;
}
Correspondence Correspondence::difference(Correspondence& other)
{
	Correspondence answer;
	vector<string> answerX;
	vector<string> answerY;
	vector<Graph> answerGraph;
	for (int i = 0; i < this->X.size(); i++)
	{
		bool check = true;
		for (int j = 0; j < other.X.size(); j++)
		{
			if (this->X[i] == other.X[j])
			{
				check = false;
			}
		}
		if (check)
		{
			answerX.push_back(this->X[i]);
		}
	}
	for (int i = 0; i < this->Y.size(); i++)
	{
		bool check = true;
		for (int j = 0; j < other.Y.size(); j++)
		{
			if (this->Y[i] == other.Y[j])
			{
				check = false;
			}
		}
		if (check)
		{
			answerY.push_back(this->Y[i]);
		}
	}
	for (int i = 0; i < this->graph.size(); i++)
	{
		bool check = true;
		for (int j = 0; j < other.graph.size(); j++)
		{
			if (this->graph[i].GetX() == other.graph[j].GetX() && this->graph[i].GetY() == other.graph[j].GetY())
			{
				check = false;
			}
		}
		if (check)
		{
			answerGraph.push_back(this->graph[i]);
		}
	}
	answer.SetGraph(answerGraph);
	answer.SetX(answerX);
	answer.SetY(answerY);
	return answer;
}
Correspondence Correspondence::composition(Correspondence& other)
{
	Correspondence answer;
	vector<string> answerX = this->X;
	vector<string> answerY = other.Y;
	vector<Graph> answerGraph;
	for (int i = 0; i < this->graph.size(); i++)
	{
		for (int j = 0; j < other.graph.size(); j++)
		{
			if (this->graph[i].GetY() == other.graph[j].GetX())
			{
				if (check_sim(this->graph[i].GetY(), other.graph[j].GetX(), answerGraph))
				{
					Graph temp(this->graph[i].GetX(), other.graph[j].GetY());
					answerGraph.push_back(temp);
				}
			}
		}
	}
	answer.SetX(answerX);
	answer.SetY(answerY);
	answer.SetGraph(answerGraph);
	return answer;
}
Correspondence Correspondence::inversion()
{
	Correspondence answer;
	vector<string> answerX = this->Y;
	vector<string> answerY = this->X;
	vector<Graph> answerGraph;
	for (int i = 0; i < this->graph.size(); i++)
	{
		Graph temp(this->graph[i].GetY(), this->graph[i].GetX());
		answerGraph.push_back(temp);
	}
	answer.SetX(answerX);
	answer.SetY(answerY);
	answer.SetGraph(answerGraph);
	return answer;
}
vector<string> Correspondence::image(vector<string> changing)
{
	vector<string> answer;
	for (int i = 0; i < changing.size(); i++)
	{
		for (int j = 0; j < X.size(); j++)
		{
			if (changing[i] == X[j])
			{
				for (int z = 0; z < graph.size(); z++)
				{
					if (graph[z].GetX() == changing[i] && graph[z].GetY() != changing[i])
					{
						bool check = true;
						for (int k = 0; k < answer.size(); k++)
						{
							if (graph[z].GetY() == answer[k])
							{
								check = false;
								break;
							}
						}
						if (check)
						{
							answer.push_back(graph[z].GetY());
						}
					}
				}
			}
		}
	}
	return answer;
}
vector<string> Correspondence::prototype(vector<string> changing)
{
	vector<string> answer;
	for (int i = 0; i < changing.size(); i++)
	{
		for (int j = 0; j < Y.size(); j++)
		{
			if (changing[i] == Y[j])
			{
				for (int z = 0; z < graph.size(); z++)
				{
					if (graph[z].GetY() == changing[i] && graph[z].GetX() != changing[i])
					{
						bool check = true;
						for (int k = 0; k < answer.size(); k++)
						{
							if (answer[k] == graph[z].GetX())
							{
								check = false;
								break;
							}
						}
						if (check)
						{
							answer.push_back(graph[z].GetX());
						}
					}
				}
			}
		}
	}
	return answer;
}
Correspondence Correspondence::constriction(vector<string> changing)
{
	Correspondence answer;
	answer.SetX(X);
	answer.SetY(Y);
	vector<Graph> answerGraph;
	for (int i = 0; i < changing.size(); i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			if (graph[j].GetX() == changing[i])
			{
				Graph temp(graph[j].GetX(), graph[j].GetY());
				answerGraph.push_back(temp);
			}
		}
	}
	answer.SetGraph(answerGraph);
	return answer;
}
Correspondence Correspondence::continuation()
{
	Correspondence answer;
	answer.SetX(X);
	answer.SetY(Y);
	vector<Graph> answerGraph;
	for (int i = 0; i < X.size(); i++)
	{
		for (int j = 0; j < Y.size(); j++)
		{
			Graph temp(X[i], Y[j]);
			answerGraph.push_back(temp);
		}
	}
	answer.SetGraph(answerGraph);
	return answer;
}
bool Correspondence::check_sim(string x, string y, vector<Graph> answerGraph)
{
	for (int i = 0; i < answerGraph.size(); i++)
	{
		if (answerGraph[i].GetX() == x && answerGraph[i].GetY() == y)
		{
			return false;
		}
	}
	return true;
}
void Correspondence::SetX(vector<string> x)
{
	this->X = x;
}
void Correspondence::SetY(vector<string> y)
{
	this->Y = y;
}
void Correspondence::SetGraph(vector<Graph> graph)
{
	this->graph = graph;
}
void Correspondence::MakeGraph()
{
	vector<Graph> graph;
	cout << "Введите мощность графика G: ";
	int size;
	cin >> size;
	cout << "Введите элементы графика G: ";
	for (int i = 0; i < size; i++)
	{
		string x;
		string y;
		cin >> x >> y;
		Graph temp(x, y);
		graph.push_back(temp);
	}
	this->graph = graph;
}

void Correspondence::MakeGraph1()
{
	vector<Graph> graph;
	cout << "Введите мощность графика F: ";
	int size;
	cin >> size;
	cout << "Введите элементы графика F: ";
	for (int i = 0; i < size; i++)
	{
		string x;
		string y;
		cin >> x >> y;
		Graph temp(x, y);
		graph.push_back(temp);
	}
	this->graph = graph;
}

Correspondence::Graph::Graph(string x, string y)
{
	this->x = x;
	this->y = y;
}
string Correspondence::Graph::GetX() {
	return x;
}

string Correspondence::Graph::GetY()
{
	return y;
}
void Correspondence::Graph::SetX(string x)
{
	this->x = x;
}
void Correspondence::Graph::SetY(string y)
{
	this->y = y;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<string> x;
	vector<string> y;
	Correspondence A;
	cout << "Введите мощность множества Х: ";
	int size_x, size_y;
	cin >> size_x;
	cout << "Введите элементы множества X: ";
	for (int i = 0; i < size_x; i++)
	{
		string element;
		cin >> element;
		x.push_back(element);
	}
	cout << "Введите мощность множества Y: ";
	cin >> size_y;
	cout << "Введите элементы множества Y: ";
	for (int i = 0; i < size_y; i++)
	{
		string element;
		cin >> element;
		y.push_back(element);
	}
	A.SetX(x);
	A.SetY(y);
	A.MakeGraph();
	cout << "-----------------------------------" << endl;
	A.Print();
	Correspondence B;
	x.clear();
	y.clear();
	cout << "Введите мощность множества U: ";
	size_x = 0, size_y = 0;
	cin >> size_x;
	cout << "Введите элементы множества U: ";
	for (int i = 0; i < size_x; i++)
	{
		string element;
		cin >> element;
		x.push_back(element);
	}
	cout << "Введите мощность множества V: ";
	cin >> size_y;
	cout << "Введите элементы множества V: ";
	for (int i = 0; i < size_y; i++)
	{
		string element;
		cin >> element;
		y.push_back(element);
	}
	B.SetX(x);
	B.SetY(y);
	B.MakeGraph1();
	cout << "-----------------------------------" << endl;
	B.Print();
	int choise;
	cout << "1) - Оперция объединения" << endl << "2) - Операция пересечения" << endl
		<< "3) - Операция разности соответсвий Г1 и Г2" << endl	
		<< "4) - Операция симметрической разности" << endl
		<< "5) - Инверсия соответсвия Г1" << endl
		<< "6) - Композиция соответсвий Г1 и Г2	" << endl
		<< "7) - Образ соответсвия Г1" << endl
		<< "8) - Прообраз соответсвия Г1" << endl
		<< "9) - Сужение соответсвия Г1" << endl
		<< "10) - Продолжение соответсвия Г1" << endl;
	cin >> choise;
	switch (choise) {
	case 2: {
		Correspondence C; //Пересечение
		cout << "\nСоответствие А:\n";
		A.Print();
		cout << "Соответствие B:\n";
		B.Print();
		C = A.intersection(B);
		cout << "Пересечение:\n";
		C.Print();
		break;
	}
	case 1: {
		Correspondence D; //Обьединение
		D = A.union_(B);
		cout << "Обьединение:\n";
		D.Print();
		break;
	}
	case 3: {
		Correspondence E; //Разность AB
		Correspondence C;
		C = A.intersection(B);
		E = A.difference(C);
		cout << "Разность A\B:\n";
		E.Print();
		break;
	}
	case 4: {
		Correspondence G; //Симметрическая разность
		Correspondence E; 
		Correspondence C;
		Correspondence F; 
		E = A.difference(C);
		F = B.difference(C);
		C = A.intersection(B);
		E = A.difference(C);
		G = E.union_(F);
		cout << "Симметрическая разность:\n";
		G.Print();
		break;
	}
	case 6: {
		Correspondence H; //Композиция A*B
		H = A.composition(B);
		cout << "Композиция A*B:\n";
		H.Print();
		break;
	}
	case 5: {
		Correspondence J; //Инверсия B
		J = B.inversion();
		cout << "Инверсия В:\n";
		J.Print();
		break;
	}
	case 7: {
		cout << "Введите мощность множества A: ";
		int size;
		cin >> size;
		vector<string> A1;
		cout << "Введите элементы множества А: ";
		for (int i = 0; i < size; i++)
		{
			string temp;
			cin >> temp;
			A1.push_back(temp);
		}
		vector<string> K; //Образ
		cout << "Образ соответствия А:\n";
		K = A.image(A1);
		for (int i = 0; i < K.size(); i++)
		{
			cout << K[i];
			if (i + 1 != K.size())
			{
				cout << ",";
			}
		}
		break;
	}
	case 8: {
		cout << "Введите мощность множества A: ";
		int size;
		cin >> size;
		vector<string> A1;
		cout << "Введите элементы множества А: ";
		for (int i = 0; i < size; i++)
		{
			string temp;
			cin >> temp;
			A1.push_back(temp);
		}
		vector<string> L; //Прообраз
		cout << "Прообраз соответствия В:\n";
		L = A.prototype(A1);
		for (int i = 0; i < L.size(); i++)
		{
			cout << L[i];
			if (i + 1 != L.size())
			{
				cout << ",";
			}
		}
		break;
	}
	case 9: {
		cout << "Введите мощность множества A: ";
		int size;
		cin >> size;
		vector<string> A1;
		cout << "Введите элементы множества А: ";
		for (int i = 0; i < size; i++)
		{
			string temp;
			cin >> temp;
			A1.push_back(temp);
		}
		Correspondence M; //Сужение А на А1
		cout << "Сужение А на множестве А:\n";
		M = A.constriction(A1);
		M.Print();
		break;
	}
	case 10: {
		Correspondence N;
		cout << "Продолжение В:\n";
		N = B.continuation();
		N.Print();
		break;
	}
	}
	return 0;
}