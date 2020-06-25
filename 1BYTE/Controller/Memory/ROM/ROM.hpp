#pragma once
#include<vector>
#include<cstdint>
#define ROM_SIZE 0//should be set to however big the rom is actually going to be
class ROM {
public:
	ROM(std::vector<int8_t> values);
	int8_t getByte(int16_t pos);
private:
	int8_t memory[ROM_SIZE];
};
