#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a[10], i, n, s = 0, p;
    srand(time(0));
    cout << "Vvedite razmer massiva, n<=10" << endl;
    cin >> n;
    cout << "1-Zapolnit' massiv sluchainimi chislami" << endl << "2-Vvesti massiv vruchnuy" << endl;
    cin >> p;
    switch (p) {
    case 1: {
        for (i = 0; i < n; i++) {
            a[i] = rand() % 10;
            cout << a[i] << " ";
        }
    }
          break;
    case 2: {
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
    } 
          break;
    default:
        cout << "Oshibka";
        return 0;
    }
      for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            for (i = i; i < n; i++) {
                s = s + abs(a[i]);
            }
        break;
        }
    }
    cout << s;
}


