/* The following code is added by Justine George JXG210092, Gautham Shaji GXS210034
 */
#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

void spin(int factor) {
  int i = 0;
  int j = 0;
  int k = 0;
  for (i = 0; i < 500; i++) {
    for (j = 0; j < 20000 * factor; j++) {
      k = j % 10;
      k = k + 1;
    }
  }
}

void print(struct pstat *st) {
  int i, aticks, bticks, cticks;
  for (i = 0; i < NPROC; i++) {
    if (st->tickets[i] == 300)
      aticks = st->ticks[i];
    else if (st->tickets[i] == 200)
      bticks = st->ticks[i];
    else if (st->tickets[i] == 100)
      cticks = st->ticks[i];
  }
  printf(1, "%d,%d,%d\n\n", aticks, bticks, cticks);
}

// pass time factor as argument during runtime
int main(int argc, char **argv) {
  int low = 100, med = 200, high = 300;

  struct pstat st;
  int factor = atoi(argv[1]);

  settickets(low);
  if (fork() == 0) { 
    settickets(med);
    if (fork() == 0) {
      settickets(high);
      spin(factor);
      getpinfo(&st);
      print(&st);
    }
  }
  spin(factor);
  while(wait() > -1);
	
  exit();
}
/* End of code added */
