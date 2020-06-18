#include "Controller.h"


void Controller::add(Register* a, Register* b) {
	// cflag
	olif(*a + *b > 0xFF, sbit1(flags), cbit1(flags))

		* a = *a + *b;

	// zflag 
	olif(*a == 0, sbit0(flags), cbit0(flags))
}

void Controller::sub(Register* a, Register* b) {
	// nflag
	olif(*a - *b < 0, sbit2(flags), cbit2(flags))

	*a = *a - *b;

	//zflag
	olif(*a == 0, sbit0(flags), cbit0(flags))
}