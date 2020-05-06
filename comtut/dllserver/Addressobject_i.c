/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 16 17:40:44 1999
 */
/* Compiler settings for D:\comtut\dllserver\Addressobject.idl:
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

const IID IID_IAddress = {0x3BF36EF1,0xF3B3,0x11d2,{0xA4,0xE3,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


const IID IID_IAddressList = {0x5664CF91,0xF3B3,0x11d2,{0xA4,0xE3,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


const IID LIBID_Addressobject = {0x5664CF92,0xF3B3,0x11d2,{0xA4,0xE3,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


const CLSID CLSID_Address = {0xE49E4821,0xF3B3,0x11d2,{0xA4,0xE3,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


const CLSID CLSID_AddressList = {0x14EF50C1,0xF3BA,0x11d2,{0xA4,0xE3,0x00,0x40,0x05,0x6D,0xF8,0x7F}};


#ifdef __cplusplus
}
#endif

