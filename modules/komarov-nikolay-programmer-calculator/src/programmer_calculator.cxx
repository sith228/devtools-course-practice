// Copyright 2017 Komarov Nikolay

#include <math.h>
#include <string>
#include <vector>

#include "include/programmer_calculator.h"

std::vector<std::string> ProgrammerCalculator::triades =
    { "000", "001", "010", "011", "100", "101", "110", "111" };

std::vector<std::string> ProgrammerCalculator::tetrads =
    { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
      "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

std::vector<std::string> ProgrammerCalculator::charsSet =
{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "a", "b", "c", "d", "e", "f" };

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
    return convertBinToOct(convertDecToBin(dec));
}

std::string ProgrammerCalculator::convertDecToHex(int dec) {
    if (dec < 0) {
        return "-1";
    }
    return convertBinToHex(convertDecToBin(dec));
}

std::string ProgrammerCalculator::convertBinToOct(const std::string &bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string binCopy = bin;
    std::string result = "";
    int lenghtOfBin = binCopy.length();
    int additionalLeftZeroesCount = 3 - lenghtOfBin % 3;

    if (additionalLeftZeroesCount != 3) {
        for (int i = 0; i < additionalLeftZeroesCount; i++) {
            binCopy = "0" + binCopy;
        }
    }

    int triadsCount = binCopy.length() / 3;

    for (int i = 0; i < triadsCount; i++) {
        std::string triad = binCopy.substr(3 * (triadsCount - 1 - i), 3);

        result = std::to_string((triad[2] - '0') * 4 +
            (triad[1] - '0') * 2 +
            (triad[0] - '0')) + result;
    }

    return result;
}

int ProgrammerCalculator::convertBinToDec(const std::string &bin) {
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

std::string ProgrammerCalculator::convertBinToHex(const std::string &bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string binCopy = bin;
    std::string result = "";
    int lengthOfBin = binCopy.length();
    int additionalLeftZeroesCount = 4 - lengthOfBin % 4;

    if (additionalLeftZeroesCount != 4) {
        for (int i = 0; i < additionalLeftZeroesCount; i++) {
            binCopy = "0" + binCopy;
        }
    }

    int tetradsCount = binCopy.length() / 4;

    for (int i = 0; i < tetradsCount; i++) {
        std::string tetrad = binCopy.substr(4 * (tetradsCount - 1 - i), 4);
        result = charsSet[tetrad[3] * 8 + tetrad[2] * 4 +
            tetrad[1] * 2 + tetrad[0]] + result;
    }

    return result;
}

std::string ProgrammerCalculator::convertOctToBin(const std::string &oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int lengthOfOct = oct.length();

    for (int i = 0; i < lengthOfOct; i++) {
        result += triades[oct[i] - '0'];
    }

    return cutUnnecessaryZeroes(result);
}

int ProgrammerCalculator::convertOctToDec(const std::string &oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return -1;
    }
    return convertBinToDec(convertOctToBin(oct));
}

std::string ProgrammerCalculator::convertOctToHex(const std::string &oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    return convertBinToHex(convertOctToBin(oct));
}

std::string ProgrammerCalculator::convertHexToBin(const std::string &hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int lengthOfHex = hex.length();

    for (int i = 0; i < lengthOfHex; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result += tetrads[hex[i] - '0'];
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += tetrads[10 + hex[i] - 'a'];
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += tetrads[10 + hex[i] - 'A'];
        }
    }

    return cutUnnecessaryZeroes(result);
}

std::string ProgrammerCalculator::convertHexToOct(const std::string &hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    return convertBinToOct(convertHexToBin(hex));
}

int ProgrammerCalculator::convertHexToDec(const std::string &hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return -1;
    }
    return convertBinToDec(convertHexToBin(hex));
}


std::string ProgrammerCalculator::cutUnnecessaryZeroes(const std::string &bin) {
    std::string binCopy = bin;
    int lengthOfBin = binCopy.length();
    int positionOfTheFirstOne = binCopy.find("1");

    if (positionOfTheFirstOne < lengthOfBin) {
        binCopy = binCopy.substr(positionOfTheFirstOne, lengthOfBin);
    }

    return binCopy;
}
