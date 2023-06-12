 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #include "MyTimer.h"
 #include "message.h"       // InternalMessage ....

 MyTimer::MyTimer( const std::string &name ) : Atomic( name )
 , In(addInputPort( "In" ))
 , Out1(addOutputPort( "Out1" ))
 , Out2(addOutputPort( "Out2" ))
,  Out3(addOutputPort( "Out3" ))
 ,comptime(00,00,02,00)
, count(00,00,01,00)

 {
 }

 Model &MyTimer::initFunction()
  {
	cout << "MyTimer initFunction()" << endl;
    state = waiting;
    timecount=0;
    holdIn(Atomic::active, count);
	return *this ;
  }

 /*********************************************************/
 Model &MyTimer::externalFunction( const ExternalMessage &msg )
  {
	cout << "MyTimer externalFunction() at " << msg.time() << endl;
	if ((msg.port() == In)&&(msg.value()==1) )
	{
		cout << "		 " << msg.value() << "   at " << msg.time() << endl;
		state=computing;
		holdIn(Atomic::active, 0);
	}
	return *this;
  }

 /*********************************************************/
 Model &MyTimer::internalFunction( const InternalMessage & )
 {
	cout << "MyTimer internalFunction()" << endl;
	if (state == waiting )
		{ cout << "		 waiting" << endl;
		  timecount=timecount+1;
		  holdIn(Atomic::active, count);
		}
	if (state == computing )
		{cout << "		 computing" << endl;
		state = waiting;
		timecount=0;
		holdIn(Atomic::active, comptime);
		}
    return *this;
 }

 /*********************************************************/
 Model &MyTimer::outputFunction( const InternalMessage &msg )
 {
	 cout << "MyTimer outputFunction() at " << msg.time() << endl;
	 if (state == computing){
		 sendOutput( msg.time(), Out1, 0) ;
		 sendOutput( msg.time(), Out2, 0) ;
		 sendOutput( msg.time(), Out3, timecount) ;
		 }
	 if((state==waiting)&&(timecount==0)) {
		 sendOutput( msg.time(), Out1, 1) ;
		 sendOutput( msg.time(), Out2, 1) ;
		 sendOutput( msg.time(), Out3, 0) ;
	 }


	return *this ;
 }

 /*********************************************************/
 MyTimer::~MyTimer()
 {
 }
