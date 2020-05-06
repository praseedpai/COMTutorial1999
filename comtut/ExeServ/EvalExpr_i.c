/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Sep 15 22:57:05 1999
 */
/* Compiler settings for EvalExpr.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IExpression = {0x5A774B31,0x2F6B,0x11d3,{0xA5,0x3E,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


const IID LIBID_EvalExpr = {0x5A774B33,0x2F6B,0x11d3,{0xA5,0x3E,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


const CLSID CLSID_Expression = {0x5A774B32,0x2F6B,0x11d3,{0xA5,0x3E,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


#ifdef __cplusplus
}
#endif

