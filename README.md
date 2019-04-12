# RTT Calculation over a connected UDP-Connection
Updated : 20 Dec 2018, Simpy Parveen(simpy.parveen1@ucalgary.ca)

Experiment to demonstrate network performance on UDP channel:
Completed implementation for client-server network on UDP transport layer. 
The experiment was basically to implement see the calculated RTT values between client and server.
The experiment shows that RTT in microseconds for same client performing direct time synchronization for 100 times to calculate
Return trip time(RTT). 
The client records its time when it first sends the synchronization request to server as given in Figure 4 and records 
the time when it receives server’s response. 

The results for the experiment when the client sends 10bytes payload data and 
receives 10bytes payload data from server as response for 100 packets are : 
  Average RTT : 2697.46 microseconds, 
  Maximum RTT : 4681 microseconds, 
  Minimum RTT : 2218 microseconds.
  
  
Usage :-

  Compile : gcc server.c -o server
 
  Run : ./server
  
  
   Compile : gcc client.c -o client
 
  Run : ./client SERVER-IP ClientHello
  
  
  
  
