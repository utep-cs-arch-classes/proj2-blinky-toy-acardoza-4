//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

int main(void) {
  configureClocks(); /* setup master oscillator, CPU & peripheral clocks */
  switch_init();
  led_init();
  reset();
  enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}
