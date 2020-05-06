#ifndef ADDRESS_LIST_IMPL_DOT_H
#define ADDRESS_LIST_IMPL_DOT_H
#include "AddressList.h"
#include "afxtempl.h"
///////////////////////////////////////////////////
//
//
//
//
//
//
class CAddressList: public IAddressList 
{
private:
	CArray<IAddress *,IAddress* > m_list;
    int curr_pos;
	
public:
  CAddressList();
  virtual BOOLEAN_T MoveFirst();
  virtual BOOLEAN_T MoveLast();
  virtual BOOLEAN_T MoveNext();
  virtual BOOLEAN_T MovePrevious();
  virtual BOOLEAN_T Eof();
  virtual BOOLEAN_T Bof();
  virtual BOOLEAN_T GetData( IAddress **Ptr );
  virtual BOOLEAN_T Add( IAddress *Ptr );
  virtual BOOLEAN_T Write( LPSTR );
  virtual BOOLEAN_T Open( LPSTR );

};


#endif
