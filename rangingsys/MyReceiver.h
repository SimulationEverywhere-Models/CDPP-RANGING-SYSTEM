 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #ifndef __MYRECEIVER_H
 #define __MYRECEIVER_H

 #include "atomic.h"      // class Atomic
 #include "string.h"	  // class String

 class MyReceiver : public Atomic
 {
   public:
	       MyReceiver( const std::string &name = "MyReceiver" );  //Default constructor
	       virtual std::string className() const {  return "MyReceiver" ;}
	       ~MyReceiver();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	        const Port &In1, &In2;
	        Port &Out;
         	enum State{
			            ready,
			            receiving,
			            disable
		              };
		    State state;
 };

#endif
