#pragma once

#include "HeaderOfConvenience.h"
#include "Register.h"

#include <vector>
#include <map>
#include <functional>


class Controller {
public:
	std::vector<Register> registers;

	/// <summary>
	/// Register containing operation flags
	/// <para>Bit0: zflag - zero flag</para>
	/// <para>Bit1: cflag - carry </para>
	/// </summary>
	Register flags = Register(2);

	/// <summary>
	/// Register for storing values from immediate instructions like addi/subi etc
	/// </summary>
	Register immediateValue = Register(1);

	/// <summary>
	/// Register for temporary result storage
	/// <para>Register0: temp register for addi</para>
	/// <para>Register1: temp register for subi</para>
	/// </summary>
	std::vector<Register> temp;

	unsigned int programCount = 0;

	short registerSize;

	std::map<byte, std::pair<int, fctPtr>> functionMap;

	Controller(int _registerCount, short _registerSize) :
		registers(std::vector<Register>(_registerCount, Register(_registerSize))),
		temp(std::vector<Register>(2, Register(_registerSize))), registerSize(_registerSize) {}

public:
	void parseInstr(byte);

	void run(byte*, int);
};
