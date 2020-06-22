#include <iostream>
#include <fstream>
#include <string>

#include "HeaderOfConvenience.h"
#include "Controller.h"
#include "Instruction.h"
#include "Register.h"


int oldMain(int argc, char** args) {
	//if (argc != 2) {
	//	std::cout << "Usage: 1BYTE.exe [file]" << std::endl;
	//	return 2;
	//}
	//std::string filePath(args[1]);
	//if (filePath.substr(filePath.size() - 5) != ".1bin") {
	//	std::cout << "Please select a valid .1basm file!" << std::endl;
	//	return 3;
	//}
	//std::ifstream in(filePath, std::ifstream::in | std::ifstream::binary);
	//if (!in.is_open() || !in.good()) {
	//	std::cout << "Something went wrong, please try again!" << std::endl;
	//	return 4;
	//}

	// copy program into ram
	//in.seekg(0, in.end);
	//int length = in.tellg();
	//in.seekg(0, in.beg);
	//byte* program = new byte[length];
	//in.read((char*)program, length);

	Controller c(10, 8);
	//c.run(program, length);
	c.registers.at(0).data = boost::dynamic_bitset<>(c.registerSize ,0xf0);
	c.registers.at(1).data = boost::dynamic_bitset<>(c.registerSize, 0x0f);

	c.functionMap.insert(std::pair<byte, std::pair<byte, fctPtr>>{ (byte)0x02, std::pair<byte, fctPtr>{(byte)0x02, subi}});

	byte asd[2] = { (byte)0x0, (byte)0x0f };
	c.functionMap.at((byte)0x02).second(&c, asd);

	std::cin.get();

	return 0;
}