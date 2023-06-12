 /***********************************************
 *
 *  DESCRIPTION: Atomic Model User Equipment (BS)
 *
 *  AUTHOR: Misagh Tavanpour
 *
 *  DATE: 19/09/2014
 **********************************************/

 #include <modeladm.h>
 #include <mainsimu.h>

 #include "MyReceiver.h"
 #include "MyTransmitter.h"
 #include "MyProcessor.h"
 #include "MyTimer.h"



 void MainSimulator::registerNewAtomics()
 {
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MyReceiver>() , "MyReceiver" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MyTransmitter>() , "MyTransmitter" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MyProcessor>() , "MyProcessor" ) ;
   SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MyTimer>() , "MyTimer" ) ;

 }
