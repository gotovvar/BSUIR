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
Edit1->Text="12,3e-1";
Edit2->Text="15,4";
Edit3->Text="0,252e+3";
Memo1->Clear();
Memo1->Lines->Add("Лабораторная работа № 1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Double x, y, z, g;
x=StrToFloat(Edit1->Text);
y=StrToFloat(Edit2->Text);
z=StrToFloat(Edit3->Text);
g=pow(y,x+1)/(pow(fabs(y-2),1.0/3)+3)+(x+y/2)/(2*fabs(x+y))*pow(x+1,-1/sin(z));
Memo1->Lines->Add("При x ="+FloatToStrF(x,ffFixed,7,3)+"; y="+FloatToStrF(y,ffFixed,7,3)+"; z="+FloatToStrF(z,ffFixed,7,3));
Memo1->Lines->Add("Результат ="+FloatToStr(g));
}
//---------------------------------------------------------------------------
