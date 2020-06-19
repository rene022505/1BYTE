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
	/// Register for temporary result storage
	/// </summary>
	Register operationResult;

	unsigned int programCount = 0;

	short registerSize;

	std::map<byte, std::pair<int, fctPtr>> functionMap;

	Controller(int registerCount, short registerSize) :
		registers(std::vector<Register>(registerCount, Register(registerSize))),
		operationResult(Register(registerSize)), registerSize(registerSize) {}

public:
	void parseInstr(byte instr);

	void run();
};
