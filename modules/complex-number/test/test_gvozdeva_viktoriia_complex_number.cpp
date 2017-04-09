// Copyright 2017 Gvozdeva Viktoriia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gvozdeva_Viktoriia_ComplexNumberTest, Multiplication_by_zero_is_zero) {
	// Arrange
	ComplexNumber z(2.0, 4.0);
	ComplexNumber zero(0.0, 0.0);

	// Act
	ComplexNumber result = z * zero;

	// Assert
	EXPECT_DOUBLE_EQ(result.getRe(), 0.0);
	EXPECT_DOUBLE_EQ(result.getIm(), 0.0);
}

TEST(Gvozdeva_Viktoriia_ComplexNumberTest, Can_compare_objects) {
	// Arrange
	ComplexNumber z1(3.0, 6.0);
	ComplexNumber z2(z1);

	// Act
	bool result = (z1 == z2);

	// Assert
	EXPECT_TRUE(result);
}

TEST(Gvozdeva_Viktoriia_ComplexNumberTest, Division_number_by_number_is_equal_to_one) {
	// Arrange
	ComplexNumber z1(3.0, 6.0);

	// Act
	ComplexNumber result = z1 / z1;

	// Assert
	EXPECT_DOUBLE_EQ(result.getRe(), 1.0);
	EXPECT_DOUBLE_EQ(result.getIm(), 0.0);
}

TEST(Gvozdeva_Viktoriia_ComplexNumberTest, Check_associativity_of_multiplication) {
	// Arrange
    ComplexNumber z1(3.0, 6.0);
	ComplexNumber z2(2.0, 4.0);
	ComplexNumber z3(1.0, 2.0);

	// Act
	ComplexNumber result = (z1 * z2) * z3;

	// Assert
	ComplexNumber result_ = z1 * (z2 * z3);
	EXPECT_EQ(result, result_);
}

TEST(Gvozdeva_Viktoriia_ComplexNumberTest, Module_of_multiplication_is_multiplication_of_modules) {
	// Arrange
	double re1 = 3.0;
	double re2 = 2.0;
	double im1 = 6.0;
	double im2 = 4.0;
	ComplexNumber z1(re1, im1);
	ComplexNumber z2(re2, im2);

	// Act
	ComplexNumber result = z1 * z2;
	double module_z1= sqrt(re1 * re1 + im1 * im1);
	double module_z2 = sqrt(re2 * re2 + im2 * im2);
	double re_com = result.getRe();
	double re_im = result.getIm();
	double module_com = sqrt(re_com * re_com + re_im * re_im);

	// Assert
	ASSERT_DOUBLE_EQ(module_z1 * module_z2, module_com);
}
