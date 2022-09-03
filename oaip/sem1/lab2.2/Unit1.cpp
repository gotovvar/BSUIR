//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Edit1->Text="1";
Edit2->Text="1";
Edit3->Text="4";
Memo1->Clear();
Memo1->Lines->Add("Лабораторная работа № 2");
RadioGroup1->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
double a,b,z,y,x;
a=StrToFloat(Edit1->Text);
b=StrToFloat(Edit2->Text);
z=StrToFloat(Edit3->Text);
if (z>0) x=sqrt(z);
else x=3*z+1;
switch(RadioGroup1->ItemIndex){
case 0: y=b*cos(a*2*x)+sin(x/5.)+a*exp(x);
Memo1->Lines->Add("y=   "+FloatToStrF(b*cos(a*2*x)+sin(x/5.)+a*exp(x),ffFixed,7,3));
break;
case 1: y=b*cos(a*pow(x,2))+sin(x/5.)+a*exp(x);
Memo1->Lines->Add("y=   "+FloatToStrF(b*cos(a*pow(x,2))+sin(x/5.)+a*exp(x),ffFixed,7,3));
break;
case 2: y=b*cos(a*x/3.)+sin(x/5.)+a*exp(x);
Memo1->Lines->Add("y=   "+FloatToStrF(b*cos(a*x/3.)+sin(x/5.)+a*exp(x),ffFixed,7,3));
break;
}
}
//---------------------------------------------------------------------------

