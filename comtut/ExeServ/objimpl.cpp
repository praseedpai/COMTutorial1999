///////////////////////////////////////
//
//
// Objimpl.cpp 
//
//
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
CExpression::CExpression()
{
  memset( ExprStr,0,sizeof(ExprStr ) );
  pobj = 0; 

}
////////////////////////////////////////////////
//
//
//
//
//
STDMETHODIMP CExpression::Evaluate(LONG  *result_type )
{

  if ( ExprStr[0] == 0 )
  {
     MessageBox( GetFocus(),"No Expr Given","Warning",1); 
  }
  if ( pobj == 0 ) 
     pobj = new CExpParser(ExprStr);
  pobj->Parse();
  switch(pobj->ResultType())
  {
  case RESULT_DOUBLE:
	     *result_type = DOUBLE_VAL ;
	     break;
  case RESULT_STRING:
	  *result_type = STR_VAL ;
	     break;
  case RESULT_ILLEGAL:
	  *result_type = ILLEGAL_VAL  ;
      break;
  


  
 }

  return NOERROR; 
}
////////////////////////////////////////////////////
//
//
//
//
//
STDMETHODIMP CExpression::EvaluateImmediate(LPSTR expr_str ,
											LONG  * result_type )
{

  SetExpr(expr_str);
  if ( pobj ) {
	  delete pobj;
	  pobj=0;
  }
  pobj = new CExpParser(ExprStr);
  pobj->Parse();
  switch(pobj->ResultType())
  {
  case RESULT_DOUBLE:
	     *result_type = DOUBLE_VAL ;
	     break;
  case RESULT_STRING:
	  *result_type = STR_VAL ;
	     break;
  case RESULT_ILLEGAL:
	  *result_type = ILLEGAL_VAL  ;
      break;
    
 }


  return NOERROR; 
}
///////////////////////////////////////////////
//
//
//
//
STDMETHODIMP CExpression::SetExpr( LPSTR expr_str )
{
   strcpy(ExprStr, expr_str);	
     if ( pobj ) {
	  delete pobj;
	  pobj=0;
  }
   return NOERROR;
}
/////////////////////////////////////////////////
//
//
STDMETHODIMP   CExpression::GetStringValue(  LPSTR result_str )
{
  if ( pobj )
	  strcpy(result_str ,pobj->ResultStr());
  
  return NOERROR;
}

/////////////////////////////////////////////////////
//
//
//
STDMETHODIMP   CExpression::GetDoubleValue(  double *result_str )
{
   if ( pobj )
	  *result_str = pobj->ResultDouble();
  
   return NOERROR;
}
//////////////////////////////////////////////////////////
//
//
//
STDMETHODIMP   CExpression::GetError( LPSTR error_str )
{
  if ( pobj )
	  pobj->ErrorStr(error_str);
  
  return NOERROR;

}
////////////////////////////////////////////////
//
//
//
STDMETHODIMP   CExpression::DummyFunc(  RESULTTYPE *lpt )
{

   return NOERROR;
}

///////////////////////////////////
//
//
//
//

STDMETHODIMP CExpression::QueryInterface(
	 REFIID iid , LPVOID *ppv )
 {
    *ppv = 0;

	if ( IID_IUnknown == iid )
	{
       *ppv = (LPVOID)(IUnknown *)this;
	}
	else if ( IID_IExpression == iid )
	{
		*ppv = (LPVOID)(IExpression *)this;
	}
	else {
		return E_NOINTERFACE;
	}

  ((IUnknown *)*ppv)->AddRef();
  
  return NOERROR;

}


STDMETHODIMP_(ULONG) CExpression::AddRef()
{
   return ++m_cRef;

}


STDMETHODIMP_(ULONG) CExpression::Release()
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
STDMETHODIMP CExpressionFactory::CreateInstance(
IUnknown* pUnknownOuter, 
REFIID iid, LPVOID *ppv)
{
	HRESULT hr;
	CExpression *pAddr = NULL;

	*ppv = NULL;

	//This object doesn't support aggregation

	if (NULL != pUnknownOuter)
		return CLASS_E_NOAGGREGATION;

	//Create the CUserInfo object

	pAddr = new CExpression();

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
STDMETHODIMP CExpressionFactory::LockServer(BOOL bLock)
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
STDMETHODIMP CExpressionFactory::QueryInterface(REFIID iid, LPVOID *ppv)
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
STDMETHODIMP_(ULONG) CExpressionFactory::AddRef(void)
{
	return ++m_cRef;
}//AddRef

//
//Release
//
STDMETHODIMP_(ULONG) CExpressionFactory::Release(void)
{
	m_cRef--;
	if (0 == m_cRef)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}//Release





