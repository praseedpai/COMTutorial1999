//////////////////////////////////
// implementation File for
// CAddress and CAddressList 
//
//

#include "stdafx.h"
#include "objimpl.h"

////////////////////////////////////
//
//
extern BOOL ServerCanUnloadNow();
extern void UnloadServer();

//////////////////////////
//
//
extern  ULONG g_cObjects;
extern  ULONG g_cLocks;
/////////////////////////////////////
//
// ctor for Address Class
//
//
CAddress::CAddress()
{

#if 1
   memset(Name,0,sizeof(Name));
   memset(Address1,0,sizeof(Address1));
   memset(Address2,0,sizeof(Address2));
   memset(City,0,sizeof(City));
   memset(State,0,sizeof(State));
   memset(Country,0,sizeof(Country));
   memset(Pin,0,sizeof(Pin));
   m_cRef=0;
#else
   memset(this,0,sizeof(CAddress)); 
#endif
}

///////////////////////////////////////////////////
//
//  Get/Set Method for Name
//
//

STDMETHODIMP  CAddress::GetName( LPSTR  str)
{
  strcpy((char *)str,Name);
  return NOERROR;
}

STDMETHODIMP CAddress::SetName( LPSTR  str)
{
  strcpy((char *)Name,str);
  return NOERROR;
}

///////////////////////////////////////////////////
//
//  Get/Set Method for Address string 1
//
//
STDMETHODIMP CAddress::GetAddress1(LPSTR  str )
{
	strcpy(str,Address1);
	return NOERROR;
}


 STDMETHODIMP CAddress::SetAddress1(LPSTR  str )
{
  	strcpy(Address1,str);
	return NOERROR;

}

///////////////////////////////////////////////////
//
//  Get/Set Method for Address string 2
//
//

STDMETHODIMP CAddress::GetAddress2(LPSTR  str )
{
	strcpy(str,Address2);
	return NOERROR;

}


STDMETHODIMP CAddress::SetAddress2(LPSTR  str )
{
  	strcpy(Address2,str);
	return NOERROR;
}
// ///////////////////////////////////////////////////
//
//  Get/Set Method for City
//
//
//
//
STDMETHODIMP CAddress::GetCity(LPSTR   str)
{
       strcpy(str,City);
	   return NOERROR;

}

STDMETHODIMP CAddress::SetCity(LPSTR   str)
{
	  strcpy(City,str);
	  return NOERROR;
}
///////////////////////////////////////////////////
//
// Get/Set Method for State
//
//
//
STDMETHODIMP CAddress::GetState( LPSTR   str)
{
   strcpy(str,State);
   return NOERROR;
}

STDMETHODIMP CAddress::SetState( LPSTR   str)
{
   strcpy(State,str);
   return NOERROR;
}
///////////////////////////////////
//
//
//
STDMETHODIMP CAddress::GetCountry( LPSTR  str)
{
   strcpy(str,Country);
   return NOERROR;
}

STDMETHODIMP CAddress::SetCountry( LPSTR  str)
{
   strcpy(Country,str);	
   return NOERROR;
}
///////////////////////////////////
//
//
//
//
STDMETHODIMP CAddress::GetPinCode( LPSTR  str)
{
     strcpy(str,Pin);
	 return NOERROR;
}

STDMETHODIMP CAddress::SetPinCode( LPSTR  str)
{
    strcpy(Pin,str);
	return NOERROR;
}

/*------ Iunknown methods --------------------*/

STDMETHODIMP CAddress::QueryInterface(
	 REFIID iid , LPVOID *ppv )
 {
    *ppv = 0;

	if ( IID_IUnknown == iid )
	{
       *ppv = (LPVOID)(IUnknown *)this;
	}
	else if ( IID_IAddress == iid )
	{
		*ppv = (LPVOID)(IAddress *)this;
	}
	else {
		return E_NOINTERFACE;
	}

  ((IUnknown *)*ppv)->AddRef();
  
  return NOERROR;

}


