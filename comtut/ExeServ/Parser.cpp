#include "err_msg.h"
#include "parser.h"

/////////////////////////////////////////////////
// ctor for Parser 
// Creates an instance of Lexical Analyzer Class
//
//
//
CExpParser::CExpParser( LPSTR ParseText ) 
{
try { 
	 Lex_ptr = new  CExpLexer( ParseText );
}
catch(...)
{
    THROW_PARSE_ERROR(18001); 
}



  
}
//////////////////////////////////////////////////////
//
//
//  Dtor
//
//

CExpParser::~CExpParser() 
{
 delete Lex_ptr;
}  

////////////////////////////////////////////////
//
//  Get The Next Token From The Stream 
//
//

inline TOK_TYPE  CExpParser::SkipToken() 
{
	//*------ if Parse  Complete Return TOKEN_EOS 

	if ( tt == TOKEN_EOS )
		  return tt;


   
     //------------ IF next Token is illegal Throw Error 

	 if ( ( tt = Lex_ptr->NextToken() ) == TOKEN_ILLEGAL )
	 {
		 
		 THROW_PARSE_ERROR( (Lex_ptr->GetErrorCode()) );
	 }

 return tt;
} 







	 

/////////////////////////////////////////////////
//
//  Evaluate Constant Expression
//
//  eg :-   Const X =  ( 100 >> 2 ) + 1; 
//          Const Y =  ( X  - 100 )
//    
void CExpParser::evaluate_const_expr()
{

	  EvaluationStack.Clear();   // Reset Stack Pointer
	  Eval_L_Expr();      // Call RD PARSER 

}

//////////////////////////////////////////////////////
//
//
//
//
//
//


void CExpParser::Eval_Factor()
{

   TOK_TYPE old_tt = tt;

   if ( old_tt == TOKEN_PLUS ||  old_tt == TOKEN_MINUS  ||
	    old_tt == TOKEN_NOT  )  
   {
      old_tt = tt; 
	  SkipToken();

      Eval_Factor();   // Recurse !

	  switch( old_tt )
	  {
	  case TOKEN_NOT:
		  {
		STACK_ELEM_TYPE x;
		EvaluationStack.Pop(&x);

		if ( x.type_info == long_val  ) 
				   x.lval = ~x.lval;
		else {

		     THROW_PARSE_ERROR(18002);   
			 

		}
		EvaluationStack.Push(&x);
		  }

		  break;
	   case TOKEN_PLUS:
		   return;
       case TOKEN_MINUS: {
		   STACK_ELEM_TYPE x;
		   EvaluationStack.Pop(&x);

		   if ( x.type_info == long_val  ) 
				   x.lval = -x.lval;
		   else
				   x.dval = -x.dval;
				   
		    EvaluationStack.Push(&x);

						 }
            break;
	  }
			 
      return;
  }         
  else if (old_tt == TOKEN_OPAREN) 
  {  
	   old_tt =tt; 
       SkipToken();
       Eval_L_Expr();
		
	   if ( tt ==  TOKEN_CPAREN) 
	   {
          SkipToken(); 
		  return;	   
	   }
	   else 
	   {
		     THROW_PARSE_ERROR(18003);   
			 
	   }
  } 
 else if (tt == TOKEN_LONG ||  tt == TOKEN_TIME )
 {
	STACK_ELEM_TYPE x;
		    
	if ( old_tt == TOKEN_LONG ) 
	{
       x.type_info = long_val; 
	   x.lval = Lex_ptr->GetLongValue();
			  
	}
    else if ( old_tt == TOKEN_TIME )
	{
	   x.type_info = double_val;
       x.dval      = Lex_ptr->GetDoubleValue();
    }
	
	   EvaluationStack.Push( &x);   
       SkipToken();  
		
       return; 
 }

else if ( tt == TOKEN_UNQUOTED_STRING )  
{
	 char CurrStr[100];
	 strcpy(CurrStr , ( char* ) Lex_ptr->GetUnquotedString().c_str() );
//    SYMBOL_INFO  *lc_symb_info;
//    STACK_ELEM_TYPE x;
//    lc_symb_info = SymbolTable.LookupSymbol(
//		 	 ( char* ) (Lex_ptr->GetUnquotedString().c_str()) );
// Symbol Not in The Table
//    if ( lc_symb_info == NULL ) {
//	 
//			 THROW_PARSE_ERROR(18004);   
//			 
//       } 
// Symbol is not a constant
//   if ( lc_symb_info->smb_kind == variable )
//		 {
//             THROW_PARSE_ERROR(18005);   
//			 
//         }  
//		 x.type_info = 
//		 (lc_symb_info->CONST_INFO.s_type == long_type ) ?
//         long_val : 
//		 (lc_symb_info->CONST_INFO.s_type == double_type ) ? 
//         double_val : illegal_val;
// Circular Reference 
// Ie   Const x  = x*2;
//         if ( x.type_info == illegal_val ) {
//
//		           THROW_PARSE_ERROR(18006);   
//			       
//		 }
//
//		 if ( x.type_info == long_val )
    		 //x.lval = lc_symb_info->CONST_INFO.lval;
		 //else
		//	 x.dval = lc_symb_info->CONST_INFO.dval;
		 
		//EvaluationStack.Push(&x);
        //SkipToken();

        if ( stricmp(CurrStr,"SIN") == 0 )
		{
                SkipToken(); 
				if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
				SkipToken();	  
			    ParseSine();
		}
        else if ( stricmp(CurrStr,"COS") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseCosine();
			  
		}
        else if ( stricmp(CurrStr,"TAN") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseTangent();
			  
		}
		else if ( stricmp(CurrStr,"ASIN") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseASine();
			  
		}
		else if ( stricmp(CurrStr,"ACOS") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseACosine();
			  
		}
		else if ( stricmp(CurrStr,"ATAN") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseATangent();
			  
		}
        else if ( stricmp(CurrStr,"SQRT") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseSQRT();
			  
		}
        else if ( stricmp(CurrStr,"INT") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseRound();
			  
		}
		else if ( stricmp(CurrStr,"FRAC") == 0 )
		{
			  SkipToken();
			  if ( tt != TOKEN_OPAREN )
					 THROW_PARSE_ERROR(18013);   
              SkipToken();
			  ParseFrac();
			  
		}
		
		


		return;
        
	 }
	
          THROW_PARSE_ERROR(18012);   
	
           return;
		   
		   
     	 	

}



