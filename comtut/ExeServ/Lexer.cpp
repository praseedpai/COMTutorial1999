




#define TABLE_DEFINED_IN_LEXCPP
#include "lexer.h"

//////////////////////////////////////////////////
// Method (#1)
// Extract Delimited String from the input stream
// delimiter  = "
//
//
//

TOK_TYPE  CExpLexer::ExtractString()
{

   char *m_ptr = Currptr;

   /*----------- Iterate till delimiter is seen ---*/
     quoted_string = "";
     
     while ( *Currptr && *Currptr != '"' )
	 {
		    if ( *Currptr == 13 || *Currptr == 10 )
			{
               SET_LEX_ERROR( 16010 ); 
		       return TOKEN_ILLEGAL;  
                 
			}

	        quoted_string += *Currptr++; 

	 }
               
	 


   /*--------- null terminated ? ------------*/ 
    
    if ( *Currptr == 0 ) 
	 {
		  SET_LEX_ERROR( 16000 ); 
		  return TOKEN_ILLEGAL;
     } 
		 

	
   
   Currptr++;
   
   return    TOKEN_STRING_LITERAL;
}



//////////////////////////////////////////////////
// Method (#2)
// Skip multiline  comment
// /*  <body> */
//
//
//

BOOL CExpLexer::SkipMultilineComment()
{

    while ( *Currptr )  
	{
      if (   *Currptr == '*' && 
             *(Currptr+1) == '/' ) 
			  break;
			  
	       if ( *Currptr == 13 ) {
                  Currptr+=2; 
			  	  line_number++;
				  continue;
			  }

           	  Currptr++;
	}

          
	 if ( !*Currptr ) 
	  {
         SET_LEX_ERROR(16001); 
		 return FALSE;
	  }


	  Currptr += 2;
	  return TRUE;  
}

//////////////////////////////////////////////////////////
//  Method (#3)  
//  < - has been found 
//  peek the next character and return the token
// 
//

TOK_TYPE CExpLexer::isToken01()
{

    char ch = *Currptr++;
		  
    switch( ch ) 
	 {
		  case '=':
            return TOKEN_LESSTHANEQUAL;
		  case '<':
			return TOKEN_SHIFTLEFT;
          case '>':
            return TOKEN_NOTEQUAL;
          default:
			Currptr--;
			return TOKEN_LESS;
     }
		  


}  
  
//////////////////////////////////////////////////////////
//  Method (#4)  
//  > - has been
//  peek the next character and return the token
// 
//
TOK_TYPE CExpLexer::isToken02()
{
    char ch = *Currptr++; 
     switch(ch) {
		 case '=':
		    return TOKEN_GREATERTHANEQUAL;
         case '>':
		    return TOKEN_SHIFTRIGHT;
         default:
			 Currptr--;
			 return TOKEN_GREATER;
		 } 

}

///////////////////////////////////////////////////
// method #5
// Extract numeric valu from the stream
// numericvalue can be long or double ( including
// exponential notation )
//



