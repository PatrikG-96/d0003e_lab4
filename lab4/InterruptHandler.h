/*
 * InterruptHandler.h
 *
 * Created: 2021-02-25 18:29:18
 *  Author: shirt
 */ 


#ifndef INTERRUPTHANDLER_H_
#define INTERRUPTHANDLER_H_

#include "Controller.h"
#include <avr/io.h>



typedef struct {
	Object super;
	Controller *controller;
}InterruptHandler;

#define initInterruptHandler(c) {initObject(), c}

void interrupt(InterruptHandler *self, int arg0);

void init(InterruptHandler *self, int arg0);

#endif /* INTERRUPTHANDLER_H_ */