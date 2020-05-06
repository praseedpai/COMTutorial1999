// A Generic Stack Class
//   
// 
///////////////////////////////////////////////////////////

#ifndef STACK_DOT_H
#define STACK_DOT_H   // Avoid multiple inclusion 


// Enumeration For Types of Data
// Stored in a Stack Element 

enum ValType 
{ 
  long_val,     // Long Value  
  double_val,   // Double
  illegal_val   // Illegal value
 };



typedef struct
{
  union
  {
	 long lval;
	 double dval;
  };

  ValType type_info;

}STACK_ELEM_TYPE;



template <class TYPE ,int STACK_SIZE = 10>


class CompilerStack {

private:
	int   stack_ptr;
	int   num_element_allocated;
	TYPE  **val;
    
public:

	void ExpandStack()  
	{
        int old_alloc = num_element_allocated; 
		    num_element_allocated +=25;

        val = static_cast<TYPE **>(
    	     realloc(val , num_element_allocated*sizeof(TYPE))); 

		  while ( old_alloc < num_element_allocated  )
		     val[old_alloc++] = static_cast<TYPE *>(
		  	 malloc(sizeof(TYPE))); 


	}
	
	CompilerStack()
	{

		num_element_allocated =(STACK_SIZE == 0 ) ?
			100 : STACK_SIZE;

        val = static_cast<TYPE **>(
			malloc(num_element_allocated*sizeof(TYPE)));

		for( int i=0 ; i < num_element_allocated ; ++i )
		    val[i] = static_cast<TYPE *>(
			malloc(sizeof(TYPE)));

        
	
  	    stack_ptr =-1;


	}


	~CompilerStack()
	{
        for( int i=0 ; i < num_element_allocated ; ++i )
		         free( val[i] );

        free( val );
    } 


	void Clear()
	{
       stack_ptr = -1;
    }
   
   BOOL Push( TYPE *value )
   {

      if ( stack_ptr > num_element_allocated-2 )
	          ExpandStack();
	        	 

	  
	  
	 
	  
      memcpy( val[++stack_ptr] ,
		      value , 
			  sizeof(TYPE) );
      
      return TRUE;
   }

   int Size() {
	   return  ( stack_ptr + 1 );
   }


   BOOL  Pop(TYPE *value) {

	 if ( stack_ptr == -1 )
		 return FALSE;


	 memcpy( value , 
	         val[stack_ptr] , 
	    	 sizeof(TYPE) );

	 
	 stack_ptr--;
	
 
     return TRUE;
	   
          

   }

 BOOL  Top(TYPE *value) {

	 if ( stack_ptr == -1 )
		 return FALSE;


	 memcpy( value , 
	         val[stack_ptr] , 
	    	 sizeof(TYPE) );

	 return TRUE;
	   
          

   }

 BOOL Empty() { return ( stack_ptr == -1 ) ? TRUE : FALSE;  } 

};



#endif