void CExpParser::Eval_SExpr()
{

        Eval_Term();
		TOK_TYPE  old_tt = tt;   
		while  (tt == TOKEN_MINUS || 
			    tt == TOKEN_PLUS) 
		{
           old_tt = tt; 
		   SkipToken();	
           Eval_Term();

		   STACK_ELEM_TYPE x , y , result;

		   EvaluationStack.Pop(&x);
		   EvaluationStack.Pop(&y);

           if ( x.type_info  != y.type_info )
		   {
			    THROW_PARSE_ERROR(18008);   
		  

          }
   		   result.type_info =  x.type_info ;

		   

		   switch ( old_tt  ) 
		   {
		    case TOKEN_MINUS:
				HandleMinus(&y,&x); 
				continue;
		  	//if ( x.type_info == long_type ) {
			//	result.lval      = ( y.lval - x.lval );
			//}
			//else {
             //   result.dval      = ( y.dval -  x.dval );
           // }
		//	break;
			
			case TOKEN_PLUS:
               HandlePlus(&y,&x); 
				continue;
          //   if ( x.type_info == long_type ) {
			//	result.lval      = ( y.lval + x.lval );
			//}
			//else {
        
              //  result.dval      = ( y.dval +  x.dval );
            //}
            //break; 

		   }

		   //EvaluationStack.Push(&result);

		} // while 

}




void CExpParser::Eval_Term() {

      Eval_Factor();
      TOK_TYPE old_tt;
 
      while (tt ==  TOKEN_DIV || 
		     tt ==  TOKEN_MUL || 
			 tt ==  TOKEN_MOD  || 
             tt ==  TOKEN_SHIFTLEFT || 
			 tt ==  TOKEN_SHIFTRIGHT )
	  {
            old_tt = tt; 
		    SkipToken();
			Eval_Factor();

		    STACK_ELEM_TYPE x , y , result;
		    EvaluationStack.Pop(&x);
  		    EvaluationStack.Pop(&y);

			if ( old_tt != TOKEN_DIV && old_tt != TOKEN_MUL ) 
			{
              if ( x.type_info  != y.type_info )
			  {
			         THROW_PARSE_ERROR(18008);   
		      }
			  if ( x.type_info != long_val ) {
			   THROW_PARSE_ERROR(18010);   
		       
		 	           
			  }
			}



		   

   		   result.type_info =  x.type_info;
		   

		   switch ( old_tt  ) 
		   {
		    case TOKEN_MUL:
			
                HandleMul(&y,&x);;
                continue;
	         
			
			case TOKEN_DIV:
				HandleDiv(&y,&x); 
				continue;

			case  TOKEN_MOD :
                result.lval      = ( y.lval % x.lval ); 
				break;
            case  TOKEN_SHIFTLEFT:
				result.lval      = ( y.lval << x.lval );
				break;
			case  TOKEN_SHIFTRIGHT :
				result.lval      = ( y.lval >> x.lval );
                break;  


		   }

		   EvaluationStack.Push(&result);

			  
	  }
	  
 }


