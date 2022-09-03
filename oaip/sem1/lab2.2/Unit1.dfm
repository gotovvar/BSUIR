object Form1: TForm1
  Left = 192
  Top = 125
  Width = 1044
  Height = 540
  Caption = #1051#1072#1073'.'#1088#1072#1073'., '#1075#1088'. 121703 '#1055#1088#1086#1082#1086#1087#1086#1074#1080#1095' '#1048'.'#1057'.'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 48
    Width = 16
    Height = 13
    Caption = 'A ='
  end
  object Label2: TLabel
    Left = 64
    Top = 96
    Width = 16
    Height = 13
    Caption = 'B ='
  end
  object Label3: TLabel
    Left = 64
    Top = 144
    Width = 16
    Height = 13
    Caption = 'Z ='
  end
  object Edit1: TEdit
    Left = 88
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 88
    Top = 96
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 88
    Top = 144
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
  end
  object Memo1: TMemo
    Left = 88
    Top = 200
    Width = 281
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object Button1: TButton
    Left = 176
    Top = 296
    Width = 97
    Height = 25
    Caption = #1055#1059#1057#1050
    TabOrder = 4
    OnClick = Button1Click
  end
  object RadioGroup1: TRadioGroup
    Left = 368
    Top = 56
    Width = 185
    Height = 105
    Caption = #1042#1099#1073#1086#1088' '#1092#1091#1085#1082#1094#1080#1080
    Items.Strings = (
      'F(x)=2x'
      'F(x)=x^2'
      'F(x)=x/3')
    TabOrder = 5
  end
end
