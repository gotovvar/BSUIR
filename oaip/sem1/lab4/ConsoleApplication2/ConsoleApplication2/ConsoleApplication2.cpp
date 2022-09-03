#include <cmath>
#include <iostream>
using namespace std;
typedef double (*TFun)(double);

 double Y(double x) {
 return (exp(x) - exp(-x)) / 2;
 }

 double S(double x) {
     int n = 10;
     double k, f = 1, s = x;
     for (k = 1; k <= n; k++) {
         f = f * 2 * k * (2 * k + 1);
         s = s + pow(x, 2 * k + 1) / f;
     }
     return s;
 }

void Out_Rez(TFun f, TFun d, double a, double b, double h) {
    for (double x = a; x <= b; x += h) {
        cout << "|Y(x) - S(x)| = " << fabs(f(x)-d(x)) << endl;
    }
}

int main()
{
    double a, b, h;
    cin >> a;
    cin >> b;
    cin >> h;
    Out_Rez(Y, S, a, b, h);
    
}

