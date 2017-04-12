// Copyright 2017 Kildishev Maxim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kildishev_Maxim_ComplexNumberTest, Can_Create_Zero) {
	// Arrange
	double re = 0.0;
	double im = 0.0;

	// Act
	ComplexNumber z(re, im);

	// Assert
	EXPECT_EQ(re, z.getRe());
	EXPECT_EQ(im, z.getIm());
}

TEST(Kildishev_Maxim_ComplexNumberTest, Cant_division_by_zero) {
	ComplexNumber z(1.0, 1.0);
	ComplexNumber zero(0.0, 0.0);
	ASSERT_ANY_THROW(z = z / zero);
}

TEST(Kildishev_Maxim_ComplexNumberTest, Sum_of_zeros_is_zero)
{
	ComplexNumber z(0.0, 0.0);
	ComplexNumber expected(0.0, 0.0);
	EXPECT_EQ(expected, z = z + z);
}

TEST(Kildishev_Maxim_ComplexNumberTest, Multyply_by_zero_is_zero)
{
	ComplexNumber z(1.1, 1.1);
	ComplexNumber expected(0.0, 0.0);
	EXPECT_EQ(expected, z = z * expected);
}

TEST(Kildishev_Maxim_ComplexNumberTest, Copy_is_equal_orig)
{
	ComplexNumber z(1.1, 1.1);
	ComplexNumber z1(z);
	EXPECT_EQ(z, z1);
}

TEST(Kildishev_Maxim_ComplexNumberTest, Sum_works)
{
	ComplexNumber z(1.0, 1.0);
	ComplexNumber z1(2.0, 2.1);
	ComplexNumber z2 = z + z1;
	ComplexNumber res(3, 3.1);
	EXPECT_EQ(res, z2);
}