TOK_TYPE  CExpLexer::ExtractLongorTime()
 {
         char Buffer[50];
         char *m_ptr = Buffer; 
         int  nctr = 0;
	     int  is_dec = 0;
		 char m_ch;

          while ( isdigit( ( m_ch = *Currptr )) || 
			      toupper(m_ch) == 'E'   || 
				  m_ch == '.' ) 
		  {    
             
			if ( m_ch == '.' ) 
			{
                                       
               if ( is_dec == 1 )
                {
                  SET_LEX_ERROR(16002);
				  Curr_Token = TOKEN_ILLEGAL;    
                  return Curr_Token;
                }

                is_dec = 1; 
                *m_ptr++ = *Currptr++; 
                continue;                                         
            }
            else if ( toupper(m_ch) == 'E' ) 
			{

				*m_ptr =0;
				int     sign = 1;
				double  till_value = atof(Buffer);
				double  frac_value = 0.0;
				m_ptr = Buffer;
                Currptr++;


                if ( *Currptr == '-' ||  *Currptr == '+' )
				{
                      if ( *Currptr == '-' ) 
						      sign = -1;
					  Currptr++;
				}
				
				if ( !isdigit(*Currptr) )
				{
                  SET_LEX_ERROR(16002);
				  Curr_Token = TOKEN_ILLEGAL;    
                  return Curr_Token;

				}


				while ( *Currptr && isdigit(*Currptr) )
				{
		     			*m_ptr++ = *Currptr++;
				}

                 
				*m_ptr = 0;

                frac_value = atof(Buffer);
				
                 
                  if ( till_value == 0.0 ) 
				  {
					  if ( frac_value == 0.0 ) {
						   SET_LEX_ERROR(16003); 
                           Curr_Token = TOKEN_ILLEGAL;
                           return Curr_Token;
                       }

                     double_value = ( sign == 1 ) ?
                     pow(10.0, (double)frac_value ) : 
					 1.0/pow(10.0,(double)frac_value);
                     return Curr_Token = TOKEN_TIME; 
					  
                  }
				  else {
                    double_value = (sign==1) ? 
				    till_value*pow(10.0, frac_value ) :till_value/pow(10.0,frac_value);
                    return Curr_Token = TOKEN_TIME;

				 }


			}
			

			 *m_ptr++ = *Currptr++;

                           

            }

		  *m_ptr=0;

        if ( is_dec == 0 ) 
		{
          Curr_Token = TOKEN_LONG;
          long_value = atol( Buffer );
          
        }
        else
        {
          Curr_Token = TOKEN_TIME; 
          double_value  =  atof( Buffer );
                     
        }

      
      return Curr_Token; 
          

   }

//////////////////////////////////////////////////////////////
//  
// method #6
// Skips the spaces and tabs in input stream
//
//
    
 void CExpLexer::SkipWhite() 
{ 
     while ( *Currptr == ' ' || *Currptr == '\t' )
	             Currptr++;
	 
}

/////////////////////////////////////////
//  
// method #7 
//  Skip input stream until you reach CR
//
  
 void CExpLexer::SkipToEoln()
{
     while (*Currptr && *Currptr != 13 ) 
	 	      Currptr++;
	 
}

/////////////////////////////////////////////////////////
//
//  method #8 
//  Convert the input given as hexadecimal value into
//  unsigned long
// 

TOK_TYPE  CExpLexer::ExtractHexDigits() 
{
        
		 char  ch = *Currptr;
         long  lval = 0;
          
		 if ( isxdigit(ch) ) 
		 {
		 while ( isxdigit(ch) ) 
		 {
			 int sval =  (isdigit(ch)) ?
				 ch-'0' : 10 + (toupper(ch) - 'A') ;
			           
             lval = (lval<<4) + sval;
             Currptr++;
			 ch = *Currptr;
           
         }
         long_value = lval;
		 return Curr_Token = TOKEN_LONG;

		}
         SET_LEX_ERROR( 16004 );  
         return TOKEN_ILLEGAL; 

} 

/////////////////////////////////////////////////////
//  method #9 
//  
//  peek the input stream and extract hexadecimal value
//  or long  or double value
//

TOK_TYPE  CExpLexer::NumericHex(char p_ch)
 {
         char ch = toupper(*(Currptr + 1));
          
		 if ( p_ch == '0' && ch == 'X' ) 
		 {
             Currptr += 2;
			 return ExtractHexDigits();
         }
		 else if ( p_ch == '&'  )  
		 {
			 if ( ch == 'H' )  
			 {
               Currptr +=2; 
			   return ExtractHexDigits(); 
			 }
			 else {
               SET_LEX_ERROR( 16005);  
               return Curr_Token = TOKEN_ILLEGAL; 
			 }
         }
		 else if ( p_ch == '0' &&  ( ch == '1' || 
			 ch == '0' ) ) 
		 {
		    TOK_TYPE xt = BinaryDigits();

			if ( xt == TOKEN_ILLEGAL ) 
			{
				return ExtractLongorTime();
            } 
            return xt;

		 }
		 else if ( p_ch == '0' &&  isxdigit(ch) )
         {
			 return HexDigits();
         } 
         else
		 { 
             return ExtractLongorTime();

         } 

		 
		    SET_LEX_ERROR( 16009);        
            return TOKEN_ILLEGAL;

}

