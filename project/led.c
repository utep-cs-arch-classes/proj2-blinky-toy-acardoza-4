#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0;
int led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_update(0);
}

void led_update()
{
  if (led_changed = 1) {
    P1OUT |= LED_GREEN;
  }
  else if(state_num = 2){
    P1OUT &= (0xff^LEDS); // clear bit for off leds
  }
  else if(led_changed = 3){
    P1OUT == 0xff;
  }
}

