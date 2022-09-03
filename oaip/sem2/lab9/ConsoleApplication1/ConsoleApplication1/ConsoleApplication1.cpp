#include <iostream>
#include <cmath>

using namespace std;

double fun(double x)
{
   return (pow(x, 3) - 50 * cos(x));
}

double Vegst(double x0, double x1, double eps) {
    double x2 = 0, y0, y1, de = fabs(x0 - x1);
    y0 = fun(x0);
    y1 = fun(x1);
    while (de > eps) {
        x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
        de = fabs(x1 - x2);
        x0 = x1;
        x1 = x2;
        y0 = y1;
        y1 = fun(x2);
    }
    return x2;
}

int main()
{
    setlocale(LC_ALL, "ru");
    double esp = 0.000000001, a = -4, b = 3, h = 0.1;
    int num = 0;
    for (double x = a; x < b; x += h) {
        if (fun(x) * fun(x + h) < 0) {
            num += 1;
            cout << num << "-ый корень " << Vegst(x, x + h, esp) << endl;
            cout << " Проверка f(x) = " << fun(Vegst(x, x + h, esp)) << endl;
        }
    }

}


