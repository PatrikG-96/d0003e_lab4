/*
 * PulseGenerator.h
 *
 * Created: 2021-02-23 11:52:28
 *  Author: shirt
 */ 


#ifndef PULSEGENERATOR_H_
#define PULSEGENERATOR_H_

#include "TinyTimber.h"
#include "Writer.h"
#include <stdint-gcc.h>
#include <stdbool.h>

typedef struct {
	Object super;
	uint8_t state;
	uint8_t port_bit;
	uint8_t active;
	uint8_t frequency;
	uint8_t saved;
	Writer* writer;
} PulseGenerator;

#define initPulseGenerator(pb,wr) {initObject(), 0, pb, 0, 0, 0, wr}

uint8_t inc_freq(PulseGenerator *self, int arg0);
uint8_t dec_freq(PulseGenerator *self, int arg0);
void pause(PulseGenerator *self, int arg0);
void resume(PulseGenerator *self, int arg0);
void save(PulseGenerator *self, int arg0);
void activate(PulseGenerator *self, int arg0);
void load(PulseGenerator *self, int arg0);
uint8_t get_frequency(PulseGenerator *self, int arg0);


void generate(PulseGenerator *self, int arg0);


#endif /* PULSEGENERATOR_H_ */