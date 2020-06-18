#include "Instruction.h"

void add(Controller* c, byte* params) {
	Register* a = &(c->mainRegister[params[0]]);
	Register* b = &(c->mainRegister[params[1]]);

	// cflag
	olif(*a + *b > 0xFF, sbit1(c->flags), cbit1(c->flags))

	*a = *a + *b;

	// zflag 
	olif(*a == 0, sbit0(c->flags), cbit0(c->flags))
}

void sub(Controller* c, byte* params) {
	Register* a = &(c->mainRegister[params[0]]);
	Register* b = &(c->mainRegister[params[1]]);

	// nflag
	olif(*a - *b < 0, sbit2(c->flags), cbit2(c->flags))

	*a = *a - *b;

	//zflag
	olif(*a == 0, sbit0(c->flags), cbit0(c->flags))
}