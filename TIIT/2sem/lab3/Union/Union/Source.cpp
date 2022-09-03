#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "SetHelper.h"
#include <sstream>
#include <numeric>
using namespace std;
vector<string> Check(vector<string> arr)
{

	vector<string> buffer;
	vector<string> rez;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i][0] == '{') {
			buffer = divide_set(arr[i]);
			sort(buffer.begin(), buffer.end());
			buffer[0] = "{" + buffer[0];
			int last = buffer.size();
			buffer[last - 1] = buffer[last - 1] + "}";
			for (int i = 0; i < buffer.size(); i++) {
				if (i < buffer.size() - 1) {
					buffer[i] = buffer[i] + " ";
				}
			}
			ostringstream stream;
			copy(buffer.begin(), buffer.end(), std::ostream_iterator<string>(stream));
			string s = stream.str();
			rez.push_back(s);
		}
		else {
			rez.push_back(arr[i]);
		}
	}
	return rez;
}

vector<string> divide_set(std::string str) {
	vector<int> spaces;
	spaces.push_back(-1);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',') {
			spaces.push_back(i);
		}
	}
	int j, x = -2, kol = spaces.size();
	vector<string> words(kol);
	for (j = 0; j < kol; j++) {
		if (j + 1 < kol) {
			for (int i = spaces[j] + 2; i < spaces[j + 1]; i++) {
				words[j].push_back(str[i]);
				x = i;
			}
		}
		else
			for (int i = x + 3; i < str.length() - 1; i++) {
				words[j].push_back(str[i]);
			}

	}
	return words;
}

vector<string> divide_into_words(std::string str) {
	vector<int> spaces;
	spaces.push_back(-2);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ';') {
			spaces.push_back(i);
		}
	}
	int j, x = -2, kol = spaces.size();
	vector<string> words(kol);
	for (j = 0; j < kol; j++) {
		if (j + 1 < kol) {
			for (int i = spaces[j] + 2; i < spaces[j + 1]; i++) {
				words[j].push_back(str[i]);
				x = i;
			}
		}
		else
			if (spaces.size() != 1) {
				for (int i = x + 2; i < str.length(); i++) {
					words[j].push_back(str[i]);
				}
			}
	}
	return words;
}