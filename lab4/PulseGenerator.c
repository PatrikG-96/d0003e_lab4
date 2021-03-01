#include "PulseGenerator.h"
#include "LCDDrivers.h"

uint8_t inc_freq(PulseGenerator *self, int arg0) {
	if (self->frequency < 99) {
		self->frequency++;	
	}
	
	// Frequency went from 0 to 1

}
uint8_t dec_freq(PulseGenerator *self, int arg0) {
	if (self->frequency > 0) {
		self->frequency--;
	}
}

void activate(PulseGenerator *self, int arg0) {
	self->active = true;
	generate(self, 0);
}

void save(PulseGenerator *self, int arg0) {
	self->saved = self->frequency;
	self->frequency = 0;
}

void load(PulseGenerator *self, int arg0) {
	self->frequency = self->saved;
}

void generate(PulseGenerator *self, int arg0) {
	
	if (self->active == true) {
		
		if (self->frequency > 0) {
			self->state = !self->state;
			int arguments[2] = {self->state, self->port_bit};
			AFTER(USEC(1000000/self->frequency/2), self, generate, 0);
			SYNC(self->writer, write, arguments);
		} else {
			int arguments[2] = {0, self->port_bit};
			SYNC(self->writer, write, arguments);
			AFTER(USEC(1000000/2), self, generate, 0);
		}
		
	}
}

uint8_t get_frequency(PulseGenerator *self, int arg0) {
	return self->frequency;
}

