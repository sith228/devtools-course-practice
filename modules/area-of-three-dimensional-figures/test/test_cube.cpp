// Copyright 2017 Kulygina Julia

#include <gtest/gtest.h>
#include "include/cube.h"

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_Copy_cube) {
    // Arrange
    double r = 2.0;
    Cube z(r);

    // Assert
    EXPECT_NO_THROW(Cube z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_Copy_Cube_bool) {
    // Arrange
    double h = 2.0;
    Cube z(h);

    // Act
    Cube z2(z);

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_comparation_Cube) {
    // Arrange
    double h = 2.0;
    Cube z(h);

    // Act
    Cube z2(3.0);

    // Assert
    EXPECT_TRUE(z != z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Is_Equal_To_Itself) {
    // Arrange
    Cube z(26.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_Create_getR) {
    // Arrange
    double r = 2.0;

    // Act
    Cube z(r);

    // Assert
    EXPECT_EQ(2.0, z.geth());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_Create_getS) {
    // Arrange
    Cube z(1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Assert_Create_with_neg_rad) {
    // Arrange
    double r = -2.0;

    // Assert
    EXPECT_ANY_THROW(Cube z(r));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_Create_Cube) {
    // Arrange
    double r = 2.0;

    // Assert
    EXPECT_NO_THROW(Cube z(r));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_setR) {
    // Arrang
    Cube z(0.2);

    // Act
    z.seth(2.0);

    // Assert
    EXPECT_EQ(2.0, z.geth());
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Assert_setR_with_negative_R) {
    // Arrang
    Cube z(0.2);

    // Assert
    EXPECT_ANY_THROW(z.seth(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_setS) {
    // Arrang
    Cube z(0.2);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Assert_setS_with_negative_S) {
    // Arrang
    Cube z(0.2);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_CalculateS) {
    // Arrang
    Cube z(1.0);

    // Act
    double s = z.CalculateS();
    double s1 = 6;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Cube_Can_CalculateS_2) {
    // Arrang
    Cube z(1.5);

    // Act
    double s = z.CalculateS();
    double s1 = 6 * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}