STDMETHODIMP_(ULONG) CAddress::AddRef()
{
   return ++m_cRef;

}


STDMETHODIMP_(ULONG) CAddress::Release()
{
   m_cRef--;

   if ( m_cRef == 0 )
   {
	   delete this;
	   g_cObjects--;

	   if ( ::ServerCanUnloadNow())
		   ::UnloadServer();
      
   }


return m_cRef;

}

/////////////////////////////////////////////
//
//
//
//
//
//
//
//
//

CAddressList::CAddressList()
{
       curr_pos = -1;
       m_list.SetSize(0);
	   m_cRef;
	   
}
/////////////////////////////////////////
//
//
//
//
 STDMETHODIMP CAddressList::MoveFirst() 
{
     
	  if ( m_list.GetUpperBound() == -1 )
	  {
		  curr_pos = -1;
		  return S_FALSE;
	  }
	  
     curr_pos = 0;
	 return S_OK;
  }

 STDMETHODIMP CAddressList::MoveLast()
  {
    if ((curr_pos = m_list.GetUpperBound()) == -1 )
	{
		    return S_FALSE;
	}
    
	return S_OK;

  }

 STDMETHODIMP CAddressList::MoveNext()
  {
      if ( curr_pos == m_list.GetUpperBound()+1 )
		    return S_FALSE;

	  curr_pos++;
	  return S_OK;
    	 
  }

 STDMETHODIMP CAddressList::MovePrevious()
{
  if ( curr_pos == -1 )
	  return S_FALSE;

  curr_pos--;
	  
	  return S_OK;

     
  }

STDMETHODIMP CAddressList::Eof()
  {
	  if ( curr_pos == m_list.GetUpperBound()+1 )
	  {
             return S_OK;
	
	  }

	  if ( curr_pos == -1 )
		  return S_OK;

	  return S_FALSE;
     


  }

STDMETHODIMP CAddressList::Bof()
  {
	  if ( curr_pos == -1 ) 
	  {
		  return S_OK;
	  }
	  return S_FALSE;


  }

STDMETHODIMP CAddressList::GetData( IAddress **Ptr )
{

	  *Ptr = m_list.GetAt(curr_pos);
	  return NOERROR;

}

STDMETHODIMP CAddressList::Add( IAddress *Ptr )
{
      m_list.Add(Ptr);
      return NOERROR;
}

 STDMETHODIMP CAddressList::Write( LPSTR  pstr)
{
  
  // do nothing 
return NOERROR;
}

 STDMETHODIMP CAddressList::Open( LPSTR  pstr)
{


 // do nothing

 return NOERROR;


}

////////////////////////////////////////////////
//
//
//
//
//
//
 STDMETHODIMP CAddressList::QueryInterface(
	 REFIID iid , LPVOID *ppv )
 {
    *ppv = 0;

	if ( IID_IUnknown == iid )
	{
       *ppv = (LPVOID)(IUnknown *)this;
	}
	else if ( IID_IAddressList == iid )
	{
		*ppv = (LPVOID)(IAddressList *)this;
	}
	else {
		return E_NOINTERFACE;
	}

  ((IUnknown *)*ppv)->AddRef();
  
  return NOERROR;

}


STDMETHODIMP_(ULONG) CAddressList::AddRef()
{
   return ++m_cRef;

}


STDMETHODIMP_(ULONG) CAddressList::Release()
{
   m_cRef--;

   if ( m_cRef == 0 )
   {
	   delete this;
	   g_cObjects--;

	   if ( ::ServerCanUnloadNow())
		   ::UnloadServer();
      
   }


return m_cRef;

}
///////////////////////////////////////
//
//
//
//
//
//
//
//
//
//
//CreateInstance
//
STDMETHODIMP CAddressFactory::CreateInstance(
IUnknown* pUnknownOuter, 
REFIID iid, LPVOID *ppv)
{
	HRESULT hr;
	CAddress *pAddr = NULL;

	*ppv = NULL;

	//This object doesn't support aggregation

	if (NULL != pUnknownOuter)
		return CLASS_E_NOAGGREGATION;

	//Create the CUserInfo object

	pAddr = new CAddress();

	if (NULL == pAddr)
		return E_OUTOFMEMORY;
	//Retrieve the requested interface
	hr = pAddr->QueryInterface(iid, ppv);
	if (FAILED(hr))
	{
		delete pAddr;
		pAddr = NULL;
		return hr;
	}
	//Increment the global object counter
	g_cObjects++;	

	return NOERROR;
}//CreateInstance

