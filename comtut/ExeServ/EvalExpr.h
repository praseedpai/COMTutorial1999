/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Sep 15 22:57:05 1999
 */
/* Compiler settings for EvalExpr.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __EvalExpr_h__
#define __EvalExpr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IExpression_FWD_DEFINED__
#define __IExpression_FWD_DEFINED__
typedef interface IExpression IExpression;
#endif 	/* __IExpression_FWD_DEFINED__ */


#ifndef __Expression_FWD_DEFINED__
#define __Expression_FWD_DEFINED__

#ifdef __cplusplus
typedef class Expression Expression;
#else
typedef struct Expression Expression;
#endif /* __cplusplus */

#endif 	/* __Expression_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_EvalExpr_0000 */
/* [local] */ 

typedef /* [public][public][helpstring] */ 
enum __MIDL___MIDL_itf_EvalExpr_0000_0001
    {	DOUBLE_VAL	= 1,
	STR_VAL	= 2,
	ILLEGAL_VAL	= 4
    }	RESULTTYPE;



extern RPC_IF_HANDLE __MIDL_itf_EvalExpr_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_EvalExpr_0000_v0_0_s_ifspec;

#ifndef __IExpression_INTERFACE_DEFINED__
#define __IExpression_INTERFACE_DEFINED__

/* interface IExpression */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IExpression;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5A774B31-2F6B-11d3-A53E-0040056DF87F")
    IExpression : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetExpr( 
            /* [in] */ LPSTR expr_str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Evaluate( 
            /* [out][in] */ LONG __RPC_FAR *result_type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EvaluateImmediate( 
            /* [in] */ LPSTR expr_str,
            /* [out][in] */ LONG __RPC_FAR *result_type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringValue( 
            /* [out][in] */ LPSTR result_str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDoubleValue( 
            /* [out][in] */ double __RPC_FAR *result_str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetError( 
            /* [out][in] */ LPSTR error_str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DummyFunc( 
            /* [out][in] */ RESULTTYPE __RPC_FAR *lpt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExpressionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IExpression __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IExpression __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IExpression __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExpr )( 
            IExpression __RPC_FAR * This,
            /* [in] */ LPSTR expr_str);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Evaluate )( 
            IExpression __RPC_FAR * This,
            /* [out][in] */ LONG __RPC_FAR *result_type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EvaluateImmediate )( 
            IExpression __RPC_FAR * This,
            /* [in] */ LPSTR expr_str,
            /* [out][in] */ LONG __RPC_FAR *result_type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStringValue )( 
            IExpression __RPC_FAR * This,
            /* [out][in] */ LPSTR result_str);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDoubleValue )( 
            IExpression __RPC_FAR * This,
            /* [out][in] */ double __RPC_FAR *result_str);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetError )( 
            IExpression __RPC_FAR * This,
            /* [out][in] */ LPSTR error_str);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DummyFunc )( 
            IExpression __RPC_FAR * This,
            /* [out][in] */ RESULTTYPE __RPC_FAR *lpt);
        
        END_INTERFACE
    } IExpressionVtbl;

    interface IExpression
    {
        CONST_VTBL struct IExpressionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExpression_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExpression_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExpression_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExpression_SetExpr(This,expr_str)	\
    (This)->lpVtbl -> SetExpr(This,expr_str)

#define IExpression_Evaluate(This,result_type)	\
    (This)->lpVtbl -> Evaluate(This,result_type)

#define IExpression_EvaluateImmediate(This,expr_str,result_type)	\
    (This)->lpVtbl -> EvaluateImmediate(This,expr_str,result_type)

#define IExpression_GetStringValue(This,result_str)	\
    (This)->lpVtbl -> GetStringValue(This,result_str)

#define IExpression_GetDoubleValue(This,result_str)	\
    (This)->lpVtbl -> GetDoubleValue(This,result_str)

#define IExpression_GetError(This,error_str)	\
    (This)->lpVtbl -> GetError(This,error_str)

#define IExpression_DummyFunc(This,lpt)	\
    (This)->lpVtbl -> DummyFunc(This,lpt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IExpression_SetExpr_Proxy( 
    IExpression __RPC_FAR * This,
    /* [in] */ LPSTR expr_str);


void __RPC_STUB IExpression_SetExpr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IExpression_Evaluate_Proxy( 
    IExpression __RPC_FAR * This,
    /* [out][in] */ LONG __RPC_FAR *result_type);


void __RPC_STUB IExpression_Evaluate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IExpression_EvaluateImmediate_Proxy( 
    IExpression __RPC_FAR * This,
    /* [in] */ LPSTR expr_str,
    /* [out][in] */ LONG __RPC_FAR *result_type);


void __RPC_STUB IExpression_EvaluateImmediate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IExpression_GetStringValue_Proxy( 
    IExpression __RPC_FAR * This,
    /* [out][in] */ LPSTR result_str);


void __RPC_STUB IExpression_GetStringValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IExpression_GetDoubleValue_Proxy( 
    IExpression __RPC_FAR * This,
    /* [out][in] */ double __RPC_FAR *result_str);


void __RPC_STUB IExpression_GetDoubleValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IExpression_GetError_Proxy( 
    IExpression __RPC_FAR * This,
    /* [out][in] */ LPSTR error_str);


void __RPC_STUB IExpression_GetError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IExpression_DummyFunc_Proxy( 
    IExpression __RPC_FAR * This,
    /* [out][in] */ RESULTTYPE __RPC_FAR *lpt);


void __RPC_STUB IExpression_DummyFunc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExpression_INTERFACE_DEFINED__ */



#ifndef __EvalExpr_LIBRARY_DEFINED__
#define __EvalExpr_LIBRARY_DEFINED__

/* library EvalExpr */
/* [version][helpstring][uuid] */ 


EXTERN_C const IID LIBID_EvalExpr;

EXTERN_C const CLSID CLSID_Expression;

#ifdef __cplusplus

class DECLSPEC_UUID("5A774B32-2F6B-11d3-A53E-0040056DF87F")
Expression;
#endif
#endif /* __EvalExpr_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
