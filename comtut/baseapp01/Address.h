#ifndef ADDRESS_DOT_H
#define ADDRESS_DOT_H
#include <windows.h>
class IAddress 
{
 public:
   virtual void GetName(LPSTR )=0;
   virtual void SetName(LPSTR )=0;
   virtual void GetAddress1(LPSTR  )=0;
   virtual void SetAddress1(LPSTR  )=0;
   virtual void GetAddress2(LPSTR )=0;
   virtual void SetAddress2(LPSTR )=0;
   virtual void GetCity(LPSTR  )=0 ;
   virtual void SetCity(LPSTR  )=0 ; 
   virtual void GetState( LPSTR  )=0;
   virtual void SetState( LPSTR  )=0;
   virtual void GetCountry( LPSTR )=0;
   virtual void SetCountry( LPSTR )=0; 
   virtual void GetPinCode( LPSTR )=0;
   virtual void SetPinCode( LPSTR )=0;
   


};


#endif
