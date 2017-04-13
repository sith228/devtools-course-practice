//Copyright 2017 Bakalin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bakalin_Andrey_ComplexNumberTest, Can_Get_Real) {
    // Arrange
    double re = 1.0, im = 2.0, re_expected;
    ComplexNumber z(re, im);
	
    // Act
    re_expected = z.getRe();

    // Assert
    EXPECT_EQ(re, re_expected);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Can_Get_Imaginary) {
    // Arrange
    double re = 1.0, im = 2.0, im_expected;
    ComplexNumber z(re, im);

    // Act
    im_expected = z.getIm();

    // Assert
    EXPECT_EQ(im, im_expected);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Additive_Commutativity_Works_With_Complex_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0), z3, z4;

    // Act
    z3 = z1 + z2;
    z4 = z2 + z1;

    // Assert
    EXPECT_EQ(z3, z4);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Additive_Associativity_Works_With_Complex_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0), z3(7.0, 8.0), z4, z5;

    // Act
    z4 = (z1 + z2) + z3;
    z5 = z1 + (z2 + z3);

    // Assert
    EXPECT_EQ(z4, z5);
}

TEST(Bakalin_Andrey_ComplexNumberTest, Left_Distributivity_Works_With_Complex_Numbers) {
    // Arrange
    ComplexNumber z1(1.0, 2.0), z2(3.0, 4.0), z3(7.0, 8.0), z4, z5;

    // Act 
    z4 = z1 * (z2 + z3);
    z5 = z1 * z2 + z1 * z3;

    // Assert
    EXPECT_EQ(z4, z5);
}
