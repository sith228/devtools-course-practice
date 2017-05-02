// Copyright 2017 Kulygina Julia

#include <gtest/gtest.h>
#include "include/three-dimensional-figures.h"

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_Copy_sphere) {
	// Arrange
    double r = 2.0;
    Sphere z(r);

    // Assert
    EXPECT_NO_THROW(Sphere z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_Create_getR) {
    // Arrange
    double r = 2.0;

    // Act
    Sphere z(r);

    // Assert
    EXPECT_EQ(2.0, z.getR());
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_Create_getS) {
    // Arrange
    Sphere z(1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Assert_Create_with_negative_radius) {
    // Arrange
    double r = -2.0;

    // Assert
    EXPECT_ANY_THROW(Sphere z(r));
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_Create_sphere) {
    // Arrange
    double r = 2.0;

    // Assert
    EXPECT_NO_THROW(Sphere z(r));
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_setR) {
    // Arrang
    Sphere z(0.2);

    // Act
    z.setR(2.0);

    // Assert
    EXPECT_EQ(2.0, z.getR());
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Assert_setR_with_negative_R) {
    // Arrang
    Sphere z(0.2);

    // Assert
    EXPECT_ANY_THROW(z.setR(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_setS) {
    // Arrang
    Sphere z(0.2);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Assert_setS_with_negative_S) {
    // Arrang
    Sphere z(0.2);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_CalculateS) {
    // Arrang
    Sphere z(1.0);

    // Act
    double s = z.CalculateS();
    double s1 = 4 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Sphere_Can_CalculateS_2) {
    // Arrang
    Sphere z(1.5);

    // Act
    double s = z.CalculateS();
    double s1 = 4 * M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}
