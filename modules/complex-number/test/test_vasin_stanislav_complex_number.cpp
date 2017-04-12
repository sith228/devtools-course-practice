// Copyright 2017 Vasin Stanislav

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Vasin_Stanislav_ComplexNumberTest, the_degree_of_the_imaginary_unit_1) {
    // Arrange
    ComplexNumber i(0.0, 1.0);
    ComplexNumber result(-1.0, 0.0);

    // Act
    ComplexNumber i_pow_2 = i * i;

    // Assert
    // i^2 = -1
	EXPECT_TRUE(result == i_pow_2);
}

TEST(Vasin_Stanislav_ComplexNumberTest, the_degree_of_the_imaginary_unit_2) {
    // Arrange
    ComplexNumber i(0.0, 1.0);
    ComplexNumber result(0.0, -1.0);

    // Act
    ComplexNumber i_pow_3 = i * i * i;

    // Assert
    // i^3 = -i
    EXPECT_TRUE(result == i_pow_3);
}

TEST(Vasin_Stanislav_ComplexNumberTest, the_degree_of_the_imaginary_unit_3) {
    // Arrange
    ComplexNumber i(0.0, 1.0);
    ComplexNumber result(1.0, 0.0);

    // Act
    ComplexNumber i_pow_4 = i * i * i * i;

    // Assert
    // i^4 = 1
    EXPECT_TRUE(result == i_pow_4);
}

TEST(Vasin_Stanislav_ComplexNumberTest, complex_conjugate_numbers) {
    // Arrange
    ComplexNumber A(2.3, 15.0);
    ComplexNumber B(2.3, -15.0);
    ComplexNumber real_number(2.3 * 2.3 + 15.0 * 15.0, 0.0);

    // Act
    ComplexNumber C = A * B;

    // Assert
    EXPECT_TRUE(real_number == C);
}

TEST(Vasin_Stanislav_ComplexNumberTest, error_add_small_and_large_numbers) {
    // Arrange
    ComplexNumber A(10000000000.0, 10000000000.0);
    ComplexNumber B(0.0000000001, 0.0000000001);

    // Act
    ComplexNumber C = A + B;

    // Assert
    EXPECT_TRUE(A == C);
}

TEST(Vasin_Stanislav_ComplexNumberTest, default_constructor_1) {
    // Arrange

    // Act
    ComplexNumber A;

    // Assert
    EXPECT_EQ(0.0, A.getRe());
}

TEST(Vasin_Stanislav_ComplexNumberTest, default_constructor_2) {
    // Arrange

    // Act
    ComplexNumber A;

    // Assert
    EXPECT_EQ(0.0, A.getIm());
}

TEST(Vasin_Stanislav_ComplexNumberTest, copy_constructor_1) {
    // Arrange
    ComplexNumber A(1.0, 23.1);

    // Act
    ComplexNumber B(A);

    // Assert
    EXPECT_EQ(A.getRe(), B.getRe());
}

TEST(Vasin_Stanislav_ComplexNumberTest, copy_constructor_2) {
    // Arrange
    ComplexNumber A(1.0, 23.1);

    // Act
    ComplexNumber B(A);

    // Assert
    EXPECT_EQ(A.getIm(), B.getIm());
}

TEST(Vasin_Stanislav_ComplexNumberTest, copy_constructor_3) {
    // Arrange
    ComplexNumber A(1.0, 23.1);

    // Act
    ComplexNumber B(A);

    // Assert
    EXPECT_FALSE(&A == &B);
}
