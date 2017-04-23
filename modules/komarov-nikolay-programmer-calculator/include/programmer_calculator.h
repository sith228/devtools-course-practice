// Copyright 2017 Komarov Nikolay

#ifndef MODULES_KOMAROV_NIKOLAY_PROGRAMMER_CALCULATOR_INCLUDE_PROG_CALC_H_
#define MODULES_KOMAROV_NIKOLAY_PROGRAMMER_CALCULATOR_INCLUDE_PROG_CALC_H_

#include <string>

class ProgrammerCalculator {
 public:
    ProgrammerCalculator();

    std::string convertDecToBin(int dec);
    std::string convertDecToOct(int dec);
    std::string convertDecToHex(int dec);

    std::string convertBinToOct(std::string bin);
    int convertBinToDec(std::string bin);
    std::string convertBinToHex(std::string bin);

    std::string convertOctToBin(std::string oct);
    int convertOctToDec(std::string oct);
    std::string convertOctToHex(std::string oct);

    std::string convertHexToBin(std::string hex);
    std::string convertHexToOct(std::string hex);
    int convertHexToDec(std::string hex);

 private:
    ~ProgrammerCalculator();
};

#endif  // MODULES_KOMAROV_NIKOLAY_PROGRAMMER_CALCULATOR_INCLUDE_PROG_CALC_H_
