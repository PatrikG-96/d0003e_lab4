
#include "InterruptHandler.h"


/* Handles joystick interrupts */
void interrupt(InterruptHandler *self, int arg0) {
	
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


int joystick() {
	
	if (~PINB & (1 << 7)) {
		return STICK_DOWN;
	}
	
	if (~PINB & (1 << 4)) {
		return STICK_PRESSED;
	}
	
	if (~PINB & (1 << 6)) {
		return STICK_UP;
	}
	
	if (~PINE & (1 << 3)) {
		return STICK_RIGHT;
	}
	
	if (~PINE & (1 << 2)) {
		return STICK_LEFT;
	}
	
	return STICK_CENTER;
}

void initJoystick() {
	DDRB = DDRB & ~((1 << 7) | (1 << 6) |(1 << 4));
	DDRE = DDRE & ~( ( 1 << 2) | (1 << 3));
	PORTB = PORTB | ((1 << 7)| (1 << 6 ) | (1 << 4));
	PORTE = PORTE | ( (1 << 2) | ( 1 << 3));
	
	
	// Enables external interrupt and sets the interrupt to PCINT15..8
	EIMSK |= (1 << PCIE1) | (1 << PCIE0);
	
	// Enables interrupt on PCINT15
	PCMSK1 |= (1 << PCINT15)|(1 << PCINT14)|(1 << PCINT12);
	PCMSK0 |= (1 << PCINT3)|(1 << PCINT2);
	
	// Sets interrupt control to generate an interruption on a falling edge
	EICRA |= (1 << ISC01);
	
}