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

#define olif(condition, tru, fals) if (condition) { tru; } else { fals; }

typedef unsigned char Register;

class Controller {
public:
	Register mainRegister[10]{ 0 };

	/// <summary>
	/// Register containing operation flags
	/// <para>Bit0: zflag - zero flag</para>
	/// <para>Bit1: cflag - carry for the last operation</para>
	/// <para>Bit2: nflag - negative result in last operation</para>
	/// <para>Bit3: </para>
	/// <para>Bit4: </para>
	/// <para>Bit5: </para>
	/// <para>Bit6: </para>
	/// <para>Bit7: </para>
	/// </summary>
	Register flags = 0;

public:
	void add(Register*, Register*);
	void sub(Register*, Register*);
};