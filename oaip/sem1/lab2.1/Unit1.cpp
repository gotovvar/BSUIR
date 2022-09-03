//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop
#include <conio.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
double y,x,z,a,b,u;
cout<< "Vvedite chislo z=";
cin >> z;
cout<<"Vvedite chislo a=";
cin>>a;
cout<<"Vvedite chislo b=";
cin>>b;
if(z>0) x=sqrt(z);
else x=3*z+1;
int c;
cout<< "1 - Znachenie f(x) ravno 2x"<<endl;
cout<< "2 - Znachenie f(x) ravno x^2"<<endl;
cout<< "3 - Znachenie f(x) ravno x/3"<<endl;
cin >> c;
switch (c)
{
case 1: u=2*x;
cout<< "Vi prisvoili znachenie f(x)=2x"<<endl;
break;
case 2: u=pow(x,2);
cout<< "Vi prisvoili znachenie f(x)=x^2"<<endl;
break;
case 3: u=x/3;
cout<< "Vi prisvoili znachenie f(x)=x/3"<<endl;
break;
default: cout<< "Oshibka!"<< endl;
getch ();
return 0;
}
y=b*cos(a*u)+sin(x/5.)+a*exp(x);
cout<< "y = " << y;
getch();

        return 0;
}
//---------------------------------------------------------------------------
 