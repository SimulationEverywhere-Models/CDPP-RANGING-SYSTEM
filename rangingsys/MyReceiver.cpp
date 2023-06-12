 /***********************************************
 *
 *  DESCRIPTION: Atomic Model Base Station (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 *
 ***********************************************/

 #include "MyReceiver.h"
 #include "message.h"       // InternalMessage ....

 MyReceiver::MyReceiver( const std::string &name ) : Atomic( name )
 , In1(addInputPort( "In1" ))
 , In2(addInputPort( "In2" ))
 , Out(addOutputPort( "Out" ))
 {
 }

 Model &MyReceiver::initFunction()
  {
	cout << "MyReceiver initFunction()" << endl;
    state = ready;
    passivate();
	return *this ;
  }

 /*********************************************************/
 Model &MyReceiver::externalFunction( const ExternalMessage &msg )
  {
	cout << "MyReceiver externalFunction() at " << msg.time() << endl;
	if ((msg.port() == In1)&&(msg.value()==1)&&(state==ready) )
	{
		cout << "	receiving	 " << msg.value() << "   at " << msg.time() << endl;
		state=receiving;
		holdIn(Atomic::active, 0);
		//sendOutput( msg.time(), Out, 1) ;
	}
	if ((msg.port() == In2)&&(msg.value()==0)&&(state==receiving) )
	{
		cout << "	disabled	 " << msg.value() << "   at " << msg.time() << endl;
		state=disable;
		holdIn(Atomic::active, 0);
	}
	if ((msg.port() == In2)&&(msg.value()==1)&&(state==disable) )
	{
		cout << "	being ready	 " << msg.value() << "   at " << msg.time() << endl;
		state=ready;
		holdIn(Atomic::active, 0);
	}
	return *this;
  }

 /*********************************************************/
 Model &MyReceiver::internalFunction( const InternalMessage & )
 {

	passivate();
    return *this;
 }

 /*********************************************************/
 Model &MyReceiver::outputFunction( const InternalMessage &msg )
 {
	 if(state==receiving) sendOutput( msg.time(), Out, 1) ;
	return *this ;
 }

 /*********************************************************/
 MyReceiver::~MyReceiver()
 {
 }