//
//LockServer
//
STDMETHODIMP CAddressFactory::LockServer(BOOL bLock)
{
	if (bLock)
		g_cLocks++;
	else
	{
		g_cLocks--;
		//See if it's alright to unload the server
		if (::ServerCanUnloadNow())
			::UnloadServer();
	}
	return NOERROR;
}//LockServer

//
//QueryInterface
//
STDMETHODIMP CAddressFactory::QueryInterface(REFIID iid, LPVOID *ppv)
{
    *ppv = NULL;
    if (IID_IUnknown == iid)
        *ppv = (LPVOID)(IUnknown *)this;     
	else if (IID_IClassFactory == iid) 
        *ppv = (LPVOID)(IClassFactory *)this;     
    else 
		return E_NOINTERFACE;	//Interface not supported
	//Perform reference count through the returned interface
    ((IUnknown *)*ppv)->AddRef();
    return NOERROR;    
}//QueryInterface

//
//AddRef
//
STDMETHODIMP_(ULONG) CAddressFactory::AddRef(void)
{
	return ++m_cRef;
}//AddRef

//
//Release
//
STDMETHODIMP_(ULONG) CAddressFactory::Release(void)
{
	m_cRef--;
	if (0 == m_cRef)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}//Release





STDMETHODIMP CAddressListFactory::CreateInstance(
IUnknown* pUnknownOuter, 
REFIID iid, LPVOID *ppv)
{
	HRESULT hr;
	CAddressList *pAddr = NULL;

	*ppv = NULL;

	//This object doesn't support aggregation

	if (NULL != pUnknownOuter)
		return CLASS_E_NOAGGREGATION;

	//Create the CUserInfo object

	pAddr = new CAddressList();

	if (NULL == pAddr)
		return E_OUTOFMEMORY;
	//Retrieve the requested interface
	hr = pAddr->QueryInterface(iid, ppv);
	if (FAILED(hr))
	{
		delete pAddr;
		pAddr = NULL;
		return hr;
	}
	//Increment the global object counter
	g_cObjects++;	

	return NOERROR;
}//CreateInstance

//
//LockServer
//
STDMETHODIMP CAddressListFactory::LockServer(BOOL bLock)
{
	if (bLock)
		g_cLocks++;
	else
	{
		g_cLocks--;
		//See if it's alright to unload the server
		if (::ServerCanUnloadNow())
			::UnloadServer();
	}
	return NOERROR;
}//LockServer

//
//QueryInterface
//
STDMETHODIMP CAddressListFactory::QueryInterface(
REFIID iid, LPVOID *ppv)
{
    *ppv = NULL;
    if (IID_IUnknown == iid)
        *ppv = (LPVOID)(IUnknown *)this;     
	else if (IID_IClassFactory == iid) 
        *ppv = (LPVOID)(IClassFactory *)this;     
    else 
		return E_NOINTERFACE;	//Interface not supported
	//Perform reference count through the returned interface
    ((IUnknown *)*ppv)->AddRef();
    return NOERROR;    
}//QueryInterface

//
//AddRef
//
STDMETHODIMP_(ULONG) CAddressListFactory::AddRef(void)
{
	return ++m_cRef;
}//AddRef

//
//Release
//
STDMETHODIMP_(ULONG) CAddressListFactory::Release(void)
{
	m_cRef--;
	if (0 == m_cRef)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}//Release





