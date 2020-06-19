#pragma once


#define sbit0(reg) reg |= 0x01
#define sbit1(reg) reg |= 0x02
#define sbit2(reg) reg |= 0x04
#define sbit3(reg) reg |= 0x08
#define sbit4(reg) reg |= 0x10
#define sbit5(reg) reg |= 0x20
#define sbit6(reg) reg |= 0x40
#define sbit7(reg) reg |= 0x80

#define cbit0(reg) reg &= 0xFE
#define cbit1(reg) reg &= 0xFD
#define cbit2(reg) reg &= 0xFB
#define cbit3(reg) reg &= 0xF7
#define cbit4(reg) reg &= 0xEF
#define cbit5(reg) reg &= 0xDF
#define cbit6(reg) reg &= 0xBF
#define cbit7(reg) reg &= 0x7F

typedef unsigned char Register;
typedef unsigned char byte;

Register getBitAt(Register reg, int bit);

void cBit(Register* reg, int bit);

void sBit(Register* reg, int bit);

#define olif(condition, tru, fals) if (condition) { tru; } else { fals; }

#define fctPtr void(*)(Controller*, byte*)
