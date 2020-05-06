///////////////////////////////////////////////////////////////
//
// Lexical Analyser Module for Edwin NT Simulation Compiler
// The Lexical Analyzer object will be emebedded in Parser  
// Object. 


#ifndef EDWIN_LEXER_DOT_H
#define EDWIN_LEXER_DOT_H  // Avoid multiple inclusion 
#include <windows.h>
#include <math.h>         //  for Pow Function  
#pragma warning(disable:4786)
#include <string>
#include <vector>
#include <list>



#define  MAX_STRING_LENGTH  255; 
#define  MAX_VARIABLE_NAME  31; 
using namespace std;

#define SET_LEX_ERROR( n )   error_code = (ULONG) (( 1 << 31 ) | (n) ) 
// Enumeration for Tokens 

enum  TOK_TYPE  {
   TOKEN_ILLEGAL = -1,     // ILLEAGEL TOKEN 
   TOKEN_PLUS  ,           // '+'
   TOKEN_MINUS ,           // '-'  
   TOKEN_EOS ,             // End of String
   TOKEN_PLUSPLUS,         // '++' 
   TOKEN_MINUSMINUS,       // '--'
   TOKEN_LONG,             // long value
   TOKEN_TIME,             // double value
   TOKEN_DIV,              // '/'
   TOKEN_MUL,              // '*'
   TOKEN_AND,              // 'AND'
   TOKEN_OR,               // 'OR'  
   TOKEN_EQUAL,            // '==' 
   TOKEN_LESSTHANEQUAL,    // '<='
   TOKEN_SHIFTLEFT,        // '<<' 
   TOKEN_NOTEQUAL,         // '!='  
   TOKEN_LESS,             //  '<'  
   TOKEN_GREATERTHANEQUAL, //  '>='
   TOKEN_SHIFTRIGHT,       //  '>>'
   TOKEN_GREATER,          //  '>'
   TOKEN_MOD,              //  '%'
   TOKEN_OPAREN,           //  '('
   TOKEN_CPAREN,           //  ')'
   TOKEN_DIM  ,            //  'DIM'
   TOKEN_AS   ,            //  'AS'
   TOKEN_LONG_STRING ,     //  'LONG'  
   TOKEN_TIME_STRING ,     //  'TIME'  
   TOKEN_CONST,            //  'CONST' 
   TOKEN_STRING_LITERAL,   //  '"<string>"'   
   TOKEN_UNQUOTED_STRING,  //   <varname or assignstatement>
   TOKEN_BOOL_TRUE,        //  'TRUE'
   TOKEN_BOOL_FALSE,       //  'FALSE'
   TOKEN_NOT,              //  'NOT'
   TOKEN_NULL_VALUE ,      //   not a keyword 
   TOKEN_NEWLINE           //   Next Line  
 
};



///////////////////////////////////////////////////////
//
// Class to Perform Lexical Analysis 
//
//
  

   
class CExpLexer  {

private:

   // Variable To Store input String  
   LPSTR  input_text;
   LPSTR  Currptr; 
   LPSTR  CurrTokenPtr;
   TOK_TYPE Curr_Token;
   LONG    long_value;
   int     lex_error_no;
   double  double_value; 
   string  unquoted_string;
   string  quoted_string;





  
   //============================== Error Code
   unsigned long  error_code;
   //==============================
   unsigned long  line_number;

	  /*------------ Extract String literal -----*/

	  TOK_TYPE ExtractString();

	  //----  Lookup the KeyWord Table for the match
	  //----  if found return TOK_TYPE else
	  //----- return TOKEN_NULL_VALUE 

	 

	 static TOK_TYPE isKeyWord( string& Temp)
	 {
        const char *mtemp = Temp.c_str(); 

        static struct TABLE_KEYWORD
		{
	      char *keywordname;
	      TOK_TYPE m_tok;
		}KEYWORD_TABLE[] = {
			{ "DIM", TOKEN_DIM } ,
			{ "AS" , TOKEN_AS  } ,
			{ "LONG"  , TOKEN_LONG_STRING },
			{ "FLOAT"  , TOKEN_TIME_STRING },
			{ "CONST" , TOKEN_CONST  },
			{ "TRUE"    , TOKEN_BOOL_TRUE  },
			{ "FALSE"   , TOKEN_BOOL_FALSE}  ,
			{ "AND"     , TOKEN_AND } ,
			{ "OR"      , TOKEN_OR  } ,
			{ "NOT"     , TOKEN_NOT } 
			
		};


 	  for( int i=0; i< sizeof(KEYWORD_TABLE) /
		   sizeof(KEYWORD_TABLE[0]); ++i )
	   {

		    if ( stricmp( KEYWORD_TABLE[i].keywordname ,mtemp )
				== 0 )
			      return KEYWORD_TABLE[i].m_tok;
       }


     return TOKEN_NULL_VALUE; 
	 }


	




	  //------ Skip Multiline Comment

	  BOOL SkipMultilineComment();
    
      //------ returns whether current token is
	  //-------  <= , << , <> , < 
      TOK_TYPE isToken01();
	   
	  //------ returns whether current token is
	  //-------  >= , >> , >   
      
	  TOK_TYPE isToken02();
	   
      // Extract Constants
	  
	  TOK_TYPE  ExtractLongorTime();

      // Skip White Spaces  aka Tab chr(32)
	  void SkipWhite();
	  
      // Skip To End of Line     
	  void SkipToEoln();


	  TOK_TYPE  ExtractHexDigits();
	 
	  TOK_TYPE  NumericHex(char p_ch);
	  
	  TOK_TYPE  RetSymbolInfo();

	  TOK_TYPE  BinaryDigits(); 

      TOK_TYPE  HexDigits();


public:
	 CExpLexer( LPCTSTR srcText );
	 
	 ~CExpLexer();

	 LONG    GetLongValue( );

	  double  GetDoubleValue();

      string& GetUnquotedString();

	  string& QuotedString();


	 TOK_TYPE NextToken();


	 TOK_TYPE PeekToken();

     long  GetErrorCode();

	 long  GetLineNumber();
     
	 long  ErrorOffset();

	   
};


#endif
