#ifndef OBJ_IMPL_DOT_H
#define OBJ_IMPL_DOT_H
#include <windows.h>
#include "EvalExpr.h"
#include "Parser.h"

class CExpression  : public IExpression 
{
 private:
   ULONG m_cRef;
   CExpParser *pobj; 
   char ExprStr[255];

 public:
   
   	//IUnknown
	STDMETHODIMP QueryInterface(REFIID iid, LPVOID *ppv);
	STDMETHODIMP_(ULONG)AddRef(void);
	STDMETHODIMP_(ULONG)Release(void);
	//IExpression 
	STDMETHODIMP SetExpr(  LPSTR expr_str );
	STDMETHODIMP Evaluate( LONG *result_type ); 	
    STDMETHODIMP EvaluateImmediate( LPSTR expr_str ,
		                            LONG *result_type );

	STDMETHODIMP   GetStringValue(  LPSTR result_str );
    STDMETHODIMP   GetDoubleValue(  double *result_str );
    STDMETHODIMP   GetError( LPSTR error_str );
	STDMETHODIMP   DummyFunc(  RESULTTYPE *lpt );

    // ctor
    CExpression(); 

};


class CExpressionFactory : public IClassFactory
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

	CExpressionFactory()
	{
		m_cRef = 0;
	}
};

#endif


