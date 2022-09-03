//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{ double x,a,b,h,y,s,f,rz;
int n=10, k;
cout.precision(5);
cout << "Vvedite nachalnoe znachenie x=";
cin>> a;
cout << "Vvedite konechnoe znachenie x=";
cin>> b;
cout<< "Vvedite  shag uvelicheniya x=";
cin>> h;
for(x=a;x<=b;x+=h){
y=(exp(x)-exp(-x))/2;
f=1;                    //f факториал в знаменателе (начальное значение при k=0)
s=x;                    //начальное значение суммы (при k=0)
for(k=1;k<=n;k++){
f=f*2*k*(2*k+1);
s=s+pow(x,2*k+1)/f;
}
rz=fabs(y-s);
cout<<"\tS(x)= "<<s<<"  "<<"\tY(x)= "<<y<<"  "<< "\t|Y(x)-S(x)|= " <<rz<< endl;
}
getch();



        return 0;
}
//---------------------------------------------------------------------------
