// Copyright 2017 Komarov Nikolay

#ifndef MODULES_PROGRAMMER_CALCULATOR_INCLUDE_PROGRAMMER_CALCULATOR_H_
#define MODULES_PROGRAMMER_CALCULATOR_INCLUDE_PROGRAMMER_CALCULATOR_H_

#include <string>
#include <vector>

class ProgrammerCalculator {
 public:
    ProgrammerCalculator();

    std::string convertDecToBin(int dec);
    std::string convertDecToOct(int dec);
    std::string convertDecToHex(int dec);

    std::string convertBinToOct(const std::string &bin);
    int convertBinToDec(const std::string &bin);
    std::string convertBinToHex(const std::string &bin);

    std::string convertOctToBin(const std::string &oct);
    int convertOctToDec(const std::string &oct);
    std::string convertOctToHex(const std::string &oct);

    std::string convertHexToBin(const std::string &hex);
    std::string convertHexToOct(const std::string &hex);
    int convertHexToDec(const std::string &hex);

 private:
    static std::vector<std::string> triades;
    static std::vector<std::string> tetrads;
    static std::vector<std::string> charsSet;
    std::string cutUnnecessaryZeroes(const std::string &bin);
};

#endif  // MODULES_PROGRAMMER_CALCULATOR_INCLUDE_PROGRAMMER_CALCULATOR_H_
