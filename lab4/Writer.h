/*
 * Writer.h
 *
 * Created: 2021-02-23 11:52:50
 *  Author: shirt
 */ 


#ifndef WRITER_H_
#define WRITER_H_


#include <stdint-gcc.h>
#include <avr/io.h>
#include "TinyTimber.h"

typedef struct {
	Object super;
}Writer;

#define initWriter() {initObject()}

void write(Writer *self, int* arg0);

#endif /* WRITER_H_ */