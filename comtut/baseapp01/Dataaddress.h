#ifndef DATA_ADDRESS_DOT_H
#define DATA_ADDRESS_DOT_H
#include "address.h"
#include "AddressList.h"
#include "afxtempl.h"
///////////////////////////////////////////////////
//
//
//
//
//
//
class TAddressList: public IAddressList 
{
private:
	CPtrArray   m_list;
    int curr_pos;
	
public:
  TAddressList();
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
