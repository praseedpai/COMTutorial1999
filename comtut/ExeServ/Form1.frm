VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5715
   ClientLeft      =   1650
   ClientTop       =   1545
   ClientWidth     =   6585
   LinkTopic       =   "Form1"
   ScaleHeight     =   5715
   ScaleWidth      =   6585
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   1155
      Left            =   2520
      TabIndex        =   1
      Top             =   3270
      Width           =   2805
   End
   Begin VB.TextBox Text1 
      Height          =   645
      Left            =   2160
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   480
      Width           =   3465
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit


Private Sub Command1_Click()
Dim x As Expression
Dim y As String * 255
Dim r As Double
Dim ts As RESULTTYPE
Dim tp As Long
Set x = New Expression

x.SetExpr (Text1.Text)
 x.Evaluate tp

If (tp = DOUBLE_VAL) Then
  
   x.GetDoubleValue r
   
ElseIf (tp = ILLEGAL_VAL) Then
   Call x.GetError(ByVal y)
   MsgBox y
   Set x = Nothing
   Exit Sub
End If

MsgBox Str$(r)
Set x = Nothing
End Sub