void  CExpParser::Eval_L_Expr() 
{
    Eval_SExpr();
	TOK_TYPE old_tt;

    while (tt == TOKEN_AND  ||  tt == TOKEN_OR )
	{
		old_tt = tt;
		SkipToken();
		Eval_SExpr();
        STACK_ELEM_TYPE x , y , result;
	    EvaluationStack.Pop(&x);
	    EvaluationStack.Pop(&y);

        if ( x.type_info  != y.type_info )
		{
			    THROW_PARSE_ERROR(18007);   
		        

        }


		if ( x.type_info != long_val ) {
			   THROW_PARSE_ERROR(18010);   
		       
		 	           
		}
		  

   		result.type_info =   long_val;
        result.lval = ( old_tt  == TOKEN_AND ) ? 
			          ( y.lval & x.lval ) : ( y.lval | x.lval );
		
   	    EvaluationStack.Push(&result);

			  
	}  // while 


}



/////////////////////////////////////////////////////
//
//  Entry Point To The Parser 
//  Builds  Parse Tree as the Parse Process is going on
//  A Typical single pass Compiler
//
          
		  
bool CExpParser::Parse() 
{
   char bfr[20];

   if ( SkipToken() == TOKEN_EOS ) 
   {
	 THROW_PARSE_ERROR(18011);   
   }


   try { 
     evaluate_const_expr(); 
     STACK_ELEM_TYPE x;
     EvaluationStack.Pop(&x);
     if ( x.type_info == long_val  ) 
		 result_value = x.lval;
     else
		 result_value = x.dval;
     result_type = RESULT_DOUBLE;


   }
   catch(long p)
   {

     ShowError(p);     
	 result_type =  RESULT_ILLEGAL;
     return false; 

   }


	 

  
     
      return true;  

}

/////////////////////////////////////////
//
//
//
//
//
bool CExpParser::ShowError( int x ) 
{

	short y = (x & 0xFFFF );
    char *ErrorPtr = NULL;
	for( int i=0; i < sizeof(Error_Info)/sizeof(Error_Info[0]);
	 ++i )
	 {

		 if ( Error_Info[i].number == y ) 
		 {
			 ErrorPtr = Error_Info[i].error_str;
			 strcpy(error_str,ErrorPtr);
			 return true;
		 }

     }


        
  
	 
	 strcpy(error_str,"unknown error");
     return true;
 }

	
void CExpParser::ParseSine()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
		 x.type_info = double_val;
	     x.dval =sin(x.lval);
	 }
     else {
		 
	     x.dval =sin(x.dval);
	 }
	 

     EvaluationStack.Push(&x);
}

void CExpParser::ParseCosine()
{

	Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
		 x.type_info =double_val;
	     x.dval =cos(x.lval);
	 }
     else {
		 
	     x.dval =cos(x.dval);
	 }
	 

     EvaluationStack.Push(&x);

}


void CExpParser::ParseTangent()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
		 x.type_info = double_val;
	     x.dval =tan(x.lval);
	 }
     else {
		 
	     x.dval =tan(x.dval);
	 }
	 

     EvaluationStack.Push(&x);


}
void CExpParser::ParseASine()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
		 x.type_info = double_val;
	     x.dval =asin(x.lval);
	 }
     else {
		 
	     x.dval =asin(x.dval);
	 }
	 

     EvaluationStack.Push(&x);
}	
void CExpParser::ParseACosine()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
		 x.type_info = double_val;
	     x.dval =acos(x.lval);
	 }
     else {
		 
	     x.dval =acos(x.dval);
	 }
	 

     EvaluationStack.Push(&x);
}

