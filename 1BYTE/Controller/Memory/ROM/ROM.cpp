#include "ROM.hpp"
using namespace std;
int8_t ROM::getByte(int16_t pos){
	return this->memory[pos];
}
