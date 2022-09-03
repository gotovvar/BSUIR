#include <iostream>
using namespace std;

double fun(int a);
double fun_r(int a);

int main()
{
	setlocale(LC_ALL, "ru");
	double rez;
	int k, n;
	cout << "Введите число n - ";
	cin >> n;
	cout << "Введите число k - ";
	cin >> k;
	while (true) {
		int c;
		cout << "1) - Обычная функция " << endl << "2) - Рекурсивная функция " << endl << "3) - Выход " << endl;
		cin >> c;
		switch (c) {
		case 1:
			rez = fun(n) / (fun(k) * fun(n - k));
			cout << "Результат - " << rez << endl;
			break;
		case 2:
			rez = fun_r(n) / (fun_r(k) * fun_r(n - k));
			cout << "Результат - " << rez << endl;
			break;
		case 3:
			return 0;
			break;
		}
	}
}

double fun(int a) {
	int b = 1;
	for (int i = 1; i <= a; i++) {
		b *= i;
	}
	return b;
}

double fun_r(int a) {
	if (a < 2)
		return 1;
	else
		return a * fun_r(a - 1);
}

