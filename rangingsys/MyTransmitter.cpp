 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #include "MyTransmitter.h"
 #include "message.h"       // InternalMessage ....

 MyTransmitter::MyTransmitter( const std::string &name ) : Atomic( name )
 , In(addInputPort( "In" ))
 , Out(addOutputPort( "Out" ))
 {
 }

 Model &MyTransmitter::initFunction()
  {
	cout << "MyTransmitter initFunction()" << endl;
    state = passive;
    passivate();
	return *this ;
  }

 /*********************************************************/
 Model &MyTransmitter::externalFunction( const ExternalMessage &msg )
  {
	cout << "MyTransmitter externalFunction() at " << msg.time() << endl;
	if ((msg.port() == In)&&(msg.value()==0)&&(state==active) )
	{
		cout << "		 " << msg.value() << "   at " << msg.time() << endl;
		state=passive;
		holdIn(Atomic::active, 0);

	}
	if ((msg.port() == In)&&(msg.value()==1)&&(state==passive) )
	{
		cout << "		 " << msg.value() << "   at " << msg.time() << endl;
		state=active;
		holdIn(Atomic::active, 0);
	}
	return *this;
  }

 /*********************************************************/
 Model &MyTransmitter::internalFunction( const InternalMessage & )
 {
	cout << "MyTransmitter internalFunction()" << endl;
	passivate();
    return *this;
 }

 /*********************************************************/
 Model &MyTransmitter::outputFunction( const InternalMessage &msg )
 {
	 cout << "MyTransmitter outputFunction() at " << msg.time() << endl;
	 if(state==passive)  sendOutput( msg.time(), Out, 0) ;
	 if(state==active)  sendOutput( msg.time(), Out, 1) ;


	return *this ;
 }

 /*********************************************************/
 MyTransmitter::~MyTransmitter()
 {
 }

