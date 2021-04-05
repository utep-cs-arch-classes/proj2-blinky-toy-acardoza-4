#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  int changed = 0;  

  static enum {A=0, B=1, C=2, D=3} state = A;
  switch (state) {
  case A: changed = 0; state = B; break;
  case B: changed = toggle_red(); state = C; break;
  case C: changed = toggle_green() + 1; state = D; break;
  case D: changed = toggle_green() + toggle_red() + 1; state = A; break;
  }

  led_changed = changed;
  led_update();
}

