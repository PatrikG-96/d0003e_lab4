
#include "InterruptHandler.h"
#include "LCDDrivers.h"
#include "Joystick.h"
#include "GUI.h"

void interrupt(InterruptHandler *self, int arg0) {
	
	int val = joystick();
	
	
	switch(joystick()) {
		case STICK_RIGHT:

			ASYNC(self->controller, stick_right, 0);
			break;
		case STICK_LEFT:

			ASYNC(self->controller, stick_left, 0);
			break;
		case STICK_UP:
	
			ASYNC(self->controller, stick_up, 0);
			break;
		case STICK_DOWN:

			ASYNC(self->controller, stick_down, 0);
			break;
		case STICK_PRESSED:

			ASYNC(self->controller, stick_pressed, 0);
			break;
	}
	
}

void init(InterruptHandler *self, int arg0) {
	
	
	initJoystick();
	initLCD();
	ASYNC(self->controller->gui, init_gui, 0);
	ASYNC(self->controller->p[0], activate, 0);
	ASYNC(self->controller->p[1], activate, 0);
}

