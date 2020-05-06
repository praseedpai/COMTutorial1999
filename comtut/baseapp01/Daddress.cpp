#include "stdafx.h"
#include "DAtaaddress.h"
////////////////////////////////
//
TAddressList::TAddressList()
{
       curr_pos = -1;
       m_list.SetSize(0);
}
/////////////////////////////////////////
//
BOOLEAN_T TAddressList::MoveFirst() 
{
  if ( m_list.GetUpperBound() == -1 )
	  {
		  curr_pos = -1;
		  return 0;
	  }
	  
     curr_pos = 0;
	 return 1;
}

BOOLEAN_T TAddressList::MoveLast()
  {
    if ((curr_pos = m_list.GetUpperBound()) == -1 )
			    return 0;
	return 1;

  }

BOOLEAN_T TAddressList::MoveNext()
 {
      if ( curr_pos == m_list.GetUpperBound()+1 )
		    return 0;
	  curr_pos++;
	  return 1;
}

BOOLEAN_T TAddressList::MovePrevious()
{
  if ( curr_pos == -1 )
	  return 0;
  curr_pos--;
  return 1;
}

BOOLEAN_T TAddressList::Eof()
{
 if ( curr_pos == m_list.GetUpperBound()+1 )
             return 1;
 if ( curr_pos == -1 )
		  return 1;
 return 0;
     


}

BOOLEAN_T TAddressList::Bof()
  {
	  if ( curr_pos == -1 ) 
		  return 1;
	  	  return 0;
  }

BOOLEAN_T TAddressList::GetData( IAddress **Ptr )
{
	  *Ptr = (IAddress *)m_list.GetAt(curr_pos);
	  return 1;

}

BOOLEAN_T TAddressList::Add( IAddress *Ptr )
{
      m_list.Add(Ptr);
      return 1;
}

 BOOLEAN_T TAddressList::Write( LPSTR pstr)
{
  
  // do nothing 
return 1;
}

 BOOLEAN_T TAddressList::Open( LPSTR pstr)
{

 // do nothing
return 1;
}



// EOF 

