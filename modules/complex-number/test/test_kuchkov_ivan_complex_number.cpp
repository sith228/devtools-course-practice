// Copyright 2017 Kuchkov Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kuchkov_Ivan_ComplexNumberTest, Can_Create_Zero) 
{
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}