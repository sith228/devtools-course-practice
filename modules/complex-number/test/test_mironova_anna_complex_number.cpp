// Copyright 2017 Mironova Anna

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mironova_Anna_ComplexNumberTest, Can_Get_Imaginary) {
	// Arrange
	double im = 25.0;
	ComplexNumber z(0.0, im);

	// Act
	double actual_im=z.getIm();

	// Assert
	EXPECT_EQ(im,actual_im);
}

TEST(Mironova_Anna_ComplexNumberTest, Can_Multiply_Purely_Imaginary_Complex_and_Complex) {
	// Arrange
	ComplexNumber z1;
	ComplexNumber z2(-3.0, 5.0);
	double im = 1.0;
	z1.setIm(im);

	// Act
	ComplexNumber res = z1*z2;
	double expected_re = -z2.getIm();
	double expected_im = z2.getRe();

	// Assert
	EXPECT_EQ(expected_re,res.getRe());
	EXPECT_EQ(expected_im, res.getIm());
}

TEST(Mironova_Anna_ComplexNumberTest, Difference_Between_Zero_and_Complex_is_Opposite_Number) {
	// Arrange
	ComplexNumber z1;
	ComplexNumber z2(-3.0, 5.0);

	// Act
	ComplexNumber res = z1-z2;
	ComplexNumber expected_res(3.0, -5.0);

	// Assert
	EXPECT_EQ(expected_res, res);
}

TEST(Mironova_Anna_ComplexNumberTest, Ñomplex_Ñonjugate_Numbers_Not_Equal) {
	// Arrange
	ComplexNumber z1(-1.1, 15.25);
	ComplexNumber z2(-1.1, -15.25);

	// Act & Assert
	EXPECT_TRUE(z1 != z2);
}

TEST(Mironova_Anna_ComplexNumberTest, Ñheck_Commutativity_Of_Addition) {
	// Arrange
	ComplexNumber z1(7.0, 14.0);
	ComplexNumber z2(4.0, -15.0);

	// Act
	ComplexNumber res1 = z1+z2;
	ComplexNumber res2 = z2+z1;

	// Assert
	EXPECT_TRUE(res1.getRe()==res2.getRe());
	EXPECT_TRUE(res1.getIm() == res2.getIm());
}

TEST(Mironova_Anna_ComplexNumberTest, Division_Purely_Imaginary_Complex_and_Ñonjugate_Complex_is_Minus_One) {
	// Arrange
	ComplexNumber z1(0.0, 5.0);
	ComplexNumber z2(0.0, -5.0);

	// Act
	ComplexNumber res = z1/z2;
	ComplexNumber expected_res(-1.0, 0.0);

	// Assert
	EXPECT_EQ(expected_res,res);
}

TEST(Mironova_Anna_ComplexNumberTest, Sum_Complex_and_Ñonjugate_Complex_is_Two_Real_Part) {
	// Arrange
	ComplexNumber z1(20.0, 5.0);
	ComplexNumber z2(20.0, -5.0);

	// Act
	ComplexNumber res = z1+z2;
	double expected_re=40.0;
	double expected_im = 0.0;

	// Assert
	EXPECT_EQ(expected_re, res.getRe());
	EXPECT_EQ(expected_im, res.getIm());
}
