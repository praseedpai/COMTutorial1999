#ifndef ADDRESS_IMPL_DOT_H
#define ADDRESS_IMPL_DOT_H
#include "address.h"
#include "addresslist.h"
#include "afxtempl.h"

class CAddress : public IAddress 
{
 private:
   char Name[50];
   char Address1[50];
   char Address2[50];
   char City[50];
   char State[50];
   char Country[50];
   char Pin[25];

 public:

   CAddress(); 
	 
    virtual void GetName(LPSTR str);
    virtual void SetName(LPSTR str);
    virtual void GetAddress1(LPSTR str );
    virtual void SetAddress1(LPSTR str );
    virtual void GetAddress2(LPSTR str);
    virtual void SetAddress2(LPSTR str);
    virtual void GetCity(LPSTR  str);
    virtual void SetCity(LPSTR  str); 
    virtual void GetState( LPSTR  str);
    virtual void SetState( LPSTR  str);
    virtual void GetCountry( LPSTR str);
    virtual void SetCountry( LPSTR str); 
    virtual void GetPinCode( LPSTR str);
    virtual void SetPinCode( LPSTR str);



};



#endif
