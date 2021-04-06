#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

char toggle_red()		/* toggle red led */
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
  return 1;			
}

char toggle_green()	/* toggle green led */
{
  char state = 0;

  switch (state) {
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  return 1;
}

void reset() {
  red_on = 0;
  green_on = 0;
  led_update();
}
void state_advance(char state)		/* alternate between toggling red & green */
{
  char changed = 0;
  switch (state) {
  case 0: changed = 0; reset(); break;
  case 1: changed = toggle_red(); break;
  case 2: changed = toggle_red(); toggle_green(); break;
  case 3: changed = toggle_red(); break;
  }

  led_changed = changed;
  led_update();
}

