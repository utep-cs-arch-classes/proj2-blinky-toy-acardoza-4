# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../demos/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf 

#additional rules for files
main.elf: ${COMMON_OBJECTS}  main.o stateMachines.o led.o switches.o wdInterruptHandler.o reset_assembly.o buzzer.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

reset_assembly.o: stateMachines.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
