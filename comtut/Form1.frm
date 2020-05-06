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
      Height          =   495
      Left            =   3120
      TabIndex        =   0
      Top             =   4380
      Width           =   1875
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
Dim pAddress As Address
Dim pAddress1  As Address
Dim pAddressList As New AddressList
Dim pts As String * 1024

Set pAddress = New Address
pAddress.SetName ("Fool")
pAddress.SetCountry ("India")

Call pAddressList.Add(pAddress)

Set pAddress = New Address

pAddress.SetName ("Fool #1")
pAddress.SetCountry ("PakisthaN")

Call pAddressList.Add(pAddress)



Call pAddressList.MoveFirst
Call pAddressList.GetData(pAddress1)
Call pAddress1.GetName(pts)
'While (pAddressList.EOF() <> 0)
'  pAddressList.GetData (pAddress1)
'  pAddress1.GetName (pts)
'  Call pAddressList.MoveNext
'Wend

MsgBox "Successful "


End Sub

