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
Edit1->Text="0,1";
Edit2->Text="1";
Edit3->Text="10";
Edit4->Text="0,1";
Memo1->Clear();
Memo1->Lines->Add("������������ ������ � 3");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{ double x,a,b,h,y,s,f,rz;
int n=10, k;
a=StrToFloat(Edit1->Text);
b=StrToFloat(Edit2->Text);
n=StrToFloat(Edit3->Text);
h=StrToFloat(Edit4->Text);
for(x=a;x<=b;x+=h){
y=(exp(x)-exp(-x))/2;
f=1;
s=x;
for(k=1;k<=n;k++){
f=f*2*k*(2*k+1);
s=s+pow(x,2*k+1)/f;}
rz=fabs(y-s);
Memo1->Lines->Add("Y(x)="+FloatToStrF(y,ffFixed,8,6)+"   S(x)="+FloatToStrF(s,ffFixed,8,6) + "   |Y(x)-S(x)|="+FloatToStrF(rz,ffFixed,8,6));
}
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Memo1->Clear();
}
//---------------------------------------------------------------------------

