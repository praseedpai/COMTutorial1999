// cppclient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cppclient.h"
#include "Addressobject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void DumpAddress( IAddress *Ptr );

BOOL CreateAddress( IAddress **pty );


/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int __cdecl _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
		return 1;
	}


	HRESULT hr;
	IUnknown *pIUnknown = NULL;
	IAddress *pt = NULL;
	IAddressList *ptlist; 



	//Initialize the COM Library
	hr = CoInitialize(NULL);

	if (SUCCEEDED(hr))
	{
		cout << "Com Library Successfuly initialised";
	}
	else
	{
		cout << "Error in Com DLL's";


	}

    hr = CoCreateInstance(CLSID_Address,
		NULL, CLSCTX_INPROC_SERVER, 
		IID_IUnknown, (LPVOID *)&pIUnknown);			

		if (!SUCCEEDED(hr))
		{
          cout << "Error Creating Com object";
		}


	hr = pIUnknown->QueryInterface(IID_IAddress, 
				(LPVOID *)&pt);

	if (!SUCCEEDED(hr))
		{
          cout << "Error Creating Com object";
		}

      pIUnknown->Release();

	  hr = CoCreateInstance(CLSID_AddressList,
		NULL, CLSCTX_INPROC_SERVER, 
		IID_IUnknown, (LPVOID *)&pIUnknown);			

		if (!SUCCEEDED(hr))
		{
          cout << "Error Creating Com object";
		}


	hr = pIUnknown->QueryInterface(IID_IAddressList, 
				(LPVOID *)&ptlist);

	if (!SUCCEEDED(hr))
		{
          cout << "Error Creating Com object";
		}

    pIUnknown->Release();
	
	pt->SetName("Name#1");
	pt->SetAddress1("Address1 #1");
    pt->SetAddress2("Address2 #1");
	pt->SetCity("City name #1");
	pt->SetCountry("Country #1");
	pt->SetState("State #1");
	pt->SetPinCode("Pin Code #1");

	ptlist->Add(pt);

    CreateAddress(&pt);
	
	pt->SetName("Name#2");
	pt->SetAddress1("Address1 #2");
    pt->SetAddress2("Address2 #2");
	pt->SetCity("City name #2");
	pt->SetCountry("Country #2");
	pt->SetState("State #2");
	pt->SetPinCode("Pin Code #2");
	
   	ptlist->Add(pt);
		
	CreateAddress(&pt);
	
	pt->SetName("Name#3");
	pt->SetAddress1("Address1 #3");
    pt->SetAddress2("Address2 #3");
	pt->SetCity("City name #3");
	pt->SetCountry("Country #3");
	pt->SetState("State #3");
	pt->SetPinCode("Pin Code #3");

	ptlist->Add(pt);

	CreateAddress(&pt);
	
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
	while (ptlist->Eof()== S_FALSE)
	{
      IAddress *m_pt=0;
      ptlist->GetData(&m_pt);
      ptlist->MoveNext();  
      DumpAddress(m_pt);
   	}

    cout << "Iterating List in Backward Direction" <<"\n";
	ptlist->MoveLast(); 
	while (ptlist->Bof() == S_FALSE)
	{
      IAddress *m_pt=0;
      ptlist->GetData(&m_pt);
      ptlist->MovePrevious();  
      DumpAddress(m_pt);
   	}


	ptlist->MoveFirst(); 
	while (ptlist->Eof()== S_FALSE)
	{
      IAddress *m_pt=0;
      ptlist->GetData(&m_pt);
      ptlist->MoveNext();  
      DumpAddress(m_pt);
	  m_pt->Release();
   	}

    ptlist->Release();






    
	return nRetCode;
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


BOOL CreateAddress( IAddress **pty )
{
   IUnknown *pIUnknown;

		HRESULT hr;
      hr = CoCreateInstance(CLSID_Address,
		NULL, CLSCTX_INPROC_SERVER, 
		IID_IUnknown, (LPVOID *)&pIUnknown);			

		if (!SUCCEEDED(hr))
		{
          cout << "Error Creating Com object";
		}


	hr = pIUnknown->QueryInterface(IID_IAddress, 
				(LPVOID *)pty);

	if (!SUCCEEDED(hr))
		{
          cout << "Error Creating Com object";
		}

      pIUnknown->Release();

return TRUE;

}
