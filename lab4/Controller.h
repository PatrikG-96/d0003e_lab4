/*
 * Controller.h
 *
 * Created: 2021-02-23 12:29:45
 *  Author: shirt
 */ 


#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#include "TinyTimber.h"
#include "PulseGenerator.h"
#include "GUI.h"
#include <stdint-gcc.h>
#include <stdbool.h>

#define LEFT 0
#define RIGHT 1
#define HOLD_DELAY 250
#define INITIAL_DELAY 500


typedef struct {
	Object super;
	PulseGenerator* p[2];
	uint8_t current;
	GUI* gui;
	bool holding_up;
	bool holding_down;
	bool currently_holding;
}Controller;

#define initController(p1, p2, g) {initObject(), {p1, p2}, 0, g, 0, 0}
	
void stick_left(Controller *self, int arg0);
void stick_right(Controller *self, int arg0);
void stick_up(Controller *self, int arg0);
void stick_down(Controller *self, int arg0);
void stick_pressed(Controller *self, int arg0);
void stick_centered(Controller *self, int arg0);
void hold_down(Controller *self, int arg0);
void hold_up(Controller *self, int arg0);
void update_gui(Controller *self, int arg0);

#endif /* CONTROLLER_H_ */