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
