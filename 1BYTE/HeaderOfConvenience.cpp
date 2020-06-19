#include "HeaderOfConvenience.h"


Register getBitAt(Register reg, int bit) {
	switch (bit) {
	case 0:
		return reg & 0x01;
	case 1:
		return reg & 0x02;
	case 2:
		return reg & 0x04;
	case 3:
		return reg & 0x08;
	case 4:
		return reg & 0x10;
	case 5:
		return reg & 0x20;
	case 6:
		return reg & 0x40;
	case 7:
		return reg & 0x80;
	default:
		return reg;
	}
}

void cBit(Register* reg, int bit) {
	switch (bit) {
	case 0:
		*reg &= 0xFE;
		break;
	case 1:
		*reg &= 0xFD;
		break;
	case 2:
		*reg &= 0xFB;
		break;
	case 3:
		*reg &= 0xF7;
		break;
	case 4:
		*reg &= 0xEF;
		break;
	case 5:
		*reg &= 0xDF;
		break;
	case 6:
		*reg &= 0xBF;
		break;
	case 7:
		*reg &= 0x7F;
	}
}

void sBit(Register* reg, int bit) {
	switch (bit) {
	case 0:
		*reg |= 0x01;
		break;
	case 1:
		*reg |= 0x02;
		break;
	case 2:
		*reg |= 0x04;
		break;
	case 3:
		*reg |= 0x08;
		break;
	case 4:
		*reg |= 0x10;
		break;
	case 5:
		*reg |= 0x20;
		break;
	case 6:
		*reg |= 0x40;
		break;
	case 7:
		*reg |= 0x80;
	}
}