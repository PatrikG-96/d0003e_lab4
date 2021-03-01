/*
 * THINGS TO DO:
 * Don't need to pause the generators when swapping, makes sense when writing to different ports
 * Use port bit as parameter for Writer write(), read the pin bit, invert it, write it to the port bit
 * Fix holding escalating
 * Activate both generators
 * Save/load, setting frequency to 0 is enough to pause it
 */ 

#include "Controller.h"
#include "Joystick.h"
#include <stdbool.h>

/* React to joystick being pressed down */
void stick_down(Controller *self, int arg0) {
	self->holding_down = true;						// we are currently, to our knowledge, holding down the stick
	SYNC(self->p[self->current], dec_freq, 0);
	update_gui(self,0);
	if (!self->currently_holding) {
		self->currently_holding = true;
		AFTER(MSEC(INITIAL_DELAY), self, hold_down, 0);	// Given an initial delay, start the holding "loop"	
	}
}

/* React to joystick being pressed upwards */
void stick_up(Controller *self, int arg0) {
	self->holding_up = true;						// we are currently, to our knowledge, holding up the stick
	SYNC(self->p[self->current], inc_freq, 0);
	update_gui(self, 0);
	if (!self->currently_holding) {
		self->currently_holding = true;
		AFTER(MSEC(INITIAL_DELAY), self, hold_up, 0);	// Given an initial delay, start the holding "loop"		
	}
}

/* React to joystick being pressed to the left */
void stick_left(Controller *self, int arg0) {
	if (self->current != LEFT)						// If we are using the "left" generator, do nothing
	{
		self->current = LEFT;						// swap generator
		ASYNC(self->gui, left, 0);					// swap segment on gui
	}
	
}

/* React to joystick being pressed to the right */
void stick_right(Controller *self, int arg0) {
	if (self->current != RIGHT)						// If we are using the "left" generator, do nothing
	{
		self->current = RIGHT;						// swap generator
		ASYNC(self->gui, right, 0);					// swap segment on gui
	}
}

/* React to joystick being pressed */
void stick_pressed(Controller *self, int arg0) {
	
	uint8_t f = SYNC(self->p[self->current], get_frequency, 0);	// check if current generator is active
	
	if(f > 0) {
		SYNC(self->p[self->current], save, 0);					// if active, save current frequency and deactivate
	} else {
		SYNC(self->p[self->current], load, 0);					// if not active, load previously saved frequency and activate
	}

	update_gui(self, 0);
	
}

/*  */
void hold_down(Controller *self, int arg0) {
	
	if (joystick()==STICK_DOWN) {
		SYNC(self->p[self->current], dec_freq, 0);
		ASYNC(self->gui, render, self->p[self->current]->frequency);
		AFTER(MSEC(HOLD_DELAY), self, hold_down, 0);
	} else {
		self->currently_holding = false;
	}
	
}

void hold_up(Controller *self, int arg0) {
	if (joystick()==STICK_UP) {
		SYNC(self->p[self->current], inc_freq, 0);
		ASYNC(self->gui, render, self->p[self->current]->frequency);
		AFTER(MSEC(HOLD_DELAY), self, hold_up, 0);
	} else {
		self->currently_holding = false;
	}
}

void stick_centered(Controller *self, int arg0) {
	self->holding_up = false;
	self->holding_down = false;
}

void update_gui(Controller *self, int arg0) {
	uint8_t freq = SYNC(self->p[self->current], get_frequency, 0);
	ASYNC(self->gui, render, freq);
}