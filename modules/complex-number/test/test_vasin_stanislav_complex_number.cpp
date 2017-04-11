// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vasin_Stanislav_ComplexNumberTest, the_degree_of_the_imaginary_unit) {
	// Arrange
	ComplexNumber i(0.0, 1.0);

	// Act
	ComplexNumber i_pow_2 = i * i;
	ComplexNumber i_pow_3 = i * i * i;
	ComplexNumber i_pow_4 = i * i * i * i;

	// Assert

	// i = i
	EXPECT_EQ(0.0, i.getRe());
	EXPECT_EQ(1.0, i.getIm());

	// i^2 = -1
	EXPECT_EQ(-1.0, i_pow_2.getRe());
	EXPECT_EQ(0.0, i_pow_2.getIm());

	// i^3 = -i
	EXPECT_EQ(0.0, i_pow_3.getRe());
	EXPECT_EQ(-1.0, i_pow_3.getIm());

	// i^4 = 1
	EXPECT_EQ(1.0, i_pow_4.getRe());
	EXPECT_EQ(0.0, i_pow_4.getIm());
}
