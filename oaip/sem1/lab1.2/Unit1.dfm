object Form1: TForm1
  Left = 330
  Top = 212
  Width = 1044
  Height = 540
  Caption = #1051#1072#1073'.'#1088#1072#1073'. 1, '#1075#1088'. 121703 '#1055#1088#1086#1082#1086#1087#1086#1074#1080#1095' '#1048'.'#1057'.'
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
    Top = 32
    Width = 16
    Height = 13
    Caption = 'X ='
  end
  object Label2: TLabel
    Left = 248
    Top = 32
    Width = 16
    Height = 13
    Caption = 'Y ='
  end
  object Label3: TLabel
    Left = 432
    Top = 32
    Width = 16
    Height = 13
    Caption = 'Z ='
  end
  object Label4: TLabel
    Left = 56
    Top = 72
    Width = 179
    Height = 13
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
  end
  object Edit1: TEdit
    Left = 88
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 272
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 456
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
  end
  object Memo1: TMemo
    Left = 56
    Top = 96
    Width = 569
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object Button1: TButton
    Left = 216
    Top = 192
    Width = 195
    Height = 25
    Caption = #1042#1067#1055#1054#1051#1053#1048#1058#1068
    TabOrder = 4
    OnClick = Button1Click
  end
end
