// Copyright 2017 Dryakhlov Dmitry

#include <stdlib.h>
#include <string>
#include <vector>

#include "include/Huffman_app.h"
#include "include/huffman.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;
HuffmanAlgApp::HuffmanAlgApp() : message_("") {}

void HuffmanAlgApp::Help(const char* appname, const char* message) {
	message_ =
		std::string(message) +
		"This is a huffman algoritm application.\n\n" +
		"Please provide arguments in the following format:\n\n" +
		"  $ " + appname + ", 'encode' , " + "<string to encode>" +
		", or \n" +
		"  $ " + appname + ", 'decode' , " + "<string to decode>";
}

bool HuffmanAlgApp::ValidateNumberOfArguments(int argc, const char** argv) {
	Arguments args;
	if (argc == 1) {
		Help(argv[0]);
		return false;
	}
	else if (argc == 2) {
		Help(argv[0], "ERROR: Should be more than 1 arguments\n\n");
		return false;
	}
	else if (argc > 3) {
		Help(argv[0], "ERROR: Should be less than 3 arguments\n\n");
		return false;
	}
	return true;
}

std::string HuffmanAlgApp::operator()(int argc, const char** argv) {
	Arguments args;
	if (!ValidateNumberOfArguments(argc, argv)) {
		return message_;
	}

	try {
		if (argv[1] != std::string("encode") && (argv[1] != std::string("decode"))) {
			throw std::string("command is uncorrect");
		}
		else
			if (argv[1] == std::string("decode")) {
				if (args.table == nullptr) {
					throw std::string("ERROR: after encode only\n\n");
				}
			}
			else exit;
	}

	catch (std::string& str) {
		return str;
	}

	std::ostringstream stream;
	args.string_to_encode = argv[1];
	args.table = new std::map< char, std::vector<bool >>;
	Huffman Huff;
	if (argv[1] == std::string("encode")) {
		try {
			std::string output_string = Huff.Encode(args.string_to_encode, args.table);
			stream << output_string;
		}
		catch (std::string& str) {
			delete args.table;
			return str;
		}
	}
	else if (argv[1] == std::string("decode")) {
		try {
			std::string output_string = Huff.Decode(args.string_to_encode, *args.table);
			stream << output_string;
		}
		catch (std::string& str) {
			delete args.table;
			return str;
		}
	}

	//delete args.polynom_coef;
	message_ = stream.str();
	return message_;
}
