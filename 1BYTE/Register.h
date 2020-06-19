#pragma once

#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include <string>


class Register {
public:
	short size;

	boost::dynamic_bitset<> data;

	Register(short pSize) :
		size(pSize) {
		this->data = boost::dynamic_bitset<>(this->size);
	}
};