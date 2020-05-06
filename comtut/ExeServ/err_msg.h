
#ifndef ERR_MSG_DOT_H
#define ERR_MSG_DOT_H 
struct err_msgs
{
  long number;
  char *error_str;
}Error_Info[] = {

  {16000,"string literal not properly terminated with delimiter (\")" },
  {16001,"Multi line Comment not  terminated" } , 	  
  {16002 ,"Illegal floating point format"}, 
  {16003 ,"Illegal floating point value"}, 
  {16004 ,"Hexadecimal value not in proper format"},  
  {16005 ,"H expected after &"}, 
  {16006 ,"Trailing 'B' not found after binary string"},
  {16007 ,"Trailing 'H' not found after hex digits"}, 
  {16008 ,"Bad token in input"},  
  {16009 ,"Numeric Value not in proper format"},
  {16010 ,"String Literal can't span multiple lines"},
  {18001 , "Internal Compiler Error ( Failed to initialize lexical analyser )"},
  {18002 , "Expected Long Data Type"}, 
  {18003 , "')' Expected"},
  {18004 , "Undefined Constant"},
  {18005 , "Constant Expected"},
  {18006 , "Circular Reference of Consant"},
  {18007 , "Undefined Error"},
  {18008 , "illegal operation - Data type incompatibility"},
  {18009 , "% , >> , << operation ,use long data type"},
  {18010 , "Bit Wise Operators Need Long Data Type"},
  {18011, "Empty Script"},
  {18012 , "Invalid Const Expression" },
  {18013 , "( expected"}
 
};


#endif 


