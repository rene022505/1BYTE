#include "Instruction.h"

void add(Controller* c, byte* params) {
	Register* a = &(c->registers.at(params[0]));
	Register* b = &(c->registers.at(params[1]));

	for (int i = 0; i < 8; i++) {
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

void sub(Controller* c, byte* params) {
}