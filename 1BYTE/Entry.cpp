#include <iostream>
#include <fstream>
#include <string>

#include "Controller.h"
#include "Instruction.h"


int main(int argc, char** args) {
	/*if (argc != 2) {
		std::cout << "Usage: 1BYTE.exe [file]" << std::endl;
		return 2;
	}
	std::string filePath(args[1]);
	if (filePath.substr(filePath.size() - 5) != ".1bin") {
		std::cout << "Please select a valid .1basm file!" << std::endl;
		return 3;
	}
	std::ifstream asmIn(filePath, std::ifstream::in | std::ifstream::binary);
	if (!asmIn.is_open() || !asmIn.good()) {
		std::cout << "Something went wrong, please try again!" << std::endl;
		return 4;
	}*/

	Controller c;
	c.mainRegister[0] = 0xf;
	c.mainRegister[1] = 0xf;

	c.functionMap.insert(std::pair<byte, std::pair<byte, void(*)(Controller*, byte*)>>{ (byte)0x02, std::pair<byte, void(*)(Controller*, byte*)>{(byte)0x02, add}});

	byte asd[2] = { (byte)0x0, (byte)0x1 };
	c.functionMap.at((byte)0x02).second(&c, asd);

	return 0;
}