#ifndef OBJ_IMPL_DOT_H
#define OBJ_IMPL_DOT_H
#include "afxtempl.h"
#include "AddressObject.h"

class CAddress : public IAddress
{
 private:
   ULONG m_cRef;
   char Name[50];
   char Address1[50];
   char Address2[50];
   char City[50];
   char State[50];
   char Country[50];
   char Pin[25];
 public:
   
   	//IUnknown
	STDMETHODIMP QueryInterface(REFIID iid, LPVOID *ppv);
	STDMETHODIMP_(ULONG)AddRef(void);
	STDMETHODIMP_(ULONG)Release(void);
	//IAddress
	STDMETHODIMP GetName(LPSTR str);
    STDMETHODIMP SetName( LPSTR  str);
    STDMETHODIMP GetAddress1(LPSTR  str );
    STDMETHODIMP SetAddress1(LPSTR  str );
    STDMETHODIMP GetAddress2(LPSTR  str);
    STDMETHODIMP SetAddress2(LPSTR  str);
    STDMETHODIMP GetCity(LPSTR   str);
    STDMETHODIMP SetCity(LPSTR   str); 
    STDMETHODIMP GetState( LPSTR   str);
    STDMETHODIMP SetState( LPSTR   str);
    STDMETHODIMP GetCountry( LPSTR  str);
    STDMETHODIMP SetCountry( LPSTR  str); 
    STDMETHODIMP GetPinCode( LPSTR  str);
    STDMETHODIMP SetPinCode( LPSTR  str);
	// ctor
    CAddress(); 

};


class CAddressFactory : public IClassFactory
{
private:
	ULONG			m_cRef;
public:
	//IUnknown
	STDMETHODIMP QueryInterface(REFIID iid, LPVOID *ppv);
    STDMETHODIMP_(ULONG)AddRef(void);
    STDMETHODIMP_(ULONG)Release(void);
	//IClassFactory
	STDMETHODIMP CreateInstance(IUnknown* pUnknownOuter, 
		REFIID iid, LPVOID *ppv);
	STDMETHODIMP LockServer(BOOL bLock);
	//Constructor
	CAddressFactory()
	{
		m_cRef = 0;
	}
};
///////////////////////////////////////
//
//
//

class CAddressList : public IAddressList
{
 private:
   ULONG m_cRef;	
   CArray<IAddress *,IAddress* > m_list;
   int curr_pos;
 public:
   //IUnknown
   STDMETHODIMP QueryInterface(REFIID iid, LPVOID *ppv);
   STDMETHODIMP_(ULONG)AddRef(void);
   STDMETHODIMP_(ULONG)Release(void); 
   //IAddressList

   
  STDMETHODIMP MoveFirst();
  STDMETHODIMP MoveLast();
  STDMETHODIMP MoveNext();
  STDMETHODIMP MovePrevious();
  STDMETHODIMP Eof();
  STDMETHODIMP Bof();
  STDMETHODIMP GetData( IAddress **Ptr );
  STDMETHODIMP Add( IAddress *Ptr );
  STDMETHODIMP Write( LPSTR str );
  STDMETHODIMP Open( LPSTR str );

  CAddressList();
 
};


class CAddressListFactory : public IClassFactory
{
private:
	ULONG			m_cRef;
public:
	//IUnknown
	STDMETHODIMP QueryInterface(REFIID iid, LPVOID *ppv);
    STDMETHODIMP_(ULONG)AddRef(void);
    STDMETHODIMP_(ULONG)Release(void);
	//IClassFactory
	STDMETHODIMP CreateInstance(IUnknown* pUnknownOuter, 
		REFIID iid, LPVOID *ppv);
	STDMETHODIMP LockServer(BOOL bLock);
	//Constructor
	CAddressListFactory()
	{
		m_cRef = 0;
	}
};




#endif
