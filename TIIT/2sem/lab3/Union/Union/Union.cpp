#include <iostream>
#include <string>
#include "Set.h"
#include "SetHelper.h"
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < 4; i++) {
		stringstream ss;
		ss << i;
		string str = ss.str();
		string path = "Test" + str + ".txt";
		cout << "\n\nTest-" << i + 1 << "\n\n";
		ifstream fin(path);
		Set<string> sets;
		vector<string> set;
		while (!fin.eof()) {
			string STR;
			getline(fin, STR);
			set = divide_into_words(STR);
			set = Check(set);
			sets.addition(set);
		}
		vector<string> rez;
		cout << "Начальные множества\n";
		sets.PrintSets();
		try
		{
			rez = sets.union_allsets();
			cout << "\nОбъединение множеств\n";
			for (int i = 0; i < rez.size(); i++) {
				cout << rez[i] << " ";
			}
			cout << "\n";
		}
		catch (const exception& ex)
		{
			cout << ex.what();
		}
		cout << "\n\n";

	}
	return 0;
}


