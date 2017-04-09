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
