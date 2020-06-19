#include "Instruction.h"

void add(Controller* c, byte* params) {
	Register* a = &(c->mainRegister[params[0]]);
	Register* b = &(c->mainRegister[params[0]]);

	for (int i = 0; i < 8; i++) {
		if (getBitAt(*a, i) != 0 && getBitAt(*b, i) != 0 && getBitAt((c->flags), 1) != 0) {
			sBit(&(c->flags), 1);
			sBit(&(c->operationResult), i);
		} else if (getBitAt(*a, i) != 0 && getBitAt(*b, i) != 0 || ((getBitAt(*a, i) != 0 || getBitAt(*b, i) != 0) && getBitAt((c->flags), 1) != 0)) {
			sBit(&(c->flags), 1);
			cBit(&(c->operationResult), i);
		} else if (getBitAt(*a, i) != 0 || getBitAt(*b, i) != 0) {
			cBit(&(c->flags), 1);
			sBit(&(c->operationResult), i);
		} else if (getBitAt((c->flags), 1) != 0) {
			cBit(&(c->flags), 1);
			sBit(&(c->operationResult), i);
		} else {
			cBit(&(c->operationResult), i);
		}
	}

	*a = c->operationResult;

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