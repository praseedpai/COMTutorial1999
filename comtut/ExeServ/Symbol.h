//////////////////////////////////////
//
//  Symbol Table Lookup Routine
//
//
//

#ifndef SYMBOL_DOT_H
#define SYMBOL_DOT_H
#include <windows.h>
#pragma warning(disable:4786)

#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std ;
enum SYMB_KIND  {  constant , variable };
enum SYMB_TYPE  {  long_type , double_type , bool_type ,
input_type , output_type , oc_type , oe_type , rs_type,lparam_type,dparam_type,
unspecified_type };

enum SYMB_FORM { s_atomic , s_array };



 typedef struct 
{

  string       SymbolName;
  SYMB_KIND    smb_kind; 
  SYMB_TYPE    smb_type;
  SYMB_FORM    smb_form;
  int          id_index;

  union {

	  struct 
	  {
		  long max_bound;

	  }ARRAY_INFO;


  
  struct {

	  union {
	  double    dval;
	  long      lval;
	  };

      SYMB_TYPE s_type;

  }CONST_INFO;

  
  };
  
string descr; 

}SYMBOL_INFO;



 class SymbolTableManager 
 {
 
  map<string,SYMBOL_INFO >   val;

  vector<string>  key_array;
  
  
  int LabelIndexValue ;

 public:

	 SymbolTableManager();

	 ~SymbolTableManager();

	 BOOL AddSymbol( SYMBOL_INFO *new_sym );

     SYMBOL_INFO * LookupSymbol(char *Name);
     long  GetSymbolCount();
     
};






#endif


