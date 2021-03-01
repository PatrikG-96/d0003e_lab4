/*
 * lab4.c
 *
 * Created: 2021-02-23 11:51:05
 * Author : shirt
 */ 

#include <avr/io.h>
#include "Controller.h"
#include "GUI.h"
#include "InterruptHandler.h"
#include "PulseGenerator.h"
#include "TinyTimber.h"
#include "Writer.h"


int main(void)
{
	return 0;
	Writer wr = initWriter();
	PulseGenerator p1 = initPulseGenerator(4, &wr);
	PulseGenerator p2 = initPulseGenerator(6, &wr);
	GUI g = initGUI();
    Controller c = initController(&p1, &p2, &g);
	InterruptHandler i = initInterruptHandler(&c);
	INSTALL(&i, interrupt, IRQ_PCINT0);
	INSTALL(&i, interrupt, IRQ_PCINT1);
	return TINYTIMBER(&i, init, 0);
}