//////////////////////////////////////////////////////////////
// method #10
//    
//
//
TOK_TYPE  CExpLexer::RetSymbolInfo()
 {
       char *m_ptr = Currptr;
      
	  
       unquoted_string = "";
	   while ( isalnum(*Currptr) || *Currptr == '_' )
		           unquoted_string += *Currptr++;

	


		   TOK_TYPE ret_val;

		   if ( ( ret_val = isKeyWord(  unquoted_string ) ) 
			   != TOKEN_NULL_VALUE )
			    return ret_val;

           
				  
             return    TOKEN_UNQUOTED_STRING;
	  }

///////////////////////////////////////////
//
//  method #11
//  Extract Binary digit string and convert to long
//
//

TOK_TYPE  CExpLexer::BinaryDigits() 
{
 char *m_ptr = Currptr+1;
 char  ch = *m_ptr;
 long  lval = 0;

 /*************************************************
  Convert the Binary Value into Decimal Form 
  *************************************************/
         
 while ( ( ch  == '0' || ch == '1')) 
 {
	 lval = (lval << 1) | ( ( ch == '1') ? 1 : 0);
	 m_ptr++;
     ch = *m_ptr;
     
 }

// Look for Trailing 'B' 
// if not found return ILeagal token 

 if ( toupper(ch)  != 'B' )  {
	 SET_LEX_ERROR( 16006 );
	 return TOKEN_ILLEGAL;
 }


m_ptr++;
Currptr = m_ptr;
long_value = lval;

return Curr_Token = TOKEN_LONG;

}
//////////////////////////////////////////////////
//
// method #12 
// 
// Extract Hex digits string and convert to long
//
//


TOK_TYPE  CExpLexer::HexDigits()
{
  
 char *m_ptr = Currptr+1;
 char  ch = *m_ptr;
 long  lval = 0;
         
  if ( isxdigit(ch) ) 
  {
    while ( isxdigit(ch) ) 
	{
      int sval =  (isdigit(ch)) ?
	           	 ch-'0' : 10 + (toupper(ch) - 'A') ;
         lval = lval<<4 | sval;
         m_ptr++;
	     ch = *m_ptr;
           
    }

	if ( toupper(ch)  != 'H' ) {
        SET_LEX_ERROR( 16007); 
		return TOKEN_ILLEGAL;
	}

	m_ptr++;
	Currptr = m_ptr;
    long_value = lval;
	return Curr_Token = TOKEN_LONG;

}
   return TOKEN_ILLEGAL;

   
}




///////////////////////////////////////////////
//
// ctor 
//   Allocates buffer to store copy of input string
//   and copies it
//

CExpLexer::CExpLexer( LPCTSTR srcText ) 
{

	 input_text =  new  TCHAR[ strlen( srcText ) +1 ];
     strcpy( input_text , srcText );
     Currptr = input_text;
	 CurrTokenPtr = NULL;
	 lex_error_no = -1;
	 line_number = 1;

       
} 

/////////////////////////////////////////////////////////
//
//  dtor
//    frees the memory allocated to store the copy of 
//    input text

CExpLexer::~CExpLexer() 
{
		 delete input_text;
         

}   

/////////////////////////////////////////////////////////
//
//
//
//

 LONG   CExpLexer::GetLongValue() 
{ 
	 return long_value; 
}

///////////////////////////////////////////////////////////
//
//
//
//
//


 double  CExpLexer::GetDoubleValue() 
{ 
	 return double_value ; 
}

