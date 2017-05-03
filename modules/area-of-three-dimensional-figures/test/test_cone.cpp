// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/three-dimensional-figures.h"

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_Copy_Cone) {
    // Arrange
    double r = 2.0;
    double l = 1.0;
    Cone z(r, l);

    // Assert
    EXPECT_NO_THROW(Cone z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_Copy_Cone_bool) {
    // Arrange
    double r = 2.0;
    double l = 1.0;
    Cone z(r, l);

    //Act
    Cone z2(z);

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_comparation_Cone) {
    // Arrange
    double r = 2.0;
    double l = 1.0;
    Cone z(r, l);

    //Act
    Cone z2(3.0, 1.0);

    // Assert
    EXPECT_TRUE(z != z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Is_Equal_To_Itself) {
    // Arrange
    Cone z(26.0, 14.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_Create_getr) {
    // Arrange
    double r = 2.0;
    double l = 1.0;

    // Act
    Cone z(r, l);

    // Assert
    EXPECT_EQ(2.0, z.getr());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_Create_getl) {
    // Arrange
    double r = 2.0;
    double l = 1.0;

    // Act
    Cone z(r, l);

    // Assert
    EXPECT_EQ(1.0, z.getl());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_Create_getS) {
    // Arrange
    Cone z(1.0, 1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Assert_Create_with_neg_rad) {
    // Arrange
    double r = -2.0;

    // Assert
    EXPECT_ANY_THROW(Cone z(r, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Assert_Create_with_neg_l) {
    // Arrange
    double l = -2.0;

    // Assert
    EXPECT_ANY_THROW(Cone z(1.0, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_Create_Cone) {
    // Arrange
    double r = 2.0;
    double l = 1.0;

    // Assert
    EXPECT_NO_THROW(Cone z(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_setr) {
    // Arrang
    Cone z(0.2, 0.1);

    // Act
    z.setr(2.0);

    // Assert
    EXPECT_EQ(2.0, z.getr());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Assert_setr_with_negative_r) {
    // Arrang
    Cone z(0.2, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setr(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_setS) {
    // Arrang
    Cone z(0.2, 0.1);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Assert_setS_with_negative_S) {
    // Arrang
    Cone z(0.2, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Cone_Assert_setl_with_negative_l) {
    // Arrang
    Cone z(0.2, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setl(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_setl) {
    // Arrang
    Cone z(0.2, 0.1);

    // Act
    z.setl(2.0);

    // Assert
    EXPECT_EQ(2.0, z.getl());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_CalculateS) {
    // Arrang
    Cone z(1.0, 1.0);

    // Act
    double s = z.CalculateS();
    double s1 = M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cone_Can_CalculateS_2) {
    // Arrang
    Cone z(1.5, 1.5);

    // Act
    double s = z.CalculateS();
    double s1 = M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}
