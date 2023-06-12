 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #include "MyProcessor.h"
 #include "message.h"       // InternalMessage ....

 MyProcessor::MyProcessor( const std::string &name ) : Atomic( name )
 , In(addInputPort( "In" ))
 , Out(addOutputPort( "Out" ))

 {
 }

 Model &MyProcessor::initFunction()
  {
	cout << "MyProcessor initFunction()" << endl;
    state = passive;
    value=0;
    passivate();
	return *this ;
  }

 /*********************************************************/
 Model &MyProcessor::externalFunction( const ExternalMessage &msg )
  {
	cout << "MyProcessor externalFunction() at " << msg.time() << endl;
	if ((msg.port() == In)&&(msg.value()==0)&&(state==active) )
	{
		cout << "		 " << msg.value() << "   at " << msg.time() << endl;
		state=passive;
		holdIn(Atomic::active, 0);
	}
	if ((msg.port() == In)&&(msg.value()!=0)&&(state==passive) )
	{
		cout << "		 " << msg.value() << "   at " << msg.time() << endl;
		value=msg.value();
		state=active;
		holdIn(Atomic::active, 0);
	}
	return *this;
  }

 /*********************************************************/
 Model &MyProcessor::internalFunction( const InternalMessage & )
 {
	cout << "MyProcessor internalFunction()" << endl;
	passivate();
    return *this;
 }

 /*********************************************************/
 Model &MyProcessor::outputFunction( const InternalMessage &msg )
 {
	 cout << "MyProcessor outputFunction() at " << msg.time() << endl;
	 if(state==passive)  sendOutput( msg.time(), Out, 0) ;
	 if(state==active)  sendOutput( msg.time(), Out, value) ;


	return *this ;
 }

 /*********************************************************/
 MyProcessor::~MyProcessor()
 {
 }

