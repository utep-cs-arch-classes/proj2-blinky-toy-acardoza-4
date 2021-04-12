# Lab 2: Counter

Counter is a basic program that can be loaded onto an **msp430**. It allows
the use of the four buttons on the board (S1, S2, S3, S4) to control the
msp430 through four different states.

## How To:

### Compile/Run:
To compile and run Counter, go into the **/project** directory and enter
"*make load*" in the terminal with the msp430 connected to your pc. This will
load the program onto the board, ready for you to try it out!
### Clean:
To clean after Counter has been used, enter "*make clean*" on the terminal
under the **/project** directory. This will remove excess files.

## Functionality:

### S1

Button **S1** is a **reset** button that will **turn off the green and red LEDs** and stop any tone that is currently playing.

### S2

Button **S2** will display the binary number *1* by turning the **red LED on**
and the green LED off; it will also play a **low** tone.

### S3

Button **S3** will display the binary number *2* by turning the **green LED
on** and the red LED off; it will also play a **medium-range** tone.


### S4

Button **S4** will display the binary number *3* by turning on both the **red
and green LEDs**; it will also play **high** tone.
