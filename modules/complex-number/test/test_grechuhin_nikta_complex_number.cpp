// Copyright 2017 Grechuhin Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Grechuhin_Nikita_Complex_Number_Test, Can_Create_Complex_Number) {
    // Arrange
    double re = 10.1;
    double im = 3.196;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Grechuhin_Nikita_Complex_Number_Test, Can_Create_By_Copy) {
    // Arrange
    double re = 5.4;
    double im = 1.3;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber test_number(z);

    // Assert
    EXPECT_EQ(test_number, z);
}

TEST(Grechuhin_Nikita_Complex_Number_Test, Can_Set_Re_and_Im)
{
    // Arrange
    double re = 13.5;
    double im = 0.6;

    // Act
    ComplexNumber z;
    z.setRe(re);
    z.setIm(im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Grechuhin_Nikita_Complex_Number_Test, Equals_operator_is_correct)
{
    // Arrange
    double re = 1.2;
    double im = 2.1;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    bool is_correct = z1 == z2;

    // Assert
    EXPECT_EQ(true, is_correct);
}

TEST(Grechuhin_Nikita_Complex_Number_Test, Can_multiplication_numbers)
{
    // Arrange
    double re1 = 2.0;
    double im1 = 0.0;
    double re2 = 1.5;
    double im2 = 5.6;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber c;
    c = a*b;

    EXPECT_EQ(re1*re2, c.getRe());
    EXPECT_EQ(re1*im2, c.getIm());
}

TEST(Grechuhin_Nikita_Complex_Number_Test, Can_summerize_numbers)
{
    // Arrange
    double re1 = 2.0;
    double im1 = 0.0;
    double re2 = 1.5;
    double im2 = 5.6;

    // Act
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);
    ComplexNumber c;
    c = a + b;

    EXPECT_EQ(re1 + re2, c.getRe());
    EXPECT_EQ(im1 + im2, c.getIm());
}
