// Copyright 2017 Komarov Nikolay

#include <string>
#include <math.h>

#include "include/programmer_calculator.h"

ProgrammerCalculator::ProgrammerCalculator() {}

std::string ProgrammerCalculator::convertDecToBin(int dec) {
    if (dec < 0) {
        return "-1";
    }
    std::string result = "";
    int quotient = dec;

    while (quotient >= 2) {
        int remainder = quotient % 2;
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
    int lenghtOfBin = bin.length();
    int additionalLeftZeroesCount = 3 - lenghtOfBin % 3;

    for (int i = 0; i < additionalLeftZeroesCount; i++) {
        bin = "0" + bin;
    }

    int triadsCount = bin.length() / 3;

    for (int i = 0; i < triadsCount; i++) {
        std::string triad = bin.substr(3 * (triadsCount - 1 - i), 3);

        if (triad == "000") {
            result = "0" + result;
        } else if (triad == "001") {
            result = "1" + result;
        } else if (triad == "010") {
            result = "2" + result;
        } else if (triad == "011") {
            result = "3" + result;
        } else if (triad == "100") {
            result = "4" + result;
        } else if (triad == "101") {
            result = "5" + result;
        } else if (triad == "110") {
            result = "6" + result;
        } else if (triad == "111") {
            result = "1" + result;
        }
    }

    return result;
}

int ProgrammerCalculator::convertBinToDec(std::string bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return -1;
    }
    int result = 0;
    int lengthOfBin = bin.length();

    for (int i = 0; i < lengthOfBin; i++) {
        if (bin[i] == '1') {
            result += pow(2, lengthOfBin - 1 - i);
        }
    }

    return result;
}

std::string ProgrammerCalculator::convertBinToHex(std::string bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int lengthOfBin = bin.length();

    for (int i = 0; i < lengthOfBin; i++) {
        if (bin[i] == '1') {
            
        }
    }

    return result;
}

std::string ProgrammerCalculator::convertOctToBin(std::string oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    std::string result = "";

    return result;
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
