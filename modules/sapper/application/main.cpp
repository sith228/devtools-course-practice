// Copyright 2017 Fedorov Igor


#include <string>
#include <iostream>

#include "./include/saper.h"

int main(int argc, const char** argv) {
	Saper app(9, 9, 80); 
	std::string output = app(argc, argv);
	printf("%s\n", output.c_str());
	return 0;
}
