// Copyright 2017 Vinogradova Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Commutativity_Of_Addition) {
    // Arrange
	ComplexNumber z1(10.0, 15.0);
	ComplexNumber z2(14.0, 20.0);

    // Act & Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Commutativity_Of_Multiplication) {
	// Arrange
	ComplexNumber z1(10.0, 15.0);
	ComplexNumber z2(14.0, 20.0);

	// Act & Assert
	EXPECT_EQ(z1 * z2, z2 * z1);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Associativity_Of_Addition) {
	// Arrange
	ComplexNumber z1(15.0, 10.0);
	ComplexNumber z2(14.0, 20.0);
	ComplexNumber z3(8.0, 11.0);

	// Act
	ComplexNumber left_z = (z1 + z2) + z3;
	ComplexNumber right_z = z1 + (z2 + z3);

	// Assert
	EXPECT_EQ(left_z, right_z);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Associativity_Of_Multiplication) {
	// Arrange
	ComplexNumber z1(15.0, 10.0);
	ComplexNumber z2(14.0, 20.0);
	ComplexNumber z3(8.0, 11.0);

	// Act
	ComplexNumber left_z = (z1 * z2) * z3;
	ComplexNumber right_z = z1 * (z2 * z3);

	// Assert
	EXPECT_EQ(left_z, right_z);
}

TEST(Vinogradova_Ekaterina_ComplexNumberTest, Distributivity) {
	// Arrange
	ComplexNumber z1(15.0, 10.0);
	ComplexNumber z2(14.0, 20.0);
	ComplexNumber z3(8.0, 11.0);

	// Act
	ComplexNumber left_z = z1 * (z2 + z3);
	ComplexNumber right_z = z1 * z2 + z1 * z3;

	// Assert
	EXPECT_EQ(left_z, right_z);
}