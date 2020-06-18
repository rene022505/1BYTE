#include <iostream>
#include <fstream>
#include <string>

#include "Controller.h"


int main(int argc, char** args) {
	/*if (argc != 2) {
		std::cout << "Usage: 1BYTE.exe [file]" << std::endl;
		return 2;
	}
	std::string filePath(args[1]);
	if (filePath.substr(filePath.size() - 6) != ".1basm") {
		std::cout << "Please select a valid .1basm file!" << std::endl;
		return 3;
	}
	std::ifstream asmIn(filePath, std::ifstream::in);
	if (!asmIn.is_open() || !asmIn.good()) {
		std::cout << "Something went wrong, please try again!" << std::endl;
		return 4;
	}*/

	Controller c;

	c.mainRegister[0] = 0xF;
	c.mainRegister[1] = 0xF;

	c.add(&c.mainRegister[0], &c.mainRegister[1]);
	c.add(&c.mainRegister[0], &c.mainRegister[1]);
	c.sub(&c.mainRegister[0], &c.mainRegister[1]);
	c.sub(&c.mainRegister[1], &c.mainRegister[0]);

	return 0;
}