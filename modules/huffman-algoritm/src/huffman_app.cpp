// Copyright 2017 Dryakhlov Dmitry

#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include "include/Huffman_app.h"
#include "include/huffman.h"

HuffmanAlgApp::HuffmanAlgApp() : message_("") {}

void HuffmanAlgApp::Help(const char* appname, const char* message) {
     message_ = std::string(message) +
        "This is a huffman algoritm application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + ", 'encode' , " + "<string to encode>" +
        ", or \n" +
        "  $ " + appname + ", 'encode and decode' , " + "<string to encode>";
}

bool HuffmanAlgApp::ValidateNumberOfArguments(int argc, const char** argv) {
    Arguments args;
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc == 2) {
        Help(argv[0], "ERROR: Should be more than 1 arguments\n\n");
        return false;
    } else if (argc > 3) {
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
        if (argv[1] != std::string("encode") &&
           (argv[1] != std::string("encode and decode"))) {
            throw std::string("command is uncorrect");
        }
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    args.string_to_encode = argv[2];
    args.table = new std::map< char, std::vector<bool >>;
    std::string huffman_cod;
    std::string huffman_decod;
    stream << "input string: " << args.string_to_encode << "\n";
    Huffman Huff;
    if (argv[1] == std::string("encode")) {
       try {
            huffman_cod = Huff.Encode(args.string_to_encode, args.table);
            stream << huffman_cod;
       }
       catch (std::string& str) {
            delete args.table;
            return str;
       }
    } else if (argv[1] == std::string("encode and decode")) {
        try {
            huffman_cod = Huff.Encode(args.string_to_encode, args.table);
            huffman_decod = Huff.Decode(huffman_cod, *args.table);
            stream <<"huffman cod: "<< huffman_cod << "\n" <<"string: "
            << huffman_decod << "\n";
        }
        catch (std::string& str) {
            delete args.table;
            return str;
        }
    }

    delete args.table;
    message_ = stream.str();
    return message_;
}
