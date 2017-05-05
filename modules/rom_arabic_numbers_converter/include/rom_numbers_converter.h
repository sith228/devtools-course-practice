// Copyright 2017 Ivan Kochin



#ifndef ROM_NUMBERS_CONVERTER_H_
#define ROM_NUMBERS_CONVERTER_H_

#include <string>
#include <iostream>

using namespace std;

class RomNumConverter {
public:
	string convert_arabic_to_rom(int temp);
	int convert_rom_to_arabic(string bufstr);
};
#endif  // ROM_NUMBERS_CONVERTER_H_
