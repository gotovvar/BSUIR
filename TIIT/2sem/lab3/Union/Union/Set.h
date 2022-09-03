#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
template <typename T>
class Set {
	vector<T> set;
	vector<vector<T>> sets;
	vector<T> union_(vector<T> arr1, vector<T> arr2);
public:
	~Set();
	void PrintSets();
	void addition(vector<T> arr);
	vector<T> union_allsets();
};

template<typename T>
void Set<T>::PrintSets()
{
	for (int i = 0; i < sets.size(); i++) {
		for (int j = 0; j < sets[i].size(); j++) {
			cout << sets[i][j] << " ";
		}
		cout << endl;
	}
}


template<typename T>
vector<T> Set<T>::union_(vector<T> arr1, vector<T> arr2)
{
	vector<T> rez;
	for (int i = 0; i < arr1.size(); i++) 
		rez.push_back(arr1[i]);
	for (int i = 0; i < arr2.size(); i++)
		if (find(rez.begin(), rez.end(), arr2[i]) == rez.end())
			rez.push_back(arr2[i]);
	return rez;
}


template<typename T>
Set<T>::~Set()
{
	sets.clear();
	set.clear();
}


template<typename T>
void Set<T>::addition(vector<T> arr)
{

	arr.pop_back();
	sets.push_back(arr);
}

template<typename T>
vector<T> Set<T>::union_allsets()
{
	if (sets.size() > 1) {
		set = union_(sets[0], sets[1]);
		for (int i = 2; i < sets.size(); i++) {
			set = union_(set, sets[i]);
		}
		sort(set.begin(), set.end());
		auto element = unique(set.begin(), set.end());
		set.erase(element, set.end());
		if (set.size() == 0) {
			throw exception("\nсимметрическая разность - пустое множество");
		}
		return set;
	}
	else throw exception("\nнекоректный ввод");
}

