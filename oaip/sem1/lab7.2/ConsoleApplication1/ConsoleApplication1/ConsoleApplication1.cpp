#include <string>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string a;
    cout << "Введите слова" << endl;
    getline(cin, a);
    int b, c[80], p = 0;
    b = a.length();
    for (int i = 0; i <= b; i++) {
        if (a[i] == ' ' || a[i] == '\0') {
            c[p] = i + 1;
            p++;
        }
    }

    int max = 0, max1 = 0, n = 0, z = 0;
    max = max1 = c[0];
    n = 1;
    z = 1;
    for (int i = 1; i < p; i++) {
        if (max <= c[i] - c[i - 1]) {
            max = c[i] - c[i - 1];
            z = i + 1;
            n = c[i - 1] + 1;
        }
    }
    cout << "Количетво символов в слове " << max - 1 << endl << "Порядкой номер слова " << z << endl << "Номер с которого начинается слово " << n;
}


