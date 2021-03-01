
#ifndef INTERRUPTHANDLER_H_
#define INTERRUPTHANDLER_H_

#include "GUI.h"
#include "Controller.h"
#include <avr/io.h>

#define STICK_CENTER 0
#define STICK_LEFT 1
#define STICK_RIGHT 2
#define STICK_UP 3
#define STICK_DOWN 4
#define STICK_PRESSED 5

typedef struct {
	Object super;
	Controller *controller;
}InterruptHandler;

#define initInterruptHandler(c) {initObject(), c}

void interrupt(InterruptHandler *self, int arg0);

void init(InterruptHandler *self, int arg0);

#endif /* INTERRUPTHANDLER_H_ */