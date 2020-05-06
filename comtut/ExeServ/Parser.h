#ifndef PARSER_DOT_H
#define PARSER_DOT_H    // Avoid Duplicate inclusion

#include <windows.h>
#include <stdio.h>
#include "Lexer.h"
#include "Stack.h"
#include "Symbol.h"


#pragma warning(disable:4786)
#include <string>
#include <vector>
#include <list>

using namespace std ;

#define MAX_FN 4 

#define MAX_CHILDREN 3 

#define RESULT_DOUBLE  1000
#define RESULT_STRING  2000
#define RESULT_ILLEGAL 3000


#define SET_PARSE_ERROR(ncode)   error_code = ncode 
#define THROW_PARSE_ERROR(ncode) { error_code = ncode; \
                                   throw error_code; }

//////////////////////////////////////////////
//
//
//
//

/////////////////////////////////////
//
//
//
typedef struct
{
	char *fnname;
	void (*fnptr)();
}BUILTINS;

 
  

///////////////////////////////////////////////////////
//
//
//
//
//
//
class CExpParser  
{

private:
    long error_code;  
	long result_type;
    double result_value;
	LPSTR  result_str;
	char   error_str[256];
    /*-------------- Pointer To  Lexical Analyzer --------*/
    CExpLexer *Lex_ptr; 
    /*------------------- Current Token -----------------*/
	TOK_TYPE     tt; 
    //------------- Stack Data Structure
	//------------- used for Constant Folding
	CompilerStack<STACK_ELEM_TYPE> EvaluationStack;
	//------------- Symbol Table Manager 
	SymbolTableManager SymbolTable;
	BUILTINS bldin[MAX_FN]; 
private:
	TOK_TYPE  SkipToken();
    void evaluate_const_expr();
    void Eval_SExpr();
    void Eval_Term(); 
	void Eval_Factor();
	void Eval_L_Expr();
	void ParseSine();
	void ParseCosine();
	void ParseTangent();
	void ParseASine();
    void ParseACosine();
	void ParseATangent();
	void ParseSQRT();
	void ParseRound();
	void ParseFrac();
	void HandlePlus(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y);
    void HandleMinus(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y);
    void HandleDiv(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y);
    void HandleMul(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y);

public:
    CExpParser( LPSTR ParseText );
    ~CExpParser();
    bool Parse();
	bool ShowError( int x ); 
	long ResultType() 
	{ 
		return result_type; 
	}

	double ResultDouble() 
	{ 
		return result_value; 
	}

	void ErrorStr( LPSTR str_error )
	{
         strcpy(str_error,error_str);

	}

    LPSTR ResultStr() 
	{
         return result_str;

	}

};
#endif

