// Copyright 2017 Fedorov Igor

#include <string>
#include <iostream>

#include "./include/saper.h"

int main(int argc, const char** argv) {
	Saper app(9, 9, 80); 
	while (true)
		if ((app(argc, argv)) == "error" ||
			(app(argc, argv)) == "You win!" ||
			(app(argc, argv)) == "You lose" ||
			(app(argc, argv)) == "exit")
			break;
	// printf("%s\n", output.c_str());
//	fwrite()
//	std::ofstream f("dump.bin", std::binary);
//	f.write(&m, sizeof(m));
//	f.close();
	return 0;
}
