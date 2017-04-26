// Copyright 2017 Komarov Nikolay

#include <string>

#include "include/programmer_calculator.h"

ProgrammerCalculator::ProgrammerCalculator() {}

std::string ProgrammerCalculator::convertDecToBin(int dec) {
    if (dec < 0) {
        return "-1";
    }
    std::string result = "";
    int quotient = dec;
    int remainder = 0;

    while (quotient >= 2) {
        remainder = quotient % 2;
        quotient = quotient / 2;
        result = std::to_string(remainder) + result;
    }

    result = std::to_string(quotient) + result;

    return result;
}

std::string ProgrammerCalculator::convertDecToOct(int dec) {
    if (dec < 0) {
        return "-1";
    }
    std::string result = "";

    return result;
}

std::string ProgrammerCalculator::convertDecToHex(int dec) {
    if (dec < 0) {
        return "-1";
    }
    std::string result = "";

    return result;
}

std::string ProgrammerCalculator::convertBinToOct(std::string bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string result = "";

    return result;
}

int ProgrammerCalculator::convertBinToDec(std::string bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return -1;
    }
    int result = 0;

    return result;
}

std::string ProgrammerCalculator::convertBinToHex(std::string bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string result = "";

    return result;
}

std::string ProgrammerCalculator::convertOctToBin(std::string oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    std::string result = "";

    return "";
}

int ProgrammerCalculator::convertOctToDec(std::string oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return -1;
    }
    int result = 0;

    return result;
}

std::string ProgrammerCalculator::convertOctToHex(std::string oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    std::string result = "";

    return result;
}

std::string ProgrammerCalculator::convertHexToBin(std::string hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    std::string result = "";

    return result;
}

std::string ProgrammerCalculator::convertHexToOct(std::string hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    std::string result = "";

    return result;
}

int ProgrammerCalculator::convertHexToDec(std::string hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return -1;
    }
    int result = 0;

    return result;
}
