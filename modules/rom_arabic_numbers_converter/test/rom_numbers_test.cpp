#include <gtest\gtest.h>
#include <string>
#include "include/rom_numbers_converter.h"

using std::string;


//ROM TO ARABIC

TEST(RomNumConverter, convetr_rom_to_arabic_I_1) {
    // Arrange
    int temp;
    string bufstr ="I";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp,1);
}

TEST(RomNumConverter, convetr_rom_to_arabic_V_5) {
    // Arrange
    int temp;
    string bufstr = "V";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 5);
}

TEST(RomNumConverter, convetr_rom_to_arabic_IV_4) {
    // Arrange
    int temp;
    string bufstr = "IV";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp,4);
}

TEST(RomNumConverter, convetr_rom_to_arabic_X_10) {
    // Arrange
    int temp;
    string bufstr = "X";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 10);
}

TEST(RomNumConverter, convetr_rom_to_arabic_IX_9) {
    // Arrange
    int temp;
    string bufstr = "IX";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 9);
}

TEST(RomNumConverter, convetr_rom_to_arabic_L_50) {
    // Arrange
    int temp;
    string bufstr = "L";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 50);
}

TEST(RomNumConverter, convetr_rom_to_arabic_XL_40) {
    // Arrange
    int temp;
    string bufstr = "XL";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 40);
}

TEST(RomNumConverter, convetr_rom_to_arabic_XC_90) {
    // Arrange
    int temp;
    string bufstr = "XC";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 90);
}

TEST(RomNumConverter, convetr_rom_to_arabic_C_100) {
    // Arrange
    int temp;
    string bufstr = "C";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 100);
}

TEST(RomNumConverter, convetr_rom_to_arabic_D_500) {
    // Arrange
    int temp;
    string bufstr = "D";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 500);
}

TEST(RomNumConverter, convetr_rom_to_arabic_CD_400) {
    // Arrange
    int temp;
    string bufstr = "CD";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 400);
}

TEST(RomNumConverter, convetr_rom_to_arabic_CM_900) {
    // Arrange
    int temp;
    string bufstr = "CM";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 900);
}

TEST(RomNumConverter, convetr_rom_to_arabic_M_1000) {
    // Arrange
    int temp;
    string bufstr = "M";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 1000);
}

TEST(RomNumConverter, convetr_rom_to_arabic_MMMCMXCIX_3999_maximum) {
    // Arrange
    int temp;
    string bufstr = "MMMCMXCIX";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 3999);
}

TEST(RomNumConverter, convetr_rom_to_arabic_CDXLIV_444) {
    // Arrange
    int temp;
    string bufstr = "CDXLIV";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 444);
}

TEST(RomNumConverter, convetr_rom_to_arabic__2345) {
    // Arrange
    int temp;
    string bufstr = "MMCCCXLV";
    RomNumConverter Convert;
    // Act
    temp = Convert.convert_rom_to_arabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 2345);
}



//ARABIC TO ROM


TEST(RomNumConverter, convetr_arabic_to_rom_I_1) {
    // Arrange
    int temp=1;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "I");
}

TEST(RomNumConverter, convetr_arabic_to_rom_V_5) {
    // Arrange
    int temp = 5;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "V");
}

TEST(RomNumConverter, convetr_arabic_to_rom_IV_4) {
    // Arrange
    int temp = 4;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "IV");
}

TEST(RomNumConverter, convetr_arabic_to_rom_X_10) {
    // Arrange
    int temp = 10;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "X");
}

TEST(RomNumConverter, convetr_arabic_to_rom_IX_9) {
    // Arrange
    int temp = 9;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "IX");
}

TEST(RomNumConverter, convetr_arabic_to_rom_L_50) {
    // Arrange
    int temp = 50;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "L");
}

TEST(RomNumConverter, convetr_arabic_to_rom_XL_40) {
    // Arrange
    int temp = 40;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "XL");
}

TEST(RomNumConverter, convetr_arabic_to_rom_XC_90) {
    // Arrange
    int temp = 90;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "XC");
}

TEST(RomNumConverter, convetr_arabic_to_rom_C_100) {
    // Arrange
    int temp = 100;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "C");
}

TEST(RomNumConverter, convetr_arabic_to_rom_D_500) {
    // Arrange
    int temp = 500;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "D");
}

TEST(RomNumConverter, convetr_arabic_to_rom_CD_400) {
    // Arrange
    int temp = 400;
    string bufstr ;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "CD");
}

TEST(RomNumConverter, convetr_arabic_to_rom_CM_900) {
    // Arrange
    int temp = 900;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "CM");
}

TEST(RomNumConverter, convetr_arabic_to_rom_M_1000) {
    // Arrange
    int temp = 1000;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "M");
}

TEST(RomNumConverter, convetr_arabic_to_rom_MMMCMXCIX_3999_maximum) {
    // Arrange
    int temp = 3999;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "MMMCMXCIX");
}

TEST(RomNumConverter, convetr_arabic_to_rom_CDXLIV_444) {
    // Arrange
    int temp = 444;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "CDXLIV");
}

TEST(RomNumConverter, convetr_arabic_to_rom_MMCCCXLV_2345) {
    // Arrange
    int temp = 2345;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.convert_arabic_to_rom(temp);
    // Assert
    EXPECT_EQ(bufstr, "MMCCCXLV");
}
