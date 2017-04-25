// Copyright 2017 Komarov Nikolay

#include <string>

#include "include/programmer_calculator.h"

ProgrammerCalculator::ProgrammerCalculator() {}

std::string ProgrammerCalculator::convertDecToBin(int dec) {
    if (dec < 0) return "";
    std::string result = "";
    int quotient = dec;
    int remainder = 0;
    while (quotient >= 2) {
        quotient = quotient / 2;
        remainder = quotient % 2;
        result = std::to_string(remainder) + result;
    }
    result = std::to_string(quotient) + result;
    return result;
}

std::string ProgrammerCalculator::convertDecToOct(int dec) {
    if (dec < 0) return "";
    std::string result = "";

    return result;
}

std::string ProgrammerCalculator::convertDecToHex(int dec) {
    if (dec < 0) return "";
    std::string result = "";

    return result;
}

std::string ProgrammerCalculator::convertBinToOct(std::string bin) {
    return "";
}

int ProgrammerCalculator::convertBinToDec(std::string bin) {
    return 0;
}

std::string ProgrammerCalculator::convertBinToHex(std::string bin) {
    return "";
}

std::string ProgrammerCalculator::convertOctToBin(std::string oct) {
    return "";
}

int ProgrammerCalculator::convertOctToDec(std::string oct) {
    return 0;
}

std::string ProgrammerCalculator::convertOctToHex(std::string oct) {
    return "";
}

std::string ProgrammerCalculator::convertHexToBin(std::string hex) {
    return "";
}

std::string ProgrammerCalculator::convertHexToOct(std::string hex) {
    return "";
}

int ProgrammerCalculator::convertHexToDec(std::string hex) {
    return 0;
}
