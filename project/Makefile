# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../demos/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: counter.elf 

#additional rules for files
counter.elf: ${COMMON_OBJECTS}  counter.o stateMachines.o led.o switches.o wdInterruptHandler.o reset_assembly.o buzzer.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: counter.elf
	msp430loader.sh counter.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

reset_assembly.o: stateMachines.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
