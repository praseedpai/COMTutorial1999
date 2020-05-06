#include "stdafx.h"
#include "addressimpl.h"

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
#else
   memset(this,0,sizeof(CAddress)); 
#endif
}

///////////////////////////////////////////////////
//
//  Get/Set Method for Name
//
//

void CAddress::GetName(LPSTR str)
{
  strcpy(str,Name);
}

void CAddress::SetName(LPSTR str)
{
  strcpy(Name,str);
}

///////////////////////////////////////////////////
//
//  Get/Set Method for Address string 1
//
//
void CAddress::GetAddress1(LPSTR str )
{
	strcpy(str,Address1);
}


 void CAddress::SetAddress1(LPSTR str )
{
  	strcpy(Address1,str);
}

///////////////////////////////////////////////////
//
//  Get/Set Method for Address string 2
//
//

void CAddress::GetAddress2(LPSTR str )
{
	strcpy(str,Address2);

}


 void CAddress::SetAddress2(LPSTR str )
{
  	strcpy(Address2,str);
}
// ///////////////////////////////////////////////////
//
//  Get/Set Method for City
//
//
//
//
 void CAddress::GetCity(LPSTR  str)
{
       strcpy(str,City);

}

 void CAddress::SetCity(LPSTR  str)
{
	  strcpy(City,str);
}
///////////////////////////////////////////////////
//
// Get/Set Method for State
//
//
//
 void CAddress::GetState( LPSTR  str)
{
   strcpy(str,State);
}

 void CAddress::SetState( LPSTR  str)
{
   strcpy(State,str);
}
///////////////////////////////////
//
//
//
 void CAddress::GetCountry( LPSTR str)
{
   strcpy(str,Country);
}

 void CAddress::SetCountry( LPSTR str)
{
   strcpy(Country,str);	 
}
///////////////////////////////////
//
//
//
//
 void CAddress::GetPinCode( LPSTR str)
{
     strcpy(str,Pin);	 
}

 void CAddress::SetPinCode( LPSTR str)
{
    strcpy(Pin,str);	 
}
// EOF 
