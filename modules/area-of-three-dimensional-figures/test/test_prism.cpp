// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/three-dimensional-figures.h"

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_Copy_Prism) {
    // Arrange
    double a = 2.0;
	double b = 3.0;
    double c = 1.0;
	double h = 5.0;
    Prism z(a, b, c, h);

    // Assert
    EXPECT_NO_THROW(Prism z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_Create_get_a) {
    // Arrange
	double a = 2.0;
	double b = 3.0;
	double c = 1.0;
	double h = 5.0;

    // Act
	Prism z(a, b, c, h);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_Create_get_b) {
	// Arrange
	double a = 2.0;
	double b = 3.0;
	double c = 1.0;
	double h = 5.0;

	// Act
	Prism z(a, b, c, h);

	// Assert
	EXPECT_EQ(3.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_Create_get_c) {
    // Arrange
	double a = 2.0;
	double b = 3.0;
	double c = 1.0;
	double h = 5.0;

	// Act
	Prism z(a, b, c, h);

    // Assert
    EXPECT_EQ(1.0, z.get_c());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_Create_get_h) {
	// Arrange
	double a = 2.0;
	double b = 3.0;
	double c = 1.0;
	double h = 5.0;

	// Act
	Prism z(a, b, c, h);

	// Assert
	EXPECT_EQ(5.0, z.get_h());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_Create_getS) {
    // Arrange
    Prism z(1.0, 1.0, 1.0, 1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_Create_with_neg_a) {
    // Arrange
    double a = -2.0;

    // Assert
    EXPECT_ANY_THROW(Prism z(a, 0, 1.0, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_Create_with_neg_b) {
	// Arrange
	double b = -2.0;

	// Assert
	EXPECT_ANY_THROW(Prism z(0, b, 1.0, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_Create_with_neg_c) {
    // Arrange
    double c = -2.0;

    // Assert
    EXPECT_ANY_THROW(Prism z(1.0, 0.2, c, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_Create_with_neg_h) {
	// Arrange
	double h = -2.0;

	// Assert
	EXPECT_ANY_THROW(Prism z(1.0, 0.2, 1.0, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_Create_Prism) {
    // Arrange
    double a = 2.0;
	double b = 3.0;
	double c = 1.0;
	double h = 5.0;

    // Assert
    EXPECT_NO_THROW(Prism z(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_set_a) {
    // Arrang
    Prism z(0.2, 0.3, 0.1, 0.5);

    // Act
    z.set_a(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_set_b) {
	// Arrang
	Prism z(0.2, 0.3, 0.1, 0.5);

	// Act
	z.set_b(2.0);

	// Assert
	EXPECT_EQ(2.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_setr_with_negative_a) {
    // Arrang
    Prism z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.set_a(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_setr_with_negative_b) {
	// Arrang
	Prism z(0.2, 0.3, 0.1, 0.5);

	// Assert
	EXPECT_ANY_THROW(z.set_b(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_setS) {
    // Arrang
    Prism z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_setS_with_negative_S) {
    // Arrang
    Prism z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_setl_with_negative_c) {
    // Arrang
    Prism z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.set_c(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Assert_setl_with_negative_h) {
	// Arrang
	Prism z(0.2, 0.3, 0.1, 0.5);

	// Assert
	EXPECT_ANY_THROW(z.set_h(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_set_c) {
    // Arrang
    Prism z(0.2, 0.3, 0.1, 0.5);

    // Act
	z.set_c(2.0);

    // Assert
	EXPECT_EQ(2.0, z.get_c());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_set_h) {
	// Arrang
	Prism z(0.2, 0.3, 0.1, 0.5);

	// Act
	z.set_h(2.0);

	// Assert
	EXPECT_EQ(2.0, z.get_h());
}

TEST(AreaOfThreeDimensionalFiguresTest, Prism_Can_CalculateS) {
    // Arrang
    Prism z(1.0, 1.0, 1.0, 1);

    // Act
    double s = z.CalculateS();
    double s1 = 3 + sqrt(3)/2;

    // Assert
    EXPECT_EQ(s1, s);
}
