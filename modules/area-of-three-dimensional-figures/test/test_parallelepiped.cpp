// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/parallelepiped.h"

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_Copy) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    Parallelepiped z(a, b, c);

    // Assert
    EXPECT_NO_THROW(Parallelepiped z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_t1) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    Parallelepiped z(a, b, c);

    // Act
    Parallelepiped z2(z);

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_comparation) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    Parallelepiped z(a, b, c);

    // Act
    Parallelepiped z2(3.0, 1.0, 1.0);

    // Assert
    EXPECT_TRUE(z != z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Is_Equal_To_Itself) {
    // Arrange
    Parallelepiped z(26.0, 14.0, 5.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_Create_get_a) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;

    // Act
    Parallelepiped z(a, b, c);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_Create_get_b) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;

    // Act
    Parallelepiped z(a, b, c);

    // Assert
    EXPECT_EQ(3.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_Create_get_c) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;

    // Act
    Parallelepiped z(a, b, c);

    // Assert
    EXPECT_EQ(1.0, z.get_c());
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_Create_getS) {
    // Arrange
    Parallelepiped z(1.0, 1.0, 1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Assert_1) {
    // Arrange
    double a = -2.0;

    // Assert
    EXPECT_ANY_THROW(Parallelepiped z(a, 0, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Assert_2) {
    // Arrange
    double b = -2.0;

    // Assert
    EXPECT_ANY_THROW(Parallelepiped z(0, b, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Assert_3) {
    // Arrange
    double c = -2.0;

    // Assert
    EXPECT_ANY_THROW(Parallelepiped z(1.0, 0.2, c));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_Create) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;

    // Assert
    EXPECT_NO_THROW(Parallelepiped z(a, b, c));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_set_a) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Act
    z.set_a(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_set_b) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Act
    z.set_b(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Assert_setr_1) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.set_a(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Assert_setr_2) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.set_b(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_setS_1) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Assert_setS_2) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Assert_setl) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.set_c(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_set_c) {
    // Arrang
    Parallelepiped z(0.2, 0.3, 0.1);

    // Act
    z.set_c(2.0);

    // Assert
    EXPECT_EQ(z.get_c(), 2.0);
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_CalculateS) {
    // Arrang
    Parallelepiped z(1.0, 1.0, 1.0);

    // Act
    double s = z.CalculateS();
    double s1 = 6.0;

    // Assert
    EXPECT_EQ(s, s1);
}

TEST(AreaOfThreeDimensionalFiguresTest, Parallelepiped_Can_CalculateS_2) {
    // Arrang
    Parallelepiped z(1.5, 1.5, 1.5);

    // Act
    double s = z.CalculateS();
    double s1 = 3 * 2 * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}
