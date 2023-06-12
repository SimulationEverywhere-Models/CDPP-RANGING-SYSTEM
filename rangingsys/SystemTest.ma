[top]
components : MyReceiver@MyReceiver ttp
in : In
out : Out1 Out2
Link : In In1@MyReceiver
Link : Out@MyReceiver In@ttp
Link : Out1@ttp In2@MyReceiver
Link : Out2@ttp Out1
Link : Out3@ttp Out2

[ttp] 
components : MyTimer@MyTimer MyProcessor@MyProcessor MyTransmitter@MyTransmitter
in : In
out : Out1 Out2 Out3
Link : In In@MyTimer
Link : Out2@MyTimer In@MyTransmitter
Link : Out3@MyTimer In@MyProcessor
Link : Out1@MyTimer Out1
Link : Out@MyProcessor Out3
Link : Out@MyTransmitter Out2