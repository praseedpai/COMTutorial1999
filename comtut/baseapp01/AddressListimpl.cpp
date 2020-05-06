#include "stdafx.h"
#include "AddressListimpl.h"

/////////////////////////////////
//
//
//
//

CAddressList::CAddressList()
{
       curr_pos = -1;
       m_list.SetSize(0);
	   
}
/////////////////////////////////////////
//
//
//
//
 BOOLEAN_T CAddressList::MoveFirst() 
{
     
	  if ( m_list.GetUpperBound() == -1 )
	  {
		  curr_pos = -1;
		  return 0;
	  }
	  
     curr_pos = 0;
	 return 1;
  }

 BOOLEAN_T CAddressList::MoveLast()
  {
    if ((curr_pos = m_list.GetUpperBound()) == -1 )
	{
		    return 0;
	}
    
	return 1;

  }

 BOOLEAN_T CAddressList::MoveNext()
  {
      if ( curr_pos == m_list.GetUpperBound()+1 )
		    return 0;

	  curr_pos++;
	  return 1;
    	 
  }

 BOOLEAN_T CAddressList::MovePrevious()
{
  if ( curr_pos == -1 )
	  return 0;

  curr_pos--;
	  
	  return 1;

     
  }

BOOLEAN_T CAddressList::Eof()
  {
	  if ( curr_pos == m_list.GetUpperBound()+1 )
	  {
             return 1;
	
	  }

	  if ( curr_pos == -1 )
		  return 1;

	  return 0;
     


  }

BOOLEAN_T CAddressList::Bof()
  {
	  if ( curr_pos == -1 ) 
	  {
		  return 1;
	  }
	  return 0;


  }

BOOLEAN_T CAddressList::GetData( IAddress **Ptr )
{
	  *Ptr = m_list.GetAt(curr_pos);
	  return 1;
}

BOOLEAN_T CAddressList::Add( IAddress *Ptr )
{
      m_list.Add(Ptr);
      return 1;
}
BOOLEAN_T CAddressList::Write( LPSTR pstr)
{
// do nothing 
return 1;
}
BOOLEAN_T CAddressList::Open( LPSTR pstr)
{
 // do nothing
 return 1;
}
// EOF 

