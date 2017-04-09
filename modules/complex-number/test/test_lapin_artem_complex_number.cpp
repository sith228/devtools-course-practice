// Copyright 2017 Lapin Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Lapin_Artem_ComplexNumberTest, Can_Create_With_Negative_Real) {
    // Arrange
    double re = -20.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe(), ComplexNumberTest::epsilon);
    EXPECT_EQ(im, z.getIm(), ComplexNumberTest::epsilon);
}

TEST(Lapin_Artem_ComplexNumberTest, Can_Create_With_Negative_Imaginary) {
    // Arrange
    double re = 20.0;
    double im = -20.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe(), ComplexNumberTest::epsilon);
    EXPECT_EQ(im, z.getIm(), ComplexNumberTest::epsilon);
}

TEST(Lapin_Artem_ComplexNumberTest, Zero_Number_Is_Equal_To_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, 0, ComplexNumberTest::epsilon);
    EXPECT_EQ(im, 0, ComplexNumberTest::epsilon);
}