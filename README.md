# Lottery Scheduler for xv6 Operating System

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

The existing round-robin scheduling algorithm in the xv6 kernel was 
modified to implement lottery scheduling. This randomized approach 
allows for processes to receive a proportional allocation of CPU time 
without requiring explicit tracking of the duration of execution for 
each process. In the lottery ticket scheduler, each process is assigned 
a number of tickets and a winning ticket is drawn to determine the next 
process to be executed. This method allows for a more equitable 
distribution of CPU resources among processes.
