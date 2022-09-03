#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int len, k = 0, max = 0, n = 0, z = 0, max1 = 0;
	int b[100];
	cout << "Введите слова" << endl;
	char a[100];
	gets_s(a);
	len = strlen(a);
	for (int i = 0; i <= len; i++) {
		if (a[i] == ' ' || a[i] == '\0') {
			b[k] = i+1;
			k++;
		}
	}
	
	max = max1 = b[0]; 
	n = 1;
	z = 1;
	for (int i = 1; i < k; i++) {
		if (max <= b[i] - b[i - 1]) {
			max = b[i] - b[i - 1];
			z = i + 1;
			n = b[i-1] + 1;
		}
	}
	cout << "Количетво символов в слове " << max - 1 << endl << "Порядкой номер слова " << z << endl << "Номер с которого начинается слово " << n;
}

