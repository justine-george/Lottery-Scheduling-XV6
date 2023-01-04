# Lottery Scheduler for xv6 Operating System

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.
I implemented lottery scheduling, a change from the default round-robin 
scheduling in xv6 kernel. Lottery scheduling is a randomized algorithm 
that allows processes to receive a proportional share of the CPU without 
explicitly tracking how long each process has been run. This lottery ticket 
scheduler assigns every process a number of tickets, and then draws a ticket,
and the process that owns the winning ticket is the next process to run.
