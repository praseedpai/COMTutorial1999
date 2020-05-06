#include "symbol.h"




SymbolTableManager::SymbolTableManager() 
{
  
};

SymbolTableManager::~SymbolTableManager() 
{
       

}



BOOL SymbolTableManager::AddSymbol( SYMBOL_INFO *new_sym )
{
        val.insert( pair<const string , SYMBOL_INFO>(
		new_sym->SymbolName , *new_sym ) );

        key_array.push_back(new_sym->SymbolName );
        return TRUE;
	
} 


SYMBOL_INFO * SymbolTableManager::LookupSymbol(char *Name)
{

        map<string,SYMBOL_INFO >::iterator i;

		return   ( ( i = val.find( Name ) ) != val.end() ) ?
			reinterpret_cast<SYMBOL_INFO *> (&((*i).second)) :
		    reinterpret_cast<SYMBOL_INFO *> (NULL);
			

		
} 


long  SymbolTableManager::GetSymbolCount()
  {
    return val.size();
  }

