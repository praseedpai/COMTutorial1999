/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Apr 21 19:02:41 1999
 */
/* Compiler settings for addressobject.idl:
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

#ifndef __addressobject_h__
#define __addressobject_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAddress_FWD_DEFINED__
#define __IAddress_FWD_DEFINED__
typedef interface IAddress IAddress;
#endif 	/* __IAddress_FWD_DEFINED__ */


#ifndef __IAddressList_FWD_DEFINED__
#define __IAddressList_FWD_DEFINED__
typedef interface IAddressList IAddressList;
#endif 	/* __IAddressList_FWD_DEFINED__ */


#ifndef __Address_FWD_DEFINED__
#define __Address_FWD_DEFINED__

#ifdef __cplusplus
typedef class Address Address;
#else
typedef struct Address Address;
#endif /* __cplusplus */

#endif 	/* __Address_FWD_DEFINED__ */


#ifndef __AddressList_FWD_DEFINED__
#define __AddressList_FWD_DEFINED__

#ifdef __cplusplus
typedef class AddressList AddressList;
#else
typedef struct AddressList AddressList;
#endif /* __cplusplus */

#endif 	/* __AddressList_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IAddress_INTERFACE_DEFINED__
#define __IAddress_INTERFACE_DEFINED__

/* interface IAddress */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAddress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3BF36EF1-F3B3-11d2-A4E3-0040056DF87F")
    IAddress : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [out][in] */ LPSTR __MIDL_0000) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ LPSTR __MIDL_0001) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAddress1( 
            /* [out][in] */ LPSTR __MIDL_0002) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAddress1( 
            /* [in] */ LPSTR __MIDL_0003) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAddress2( 
            /* [out][in] */ LPSTR __MIDL_0004) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAddress2( 
            /* [in] */ LPSTR __MIDL_0005) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCity( 
            /* [out][in] */ LPSTR __MIDL_0006) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCity( 
            /* [in] */ LPSTR __MIDL_0007) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetState( 
            /* [out][in] */ LPSTR __MIDL_0008) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ LPSTR __MIDL_0009) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCountry( 
            /* [out][in] */ LPSTR __MIDL_0010) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCountry( 
            /* [in] */ LPSTR __MIDL_0011) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPinCode( 
            /* [out][in] */ LPSTR __MIDL_0012) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPinCode( 
            /* [in] */ LPSTR __MIDL_0013) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAddress __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAddress __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAddress __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IAddress __RPC_FAR * This,
            /* [out][in] */ LPSTR __MIDL_0000);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IAddress __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0001);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAddress1 )( 
            IAddress __RPC_FAR * This,
            /* [out][in] */ LPSTR __MIDL_0002);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAddress1 )( 
            IAddress __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0003);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAddress2 )( 
            IAddress __RPC_FAR * This,
            /* [out][in] */ LPSTR __MIDL_0004);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAddress2 )( 
            IAddress __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0005);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCity )( 
            IAddress __RPC_FAR * This,
            /* [out][in] */ LPSTR __MIDL_0006);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCity )( 
            IAddress __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0007);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetState )( 
            IAddress __RPC_FAR * This,
            /* [out][in] */ LPSTR __MIDL_0008);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetState )( 
            IAddress __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0009);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCountry )( 
            IAddress __RPC_FAR * This,
            /* [out][in] */ LPSTR __MIDL_0010);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCountry )( 
            IAddress __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0011);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPinCode )( 
            IAddress __RPC_FAR * This,
            /* [out][in] */ LPSTR __MIDL_0012);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPinCode )( 
            IAddress __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0013);
        
        END_INTERFACE
    } IAddressVtbl;

    interface IAddress
    {
        CONST_VTBL struct IAddressVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAddress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAddress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAddress_GetName(This,__MIDL_0000)	\
    (This)->lpVtbl -> GetName(This,__MIDL_0000)

#define IAddress_SetName(This,__MIDL_0001)	\
    (This)->lpVtbl -> SetName(This,__MIDL_0001)

#define IAddress_GetAddress1(This,__MIDL_0002)	\
    (This)->lpVtbl -> GetAddress1(This,__MIDL_0002)

#define IAddress_SetAddress1(This,__MIDL_0003)	\
    (This)->lpVtbl -> SetAddress1(This,__MIDL_0003)

#define IAddress_GetAddress2(This,__MIDL_0004)	\
    (This)->lpVtbl -> GetAddress2(This,__MIDL_0004)

#define IAddress_SetAddress2(This,__MIDL_0005)	\
    (This)->lpVtbl -> SetAddress2(This,__MIDL_0005)

#define IAddress_GetCity(This,__MIDL_0006)	\
    (This)->lpVtbl -> GetCity(This,__MIDL_0006)

#define IAddress_SetCity(This,__MIDL_0007)	\
    (This)->lpVtbl -> SetCity(This,__MIDL_0007)

#define IAddress_GetState(This,__MIDL_0008)	\
    (This)->lpVtbl -> GetState(This,__MIDL_0008)

#define IAddress_SetState(This,__MIDL_0009)	\
    (This)->lpVtbl -> SetState(This,__MIDL_0009)

#define IAddress_GetCountry(This,__MIDL_0010)	\
    (This)->lpVtbl -> GetCountry(This,__MIDL_0010)

#define IAddress_SetCountry(This,__MIDL_0011)	\
    (This)->lpVtbl -> SetCountry(This,__MIDL_0011)

#define IAddress_GetPinCode(This,__MIDL_0012)	\
    (This)->lpVtbl -> GetPinCode(This,__MIDL_0012)

#define IAddress_SetPinCode(This,__MIDL_0013)	\
    (This)->lpVtbl -> SetPinCode(This,__MIDL_0013)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_GetName_Proxy( 
    IAddress __RPC_FAR * This,
    /* [out][in] */ LPSTR __MIDL_0000);


void __RPC_STUB IAddress_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_SetName_Proxy( 
    IAddress __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0001);


void __RPC_STUB IAddress_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_GetAddress1_Proxy( 
    IAddress __RPC_FAR * This,
    /* [out][in] */ LPSTR __MIDL_0002);


void __RPC_STUB IAddress_GetAddress1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_SetAddress1_Proxy( 
    IAddress __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0003);


void __RPC_STUB IAddress_SetAddress1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_GetAddress2_Proxy( 
    IAddress __RPC_FAR * This,
    /* [out][in] */ LPSTR __MIDL_0004);


void __RPC_STUB IAddress_GetAddress2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_SetAddress2_Proxy( 
    IAddress __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0005);


void __RPC_STUB IAddress_SetAddress2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_GetCity_Proxy( 
    IAddress __RPC_FAR * This,
    /* [out][in] */ LPSTR __MIDL_0006);


void __RPC_STUB IAddress_GetCity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_SetCity_Proxy( 
    IAddress __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0007);


void __RPC_STUB IAddress_SetCity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_GetState_Proxy( 
    IAddress __RPC_FAR * This,
    /* [out][in] */ LPSTR __MIDL_0008);


void __RPC_STUB IAddress_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_SetState_Proxy( 
    IAddress __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0009);


void __RPC_STUB IAddress_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_GetCountry_Proxy( 
    IAddress __RPC_FAR * This,
    /* [out][in] */ LPSTR __MIDL_0010);


void __RPC_STUB IAddress_GetCountry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_SetCountry_Proxy( 
    IAddress __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0011);


void __RPC_STUB IAddress_SetCountry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_GetPinCode_Proxy( 
    IAddress __RPC_FAR * This,
    /* [out][in] */ LPSTR __MIDL_0012);


void __RPC_STUB IAddress_GetPinCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddress_SetPinCode_Proxy( 
    IAddress __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0013);


void __RPC_STUB IAddress_SetPinCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddress_INTERFACE_DEFINED__ */


#ifndef __IAddressList_INTERFACE_DEFINED__
#define __IAddressList_INTERFACE_DEFINED__

/* interface IAddressList */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAddressList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5664CF91-F3B3-11d2-A4E3-0040056DF87F")
    IAddressList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MoveFirst( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveLast( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveNext( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MovePrevious( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Eof( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Bof( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            /* [out] */ IAddress __RPC_FAR *__RPC_FAR *__MIDL_0014) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            IAddress __RPC_FAR *__MIDL_0015) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ LPSTR __MIDL_0016) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ LPSTR __MIDL_0017) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddressListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAddressList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAddressList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAddressList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveFirst )( 
            IAddressList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveLast )( 
            IAddressList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveNext )( 
            IAddressList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MovePrevious )( 
            IAddressList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eof )( 
            IAddressList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Bof )( 
            IAddressList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetData )( 
            IAddressList __RPC_FAR * This,
            /* [out] */ IAddress __RPC_FAR *__RPC_FAR *__MIDL_0014);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAddressList __RPC_FAR * This,
            IAddress __RPC_FAR *__MIDL_0015);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Write )( 
            IAddressList __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0016);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IAddressList __RPC_FAR * This,
            /* [in] */ LPSTR __MIDL_0017);
        
        END_INTERFACE
    } IAddressListVtbl;

    interface IAddressList
    {
        CONST_VTBL struct IAddressListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddressList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAddressList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAddressList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAddressList_MoveFirst(This)	\
    (This)->lpVtbl -> MoveFirst(This)

#define IAddressList_MoveLast(This)	\
    (This)->lpVtbl -> MoveLast(This)

#define IAddressList_MoveNext(This)	\
    (This)->lpVtbl -> MoveNext(This)

#define IAddressList_MovePrevious(This)	\
    (This)->lpVtbl -> MovePrevious(This)

#define IAddressList_Eof(This)	\
    (This)->lpVtbl -> Eof(This)

#define IAddressList_Bof(This)	\
    (This)->lpVtbl -> Bof(This)

#define IAddressList_GetData(This,__MIDL_0014)	\
    (This)->lpVtbl -> GetData(This,__MIDL_0014)

#define IAddressList_Add(This,__MIDL_0015)	\
    (This)->lpVtbl -> Add(This,__MIDL_0015)

#define IAddressList_Write(This,__MIDL_0016)	\
    (This)->lpVtbl -> Write(This,__MIDL_0016)

#define IAddressList_Open(This,__MIDL_0017)	\
    (This)->lpVtbl -> Open(This,__MIDL_0017)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAddressList_MoveFirst_Proxy( 
    IAddressList __RPC_FAR * This);


void __RPC_STUB IAddressList_MoveFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_MoveLast_Proxy( 
    IAddressList __RPC_FAR * This);


void __RPC_STUB IAddressList_MoveLast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_MoveNext_Proxy( 
    IAddressList __RPC_FAR * This);


void __RPC_STUB IAddressList_MoveNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_MovePrevious_Proxy( 
    IAddressList __RPC_FAR * This);


void __RPC_STUB IAddressList_MovePrevious_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_Eof_Proxy( 
    IAddressList __RPC_FAR * This);


void __RPC_STUB IAddressList_Eof_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_Bof_Proxy( 
    IAddressList __RPC_FAR * This);


void __RPC_STUB IAddressList_Bof_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_GetData_Proxy( 
    IAddressList __RPC_FAR * This,
    /* [out] */ IAddress __RPC_FAR *__RPC_FAR *__MIDL_0014);


void __RPC_STUB IAddressList_GetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_Add_Proxy( 
    IAddressList __RPC_FAR * This,
    IAddress __RPC_FAR *__MIDL_0015);


void __RPC_STUB IAddressList_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_Write_Proxy( 
    IAddressList __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0016);


void __RPC_STUB IAddressList_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressList_Open_Proxy( 
    IAddressList __RPC_FAR * This,
    /* [in] */ LPSTR __MIDL_0017);


void __RPC_STUB IAddressList_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddressList_INTERFACE_DEFINED__ */



#ifndef __Addressobject_LIBRARY_DEFINED__
#define __Addressobject_LIBRARY_DEFINED__

/* library Addressobject */
/* [version][helpstring][uuid] */ 


EXTERN_C const IID LIBID_Addressobject;

EXTERN_C const CLSID CLSID_Address;

#ifdef __cplusplus

class DECLSPEC_UUID("E49E4821-F3B3-11d2-A4E3-0040056DF87F")
Address;
#endif

EXTERN_C const CLSID CLSID_AddressList;

#ifdef __cplusplus

class DECLSPEC_UUID("14EF50C1-F3BA-11d2-A4E3-0040056DF87F")
AddressList;
#endif
#endif /* __Addressobject_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
