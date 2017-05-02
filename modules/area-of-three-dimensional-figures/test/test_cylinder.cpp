// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/three-dimensional-figures.h"

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_Copy_Cylinder) {
    // Arrange
    double r = 2.0;
    double l = 1.0;
    Cylinder z(r, l);

    // Assert
    EXPECT_NO_THROW(Cylinder z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_Create_getr) {
    // Arrange
    double r = 2.0;
	double l = 1.0;

    // Act
    Cylinder z(r, l);

    // Assert
    EXPECT_EQ(2.0, z.getr());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_Create_getl) {
    // Arrange
    double r = 2.0;
    double l = 1.0;

    // Act
    Cylinder z(r, l);

    // Assert
    EXPECT_EQ(1.0, z.getl());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_Create_getS) {
    // Arrange
    Cylinder z(1.0, 1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Assert_Create_with_neg_rad) {
    // Arrange
    double r = -2.0;

    // Assert
    EXPECT_ANY_THROW(Cylinder z(r, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Assert_Create_with_neg_l) {
    // Arrange
    double l = -2.0;

    // Assert
    EXPECT_ANY_THROW(Cylinder z(1.0, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_Create_Cylinder) {
    // Arrange
    double r = 2.0;
	double l = 1.0;

    // Assert
    EXPECT_NO_THROW(Cylinder z(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_setr) {
    // Arrang
    Cylinder z(0.2, 0.1);

    // Act
    z.setr(2.0);

    // Assert
    EXPECT_EQ(2.0, z.getr());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Assert_setr_with_negative_r) {
    // Arrang
    Cylinder z(0.2, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setr(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_setS) {
    // Arrang
    Cylinder z(0.2, 0.1);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Assert_setS_with_negative_S) {
    // Arrang
    Cylinder z(0.2, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Assert_setl_with_negative_l) {
    // Arrang
    Cylinder z(0.2, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setl(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_setl) {
    // Arrang
    Cylinder z(0.2, 0.1);

    // Act
	z.setl(2.0);

    // Assert
	EXPECT_EQ(2.0, z.getl());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_CalculateS) {
    // Arrang
    Cylinder z(1.0, 1.0);

    // Act
    double s = z.CalculateS();
    double s1 = 2 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cylinder_Can_CalculateS_2) {
    // Arrang
    Cylinder z(1.5, 1.5);

    // Act
    double s = z.CalculateS();
    double s1 = 2 * M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}
