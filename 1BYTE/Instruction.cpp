#include "Instruction.h"


void add(Controller* c, byte* params) {
	Register* a = &(c->registers.at(params[0]));
	Register* b = &(c->registers.at(params[1]));

	for (int i = 0; i < (*c).registerSize; i++) {
		if ((*a).data.test(i) && (*b).data.test(i) && (*c).flags.data.test(1)) {
			(*c).flags.data.set(1);
			(*a).data.set(i);
		} else if (((*a).data.test(i) && (*b).data.test(i)) || ((*a).data.test(i) || (*b).data.test(i)) && (*c).flags.data.test(1)) {
			(*c).flags.data.set(1);
			(*a).data.reset(i);
		} else if ((*a).data.test(i) || (*b).data.test(i)) {
			(*c).flags.data.reset(1);
			(*a).data.set(i);
		} else if ((*c).flags.data.test(1)) {
			(*c).flags.data.reset(1);
			(*a).data.set(i);
		} else {
			(*a).data.reset(i);
		}
	}

	// zflag 
	olif((*a).data.none(), (*c).flags.data.set(0), (*c).flags.data.reset(0))
}

void addi(Controller* c, byte* params) {
	Register* a = &(c->registers.at(params[0]));
	byte val = params[1];

	(*c).flags.data.reset(1);

	for (int i = 0; i < (*c).registerSize; i++) {
		if ((*a).data.test(i) && ((val >> i & 0x01) != 0) && (*c).flags.data.test(1)) {
			(*c).flags.data.set(1);
			(*a).data.set(i);
		} else if (((*a).data.test(i) && ((val >> i & 0x01) != 0) || ((*a).data.test(i) || ((val >> i & 0x01) != 0)) && (*c).flags.data.test(1))) {
			(*c).flags.data.set(1);
			(*a).data.reset(i);
		} else if ((*a).data.test(i) || ((val >> i & 0x01) != 0)) {
			(*c).flags.data.reset(1);
			(*a).data.set(i);
		} else if ((*c).flags.data.test(1)) {
			(*c).flags.data.reset(1);
			(*a).data.set(i);
		} else {
			(*a).data.reset(i);
		}
	}

	// zflag 
	olif((*a).data.none(), (*c).flags.data.set(0), (*c).flags.data.reset(0))
}

void sub(Controller* c, byte* params) {
	Register* a = &(c->registers.at(params[0]));
	Register* b = &(c->registers.at(params[1]));
	(*b).data.flip();
	byte temp[] = { params[1], (byte)0x01 };
	addi(c, temp);
	byte temp1[] = { params[0], params[1] };
	add(c, temp1);

	// zflag 
	olif((*a).data.none(), (*c).flags.data.set(0), (*c).flags.data.reset(0))
}

void subi(Controller* c, byte* params) { // does not work
	Register* a = &(c->registers.at(params[0]));
	byte val = params[1];
	val = ~val;
	byte temp[] = { val, (byte)0x01 };
	addi(c, temp);
	byte temp1[] = { params[0], params[1] };
	add(c, temp1);

	// zflag 
	olif((*a).data.none(), (*c).flags.data.set(0), (*c).flags.data.reset(0))
}

void mov(Controller* c, byte* params) {
	Register* a = &(c->registers.at(params[0]));
	Register* b = &(c->registers.at(params[1]));

	*a = *b;
}

void movi(Controller* c, byte* params) {
	Register* a = &(c->registers.at(params[0]));
	byte val = params[1];

	*a = val;
}

void halt(Controller* c, byte* params) {
	c->programCount = UINT_MAX - 1;
}

void nop(Controller* c, byte* params) {}