// Copyright 2017 Pletnev Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pletnev_Nikita_ComplexNumberTest, Divide_Zero_By_A_Complex) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z = z1 / z2;

    // Assert
    EXPECT_EQ(z1, z);
}

TEST(Pletnev_Nikita_ComplexNumberTest, Subtract_A_Number_From_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    ComplexNumber expected_z(-1.0, -1.0);
    EXPECT_EQ(expected_z, z);
}