void CExpParser::ParseATangent()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
		 x.type_info = double_val;
	     x.dval =atan(x.lval);
	 }
     else {
		 
	     x.dval =atan(x.dval);
	 }
	 

     EvaluationStack.Push(&x);
}

void CExpParser::HandlePlus(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y)
{
  
	STACK_ELEM_TYPE result;
    
    if ( x->type_info == y->type_info )
	{
       if ( x->type_info == long_val ) {
		        result.type_info = long_val;
				result.lval      = ( y->lval+x->lval );
			}
			else {
				result.type_info = long_val;
                result.dval      = ( y->dval + x->dval );
            }

    

	}else 
	{
        result.type_info = double_val;
		if ( x->type_info == long_val ) 
		{
			result.dval      = ( y->dval+x->lval );
		}
		else 
		{
             result.dval      = ( y->lval+x->dval );
        }
        

	}

	EvaluationStack.Push(&result);

 
}
void CExpParser::HandleMinus(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y)
{

		STACK_ELEM_TYPE result;
    
    if ( x->type_info == y->type_info )
	{
       if ( x->type_info == long_val ) {
		        result.type_info = long_val;
				result.lval      = ( y->lval-x->lval );
			}
			else {
				result.type_info = long_val;
                result.dval      = ( y->dval- x->dval );
            }

    

	}else 
	{
        result.type_info = double_val;
		if ( x->type_info == long_val ) 
		{
			result.dval      = ( y->dval-x->lval );
		}
		else 
		{
             result.dval      = ( y->lval-x->dval );
        }
        

	}

	EvaluationStack.Push(&result);


}
void CExpParser::HandleDiv(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y)
{
		STACK_ELEM_TYPE result;
    
    if ( x->type_info == y->type_info )
	{
       if ( x->type_info == long_val ) {
		        result.type_info = long_val;
				result.dval      = ( (double)x->lval/(double)y->lval );
			}
			else {
				result.type_info = long_val;
                result.dval      = ( x->dval / (double)y->dval );
            }

    

	}else 
	{
        result.type_info = double_val;
		if ( x->type_info == long_val ) 
		{
			result.dval      = ( (double)x->lval/y->dval );
		}
		else 
		{
             result.dval      = ( x->dval/ (double)y->lval );
        }
        

	}

	EvaluationStack.Push(&result);


}
void CExpParser::HandleMul(STACK_ELEM_TYPE *x,STACK_ELEM_TYPE *y)
{
		STACK_ELEM_TYPE result;
    
    if ( x->type_info == y->type_info )
	{
       if ( x->type_info == long_val ) {
		        result.type_info = long_val;
				result.lval      = ( y->lval*x->lval );
			}
			else {
				result.type_info = long_val;
                result.dval      = ( y->dval * x->dval );
            }

    

	}else 
	{
        result.type_info = double_val;
		if ( x->type_info == long_val ) 
		{
			result.dval      = ( y->dval*x->lval );
		}
		else 
		{
             result.dval      = ( y->lval * x->dval );
        }
        

	}

	EvaluationStack.Push(&result);


}

void CExpParser::ParseSQRT()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
		 x.type_info = double_val;
	     x.dval =sqrt(x.lval);
	 }
     else {
		 
	     x.dval =sqrt(x.dval);
	 }
	 

     EvaluationStack.Push(&x);

}

void CExpParser::ParseRound()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);

	 if ( x.type_info == long_val  ) {
              x.type_info = long_val;		 
	     x.lval =(long)x.lval;
	 }
     else {
		      x.type_info = long_val;
	     x.lval =(long)(x.dval);
	 }
	 

     EvaluationStack.Push(&x);

}

void CExpParser::ParseFrac()
{
     Eval_L_Expr();      
     if ( tt != TOKEN_CPAREN )
		 THROW_PARSE_ERROR(18003);   
	 SkipToken();

     STACK_ELEM_TYPE x;
	 EvaluationStack.Pop(&x);
     
	 if ( x.type_info == long_val  ) {
	     x.type_info = double_val;	 
	     x.dval =0;
	 }
     else {
		 x.type_info = double_val;
	     x.dval =x.dval - (int)x.dval;
	 }
	 

     EvaluationStack.Push(&x);

}

// #EOF  Parser.cpp



