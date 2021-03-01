/*
 * GUI.c
 *
 * Created: 2021-02-23 11:52:59
 *  Author: shirt
 */ 

#include "GUI.h"
#include "PulseGenerator.h"

void right(GUI *self, int arg0) {
	
	self->curr_section=RIGHT;
	setbits(&LCDDR3, 1, 0, 1);
	setbits(&LCDDR13, 1, 0, 0);
}

void left(GUI *self, int arg0) {
	self->curr_section=LEFT;
	setbits(&LCDDR3, 1, 0, 0);
	setbits(&LCDDR13, 1, 0, 1);
}

void render(GUI *self, int arg0) {
	
	if (self->curr_section==RIGHT) {
		printAt(arg0, 4);
		setbits(&LCDDR3, 1, 0, 1);
		setbits(&LCDDR13, 1, 0, 0);
	}
	if (self->curr_section==LEFT) {
		printAt(arg0, 0);
		setbits(&LCDDR3, 1, 0, 0);
		setbits(&LCDDR13, 1, 0, 1);
	}

}

void init_gui(GUI *self, int arg0) {
	printAt(0, 0);
	printAt(0, 4);
	setbits(&LCDDR3, 1, 0, 0);
	setbits(&LCDDR13, 1, 0, 1);
}