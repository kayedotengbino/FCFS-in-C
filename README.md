# FCFS-in-C
Static Array Implementation of the FCFS scheduling algorithm

With this scheme, the process that requests the CPU first is allocated the CPU first. The 
implementation of the FCFS policy is easily managed with a FIFO queue. When a process 
enters the ready queue, its PCB is linked onto the tail of the queue. When the CPU is free, it is 
allocated to the process at the head of the queue. The running process is then removed from 
the queue.
 As an example, consider the following set of processes, they all arrived at time 0 with the 
order P1, P2, P3, P4, with the length of the CPU time given in milliseconds.

Process|Burst time
-------|----------
P1|6
P2|8  
P3|7       
P4|3   

Consider also the waiting time and turnaround time of each process, the average waiting 
time and turnaround time.
