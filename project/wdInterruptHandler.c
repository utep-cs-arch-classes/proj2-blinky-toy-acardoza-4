#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) {
    state_advance(0);
  }
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & SWITCHES) {             /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;               /* clear pending sw interrupts */
    switch_interrupt_handler();
  }
}
