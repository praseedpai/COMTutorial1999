#include "stdafx.h"
#include "BaseApp.h"
#include "Addressimpl.h"
#include "AddressListimpl.h"
#include "Dataaddress.h"

CWinApp theApp;
using namespace std;
void DumpAddress( IAddress *Ptr );
BOOL CreateObject( int id , void **objptr );
BOOL CreateObject01( int id , void **objptr );
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	if (!AfxWinInit(::GetModuleHandle(NULL), 
		NULL, ::GetCommandLine(), 0))
	{
	  cerr << _T("Fatal Error: MFC initialization failed") << endl;
	  return 1;
	}
	cout <<"Creating Address Object" << "\n";
	IAddressList *ptlist;
    if ( !CreateObject( 1 ,(void **) &ptlist ) )
	{
		cout << "this interface not supported\n";
		return FALSE;
	}
    IAddress *pt;
    if ( !CreateObject01( 1 ,(void **) &pt ) )
	{
		cout << "this interface not supported\n";
		return FALSE;
	}
	if ( pt == 0 )
		return 1;
    pt->SetName("Name#1");
	pt->SetAddress1("Address1 #1");
    pt->SetAddress2("Address2 #1");
	pt->SetCity("City name #1");
	pt->SetCountry("Country #1");
	pt->SetState("State #1");
	pt->SetPinCode("Pin Code #1");
	ptlist->Add(pt);
    pt = new CAddress();
	pt->SetName("Name#2");
	pt->SetAddress1("Address1 #2");
    pt->SetAddress2("Address2 #2");
	pt->SetCity("City name #2");
	pt->SetCountry("Country #2");
	pt->SetState("State #2");
	pt->SetPinCode("Pin Code #2");
   	ptlist->Add(pt);
	pt = new CAddress();
	pt->SetName("Name#3");
	pt->SetAddress1("Address1 #3");
    pt->SetAddress2("Address2 #3");
	pt->SetCity("City name #3");
	pt->SetCountry("Country #3");
	pt->SetState("State #3");
	pt->SetPinCode("Pin Code #3");
	ptlist->Add(pt);
	pt = new CAddress();
	pt->SetName("Name#4");
	pt->SetAddress1("Address1 #4");
    pt->SetAddress2("Address2 #4");
	pt->SetCity("City name #4");
	pt->SetCountry("Country #4");
	pt->SetState("State #4");
	pt->SetPinCode("Pin Code #4");
	ptlist->Add(pt);
    cout << "Iterating List in Forward Direction" <<"\n";
	ptlist->MoveFirst(); 
	while (!ptlist->Eof() )
	{
      IAddress *m_pt=0;
      ptlist->GetData(&m_pt);
      ptlist->MoveNext();  
      DumpAddress(m_pt);
   	}
    cout << "Iterating List in Backward Direction" <<"\n";
	ptlist->MoveLast(); 
	while (!ptlist->Bof() )
	{
      IAddress *m_pt=0;
      ptlist->GetData(&m_pt);
      ptlist->MovePrevious();  
      DumpAddress(m_pt);

   	}


 return 1;	
}
void DumpAddress( IAddress *Ptr )
{
  char buffer[255];

  cout <<"----------------------------------\n";
  Ptr->GetName(buffer);
  cout <<"Name = " << buffer << "\n";
  Ptr->GetAddress1(buffer);
  cout <<"Address1= " <<buffer  << "\n";
  Ptr->GetAddress2(buffer);
  cout <<"Address2= " << buffer << "\n";
  Ptr->GetCity(buffer);
  cout <<"City = " << buffer<< "\n";
  Ptr->GetState(buffer);
  cout <<"State = " << buffer<< "\n";
  Ptr->GetCountry(buffer);
  cout <<"Country = " << buffer<< "\n";
  Ptr->GetPinCode(buffer);
  cout <<"Pin = " << buffer<< "\n";
  cout <<"************************************\n\n\n";
}
BOOL CreateObject( int id , void **objptr )
{
      if ( id == 1 )
		{
			*objptr = (void *)(new CAddressList());
			return TRUE;
		}
		else if ( id == 2 )
		{   
            *objptr = (void *)(new TAddressList());
			return TRUE; 
		}
		else {
		   *objptr = 0;
	   return FALSE;
		}
}
BOOL CreateObject01( int id , void **objptr )
{
		*objptr = (void *)(new CAddress());
		return TRUE;
}

