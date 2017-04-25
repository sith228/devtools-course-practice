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
