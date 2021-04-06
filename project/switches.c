#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch1, switch2, switch3, switch4, switch_state_down, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch1 = (p2val & SW1) ? 0 : 1;
  switch2 = (p2val & SW2) ? 0 : 1;
  switch3 = (p2val & SW3) ? 0 : 1;
  switch4 = (p2val & SW3) ? 0 : 1;

  if (switch1) {
    state_advance(1);
    //do something
  }
  if (switch2) {
    state_advance(2);
    //do something
  }
  if (switch3) {
    state_advance(3);
    //do something
  }
  else if (switch4){
    state_advance(4);
    //do something
  }
  switch_state_changed = 1;
  led_update();
}