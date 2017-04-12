// Copyright 2017 Buldakov Vladislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Create_Default) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
	ComplexNumber z = ComplexNumber();

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Buldakov_Vladislav_ComplexNumberTest, Can_Sum) {
    // Arrange
    double re = 1.0;
    double im = 2.0;
    ComplexNumber z(re, im);
	ComplexNumber neg_z(-re, -im);

    // Act
	ComplexNumber resut = z + neg_z;

    // Assert
	EXPECT_EQ(0.0, resut.getRe());
	EXPECT_EQ(0.0, resut.getIm());
}



