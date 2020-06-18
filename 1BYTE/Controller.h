#pragma once

#include "HeaderOfConvenience.h"

#include <vector>
#include <map>
#include <functional>


typedef unsigned char Register;
typedef unsigned char byte;


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

	std::vector<unsigned char> RAM;

	unsigned int programCount = 0;

	std::map<byte, std::pair<byte, void(*)(Controller*, byte*)>> functionMap;

	Controller() {}
	Controller(std::vector<byte> program) : RAM(program) {}

public:
	void parseInstr(byte instr);

	void run();
};
