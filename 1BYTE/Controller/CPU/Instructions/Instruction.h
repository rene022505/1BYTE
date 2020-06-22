#pragma once

#include "./../../Controller.h"


class Instruction {
public:
	/// <summary>
	/// Instruction binary code
	/// </summary>
	const unsigned char opcode;
	
	/// <summary>
	/// Method that is run when the instruction gets called
	/// </summary>
	const void (*run)(Controller*);

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="_opcode">Instruction binary code</param>
	/// <param name="_func">Instruction logic</param>
	/// <returns></returns>
	Instruction(unsigned char _opcode, const void(*_func)(Controller*)) : opcode(_opcode), run(_func) {}
};