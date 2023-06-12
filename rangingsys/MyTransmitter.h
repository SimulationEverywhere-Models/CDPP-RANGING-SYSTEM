 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #ifndef __MYTRANSMITTER_H
 #define __MYTRANSMITTER_H

 #include "atomic.h"      // class Atomic
 #include "string.h"	  // class String

 class MyTransmitter : public Atomic
 {
   public:
	       MyTransmitter( const std::string &name = "MyTransmitter" );  //Default constructor
	       virtual std::string className() const {  return "MyTransmitter" ;}
	       ~MyTransmitter();

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
 };

#endif
