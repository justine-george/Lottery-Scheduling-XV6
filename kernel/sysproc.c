#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"
/* The following code is added by Justine George JXG210092, Gautham Shaji GXS210034
 */
// Header file that contains struct pstat
#include "pstat.h"
/* End of code added */

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/* The following code is added by Justine George JXG210092, Gautham Shaji GXS210034
 */
// Set the number of tickets of the current running process
int
sys_settickets(void) 
{
  int ticketCount;
  // Argument passed in the user level (int) is captured here
  argint(0, &ticketCount); 
  if (ticketCount < 1)
    return -1; // return -1 on error
  // Call kernel level function with the arguments from user level
  return settickets(ticketCount);
}

// Get process statistics
int
sys_getpinfo(void)
{
  struct pstat *ps;
  // Argument passed in the user level (struct pstat) is captured here
  if (argptr(0, (void*)&ps, sizeof(*ps)) < 0)
    return -1; // return -1 on error
  if (ps == NULL)
    return -1; // return -1 if ps is NULL
  // Call kernel level function with the arguments from user level
  return getpinfo(ps); 
}
/* End of code added */
