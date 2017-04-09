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