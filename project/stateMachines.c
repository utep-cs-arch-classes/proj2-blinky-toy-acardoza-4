#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
/*
char toggle_red()		/* toggle red led 
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

char toggle_green()	/* toggle green led 
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
*/
void reset()
{
  red_on = 0;
  green_on = 0;
  dimming = 0;
  led_update();
}

void set_dim(){
  while(dimming == 1) {
    unsigned int i,j;
    for( i = 1; i < 1200; i++) {
      green_on = 1;
      red_on = 0;
      led_changed = 1;
      led_update();

      for(j = i; j > 0; j--) {
	__delay_cycles(1);
      }

      green_on = 0;
      red_on = 1;
      led_changed = 1;
      led_update();

      for(j = (1200 - i); j > 0; j--) {
	__delay_cycles(1);
      }
      
    }    
  }
}
void state_advance(char state)		/* alternate between toggling red & green */
{
  if (state == '0') {
    //reset()
    reset_assembly();
    //set_dim();
  }
  else if (state == '1') {
    red_on = 0;
    green_on = 1;
    led_changed = 1;
    //dimming = 1;
    //set_dim();
    led_update();
  }
  else if (state == '2') {
    red_on = 1;
    green_on = 0;
    led_changed = 1;
    led_update();
  }
  else if(state == '3') {
    red_on = 1;
    green_on = 1;
    led_changed = 1;
    led_update();
  }
  led_update();
}

