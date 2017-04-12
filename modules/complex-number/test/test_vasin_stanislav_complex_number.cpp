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

TEST(Vasin_Stanislav_ComplexNumberTest, complex_conjugate_numbers) {
    // Arrange
    ComplexNumber A(2.3, 15.0);
    ComplexNumber B(2.3, -15.0);
    double real_number = 2.3 * 2.3 + 15.0 * 15.0;

    // Act
    ComplexNumber C = A * B;

    // Assert
    EXPECT_EQ(real_number, C.getRe());
    EXPECT_EQ(0.0, C.getIm());
}

TEST(Vasin_Stanislav_ComplexNumberTest, error_add_small_and_large_numbers) {
    // Arrange
    ComplexNumber A(10000000000.0, 10000000000.0);
    ComplexNumber B(0.0000000001, 0.0000000001);

    // Act
    ComplexNumber C = A + B;

    // Assert
    EXPECT_EQ(A.getRe(), C.getRe());
    EXPECT_EQ(A.getIm(), C.getIm());
}

TEST(Vasin_Stanislav_ComplexNumberTest, default_constructor) {
    // Arrange

    // Act
    ComplexNumber A;

    // Assert
    EXPECT_EQ(0.0, A.getRe());
    EXPECT_EQ(0.0, A.getIm());
}

TEST(Vasin_Stanislav_ComplexNumberTest, copy_constructor) {
    // Arrange
    ComplexNumber A(1.0, 23.1);

    // Act
    ComplexNumber B(A);

    // Assert
    EXPECT_EQ(A.getRe(), B.getRe());
    EXPECT_EQ(A.getIm(), B.getIm());
    EXPECT_FALSE(&A == &B);
}
