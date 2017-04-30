// Copyright 2017 Tarasov Oleg

#include <gtest/gtest.h>
#include "include/length_converter.h"

TEST(LengthConverterTest, Can_Create_Length_Object) {
    // Arrange
    LENGTH_TYPE type = KILOMETRE;
    double value = 11.7;

    // Act & Assert
    ASSERT_NO_THROW(new Length(type, value));
}

TEST(LengthConverterTest, Can_Conver_Into_SM) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 11.7;

    // Act
    Length length(type, value);
    
    // Assert
    ASSERT_EQ(length.ConvertTo(type), value);
}

TEST(LengthConverterTest, Can_Convert_Into_SM_Not_Equal) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 11.7;

    // Act
    Length length(type, value);
    
    // Assert
    ASSERT_NE(length.ConvertTo(type), 1.17);
}

TEST(LengthConverterTest, Can_Convert_Into_Micrometre) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 0.0117;
    double expected_value = 117.0, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(MICROMETRE);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Millimetre) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 11.7;
    double expected_value = 117.0, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(MILLIMETRE);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Decimetre) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 11.7;
    double expected_value = 1.17, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(DECIMETRE);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Metre) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 117.0;
    double expected_value = 1.17, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(METRE);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Kilometre) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 117.0;
    double expected_value = 0.00117, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(KILOMETRE);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Inch) { // дюйм
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 1.17;
    double expected_value = 0.4606299, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(INCH);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Hand) {
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 45.0;
    double expected_value = 4.429133858, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(HAND);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Link) { 
    // Arrange
    LENGTH_TYPE type = CENTIMETRE;
    double value = 11.7;
    double expected_value = 0.581603, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(LINK);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Foot) {
    // Arrange
    LENGTH_TYPE type = METRE;
    double value = 6.7;
    double expected_value = 21.981627, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(FOOT);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Yard) {
    // Arrange
    LENGTH_TYPE type = METRE;
    double value = 6.7;
    double expected_value = 7.327209, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(YARD);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Rod) {
    // Arrange
    LENGTH_TYPE type = METRE;
    double value = 6.7;
    double expected_value = 1.3322198, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(ROD);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Chain) {
    // Arrange
    LENGTH_TYPE type = KILOMETRE;
    double value = 6.7;
    double expected_value = 333.054959, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(CHAIN);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Furhlong) {
    // Arrange
    LENGTH_TYPE type = KILOMETRE;
    double value = 1.17;
    double expected_value = 5.816034, converted_value;

    // Act
    Length length(type, value);
    converted_value = length.ConvertTo(FURHLONG);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_Mile) {
    // Arrange
    LENGTH_TYPE type = KILOMETRE;
    double value = 11.7;
    double expected_value = 7.2700429, converted_value;

    // Act
    Length length(type, value);
	converted_value = length.ConvertTo(MILE);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Convert_Into_League) {
    // Arrange
    LENGTH_TYPE type = KILOMETRE;
    double value = 7.0;
    double expected_value = 1.449866, converted_value;

    // Act
    Length length(type, value);
	converted_value = length.ConvertTo(LEAGUE);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}

TEST(LengthConverterTest, Can_Do_Several_Convert) {
    // Arrange
    LENGTH_TYPE type1 = MILLIMETRE, type2 = KILOMETRE, type3 = YARD;
    double value = 7.0;
    double expected_value = 0.007655, converted_value;

    // Act
    Length length(type1, value);
    value = length.ConvertTo(type2);
    Length length2(type2, value);
	converted_value = length2.ConvertTo(YARD);
    
    // Assert
	ASSERT_NEAR(converted_value, expected_value, 0.000001);
}
