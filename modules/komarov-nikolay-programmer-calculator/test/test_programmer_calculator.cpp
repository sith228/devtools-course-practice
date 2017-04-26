// Copyright 2017 Komarov Nikolay

#include <gtest/gtest.h>
#include <string>

#include "include/programmer_calculator.h"

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Dec_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string bin = "1101010110111";
    int dec = 6839;

    binResult = programmer_calculator.convertDecToBin(dec);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Bin_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string bin = "101011011001";
    int dec = 2777;

    decResult = programmer_calculator.convertBinToDec(bin);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Dec_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string bin = "-1";
    int dec = -83904;

    binResult = programmer_calculator.convertDecToBin(dec);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Dec_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string oct = "-1";
    int dec = -49;

    octResult = programmer_calculator.convertDecToOct(dec);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Dec_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string hex = "-1";
    int dec = -8657;

    hexResult = programmer_calculator.convertDecToHex(dec);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Bin_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string bin = "69838gjik";
    std::string oct = "-1";

    octResult = programmer_calculator.convertBinToOct(bin);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Bin_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string bin = "433572";
    int dec = -1;

    decResult = programmer_calculator.convertBinToDec(bin);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Bin_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string bin = "9jg348";
    std::string hex = "-1";

    hexResult = programmer_calculator.convertBinToHex(bin);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Oct_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string oct = "86205";
    std::string bin = "-1";

    binResult = programmer_calculator.convertOctToBin(oct);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Oct_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string oct = "jg930#&";
    int dec = -1;

    decResult = programmer_calculator.convertOctToDec(oct);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Oct_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string oct = "289360";
    std::string hex = "-1";

    hexResult = programmer_calculator.convertOctToHex(oct);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Hex_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string hex = "49a7feg";
    std::string bin = "-1";

    binResult = programmer_calculator.convertHexToBin(hex);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Hex_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string hex = "ig5095uj";
    std::string oct = "-1";

    octResult = programmer_calculator.convertHexToOct(hex);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
        Wrong_Result_Of_Converting_Hex_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator = *new ProgrammerCalculator();
    std::string hex = "8592^";
    int dec = -1;

    decResult = programmer_calculator.convertHexToDec(hex);

    EXPECT_EQ(decResult, dec);
}
