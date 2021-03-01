/*
 * GUI.h
 *
 * Created: 2021-02-23 11:53:09
 *  Author: shirt
 */ 


#ifndef GUI_H_
#define GUI_H_

#define LEFT 0
#define RIGHT 1
#define RIGHT_MARKER &LCDDR3
#define LEFT_MARKER &LCDDR8

#include "TinyTimber.h"
#include "LCDDrivers.h"
#include <stdint-gcc.h>
#include <avr/io.h>

typedef struct {
	Object super;
	uint8_t curr_section;
} GUI;

#define initGUI() {initObject(), 0}
	
void left(GUI *self, int arg0);

void right(GUI *self, int arg0);

void render(GUI *self, int arg0);

void init_gui(GUI *self, int arg0);


#endif /* GUI_H_ */