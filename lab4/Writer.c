#include "Writer.h"
#include "LCDDrivers.h"

void write(Writer *self, int* arg0) {
	
	uint8_t portnr = arg0[1];
	uint8_t state = arg0[0];

	//if (portnr == 4)
	//{
//
		//writeChar(state + '0', 2);
	//} 
	//else if (portnr == 6)
	//{
	//
		//writeChar(state + '0', 3);
	//}
	
	setbits(&PORTE, 1, portnr, state);
}

