// Copyright 2017 Komarov Nikolay

#include <math.h>
#include <string>

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
    return convertBinToOct(convertDecToBin(dec));
}

std::string ProgrammerCalculator::convertDecToHex(int dec) {
    if (dec < 0) {
        return "-1";
    }
    return convertBinToHex(convertDecToBin(dec));
}

std::string ProgrammerCalculator::convertBinToOct(std::string bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int lenghtOfBin = bin.length();
    int additionalLeftZeroesCount = 3 - lenghtOfBin % 3;

    if (additionalLeftZeroesCount != 3) {
        for (int i = 0; i < additionalLeftZeroesCount; i++) {
            bin = "0" + bin;
        }
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
            result = "7" + result;
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
    int additionalLeftZeroesCount = 4 - lengthOfBin % 4;

    if (additionalLeftZeroesCount != 4) {
        for (int i = 0; i < additionalLeftZeroesCount; i++) {
            bin = "0" + bin;
        }
    }

    int tetradsCount = bin.length() / 4;

    for (int i = 0; i < tetradsCount; i++) {
        std::string triad = bin.substr(4 * (tetradsCount - 1 - i), 4);

        if (triad == "0000") {
            result = "0" + result;
        } else if (triad == "0001") {
            result = "1" + result;
        } else if (triad == "0010") {
            result = "2" + result;
        } else if (triad == "0011") {
            result = "3" + result;
        } else if (triad == "0100") {
            result = "4" + result;
        } else if (triad == "0101") {
            result = "5" + result;
        } else if (triad == "0110") {
            result = "6" + result;
        } else if (triad == "0111") {
            result = "7" + result;
        } else if (triad == "1000") {
            result = "8" + result;
        } else if (triad == "1001") {
            result = "9" + result;
        } else if (triad == "1010") {
            result = "a" + result;
        } else if (triad == "1011") {
            result = "b" + result;
        } else if (triad == "1100") {
            result = "c" + result;
        } else if (triad == "1101") {
            result = "d" + result;
        } else if (triad == "1110") {
            result = "e" + result;
        } else if (triad == "1111") {
            result = "f" + result;
        }
    }

    return result;
}

std::string ProgrammerCalculator::convertOctToBin(std::string oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int lengthOfOct = oct.length();

    for (int i = 0; i < lengthOfOct; i++) {
        switch (oct[i]) {
        case '0':
            result += "000";
            break;
        case '1':
            result += "001";
            break;
        case '2':
            result += "010";
            break;
        case '3':
            result += "011";
            break;
        case '4':
            result += "100";
            break;
        case '5':
            result += "101";
            break;
        case '6':
            result += "110";
            break;
        case '7':
            result += "111";
            break;
        }
    }

    return cutUnnecessaryZeroes(result);
}

int ProgrammerCalculator::convertOctToDec(std::string oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return -1;
    }
    return convertBinToDec(convertOctToBin(oct));
}

std::string ProgrammerCalculator::convertOctToHex(std::string oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    return convertBinToHex(convertOctToBin(oct));
}

std::string ProgrammerCalculator::convertHexToBin(std::string hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int lengthOfHex = hex.length();

    for (int i = 0; i < lengthOfHex; i++) {
        switch (hex[i]) {
        case '0':
            result += "0000";
            break;
        case '1':
            result += "0001";
            break;
        case '2':
            result += "0010";
            break;
        case '3':
            result += "0011";
            break;
        case '4':
            result += "0100";
            break;
        case '5':
            result += "0101";
            break;
        case '6':
            result += "0110";
            break;
        case '7':
            result += "0111";
            break;
        case '8':
            result += "1000";
            break;
        case '9':
            result += "1001";
            break;
        case 'a':
        case 'A':
            result += "1010";
            break;
        case 'b':
        case 'B':
            result += "1011";
            break;
        case 'c':
        case 'C':
            result += "1100";
            break;
        case 'd':
        case 'D':
            result += "1101";
            break;
        case 'e':
        case 'E':
            result += "1110";
            break;
        case 'f':
        case 'F':
            result += "1111";
            break;
        }
    }

    return cutUnnecessaryZeroes(result);
}

std::string ProgrammerCalculator::convertHexToOct(std::string hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    return convertBinToOct(convertHexToBin(hex));
}

int ProgrammerCalculator::convertHexToDec(std::string hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return -1;
    }
    return convertBinToDec(convertHexToBin(hex));
}


std::string ProgrammerCalculator::cutUnnecessaryZeroes(std::string bin) {
    int lengthOfBin = bin.length();
    int positionOfTheFirstOne = bin.find("1");

    if (positionOfTheFirstOne < lengthOfBin) {
        bin = bin.substr(positionOfTheFirstOne, lengthOfBin);
    }

    return bin;
}