////////////////////////////////////////////////////
//
//
//
//


 string&  CExpLexer::GetUnquotedString() 
{
        return unquoted_string;

}

///////////////////////////////////////////////////
//
//
//
//

 string&  CExpLexer::QuotedString() 
{
   return quoted_string;

}

////////////////////////////////////////////////////
//
//  Scans the input string from current index and 
//  returns the Type of Token
//
//
//



TOK_TYPE CExpLexer::NextToken() 
{
 
  CurrTokenPtr = Currptr;
   
	
 /**********************  Skip White Spaces **********/
    	SkipWhite();             

  skip_label:

         switch( *Currptr ) 
		 {
          case  13: 
             // Case Carriage Return 
             // Skip two characters 
             Currptr+=2;
			 line_number++;
			 return ( Curr_Token = TOKEN_NEWLINE );
			 break;
          case 10:
			 Currptr+=1;
			 line_number++;
			 return ( Curr_Token = TOKEN_NEWLINE );
			 break; 
    	  case '0':
		  case '1':
		  case '2':
		  case '3':	   
          case '4':
          case '5':
          case '6':
		  case '7':
		  case '8':
		  case '9':
          case '&':
             return NumericHex( *Currptr );
     	  case  0 :
             return  Curr_Token = TOKEN_EOS;  
		  case '(':
			 Currptr++;
			 return Curr_Token = TOKEN_OPAREN;
          case  ')':
             Currptr++;
			 return Curr_Token = TOKEN_CPAREN;
          
          case '+':
			 
		     Currptr++;			
             return  Curr_Token = TOKEN_PLUS;
          case  '-':
           
		      Currptr++;		
			 return  Curr_Token  = TOKEN_MINUS;
          case '\'':
			     SkipToEoln();
				 goto skip_label;

           case  '/': 

			   if ( * (Currptr + 1) == '/' ) {
				    Currptr +=2;
				    SkipToEoln();
					goto skip_label;
               } 
               else if ( * (Currptr +1) == '*' ) {
				    Currptr+=2;
					if  (SkipMultilineComment() ) 
						  goto skip_label;

					
			   }
              		   
			   Currptr++;
               return Curr_Token  = TOKEN_DIV;
           case  '*':
               Currptr++;
			   return Curr_Token  = TOKEN_MUL;
           case '=' :
			   Currptr++;
			   return Curr_Token = TOKEN_EQUAL; 
           case '<' :
			   Currptr++;
			   return Curr_Token = isToken01();
           case '>' :
			   Currptr++;
			   return Curr_Token = isToken02();
           case '%':
			   Currptr++;
               return Curr_Token = TOKEN_MOD;
           case '"':
			   Currptr++;
			   return Curr_Token = ExtractString();
          
           default:
			   if (!isalpha(*Currptr) ) 
			   {
				   SET_LEX_ERROR(16008);
				   return TOKEN_ILLEGAL;
			   }
               return  Curr_Token = RetSymbolInfo();
			  
  			   
           
       }


	   

	   }


///////////////////////////////////////////////////////
//
//  Calls Next Token To identify Token
//  and resets input pointer
//
//

TOK_TYPE CExpLexer::PeekToken() 
{
	LPSTR temp_pointer = Currptr;
	long  oldlinenum = line_number; 

	TOK_TYPE ret_val = NextToken();

	Currptr = temp_pointer;
    line_number = oldlinenum; 
	return ret_val;


}

/////////////////////////////////////////////////
//
//
//  Retrieve the Error Code 
//
//
//

  long  CExpLexer::GetErrorCode() 
 {
   return error_code;
 }

/////////////////////////////////////////////////////
//
//
//
//
//
 long  CExpLexer::GetLineNumber() 
 {
   return line_number;
 }

 //////////////////////////////////////////////////
 //
 //
 //
 //
 long  CExpLexer::ErrorOffset()
 {
   return ( Currptr - input_text );
 }


 //EOF LEXER.CPP 
