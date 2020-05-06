#ifndef ADDRESS_LIST_DOT_H
#define ADDRESS_LIST_DOT_H
#include "address.h"

typedef LONG BOOLEAN_T; 

class IAddressList 
{
 public:
  virtual BOOLEAN_T MoveFirst()=0;
  virtual BOOLEAN_T MoveLast()=0;
  virtual BOOLEAN_T MoveNext()=0;
  virtual BOOLEAN_T MovePrevious()=0;
  virtual BOOLEAN_T Eof()=0;
  virtual BOOLEAN_T Bof()=0;
  virtual BOOLEAN_T GetData(IAddress ** )=0;
  virtual BOOLEAN_T Add(IAddress *)=0;
  virtual BOOLEAN_T Write(LPSTR )=0; 
  virtual BOOLEAN_T Open(LPSTR )=0;









};


#endif
