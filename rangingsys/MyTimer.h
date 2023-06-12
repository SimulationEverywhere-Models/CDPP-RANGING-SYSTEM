 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #ifndef __MYTIMER_H
 #define __MYTIMER_H

 #include "atomic.h"      // class Atomic
 #include "string.h"	  // class String

 class MyTimer : public Atomic
 {
   public:
	       MyTimer( const std::string &name = "MyTimer" );  //Default constructor
	       virtual std::string className() const {  return "MyTimer" ;}
	       ~MyTimer();

   protected:
	          Model &initFunction();
	          Model &externalFunction( const ExternalMessage & );
	          Model &internalFunction( const InternalMessage & );
	          Model &outputFunction( const InternalMessage & );

   private:
	        const Port &In;
	        Port  &Out1 ;
	        Port  &Out2 ;
	        Port  &Out3 ;
	        Time comptime,count;
         	enum State{
			            waiting,
			            computing,
		              };
		    State state;
		    int timecount;
 };

#endif   //__BS_H
