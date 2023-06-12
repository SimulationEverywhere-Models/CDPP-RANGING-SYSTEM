 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #ifndef __MYPROCESSOR_H
 #define __MYPROCESSOR_H

 #include "atomic.h"      // class Atomic
 #include "string.h"	  // class String

 class MyProcessor : public Atomic
 {
   public:
	       MyProcessor( const std::string &name = "MyProcessor" );  //Default constructor
	       virtual std::string className() const {  return "MyProcessor" ;}
	       ~MyProcessor();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	        const Port &In;
	        Port &Out;
         	enum State{
			            active,
			            passive,
		              };
		    State state;
		    int value;
 };

#endif
