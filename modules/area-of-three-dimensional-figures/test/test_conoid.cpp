// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/conoid.h"

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_Copy_Conoid) {
    // Arrange
    double r1 = 2.0;
    double r2 = 3.0;
    double l = 1.0;
    Conoid z(r1, r2, l);

    // Assert
    EXPECT_NO_THROW(Conoid z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_Copy_Conoid_bool) {
    // Arrange
    double r1 = 2.0;
    double r2 = 3.0;
    double l = 1.0;
    Conoid z(r1, r2, l);

    // Act
    Conoid z2(z);

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_comparation_Conoid) {
    // Arrange
    double r1 = 2.0;
    double r2 = 3.0;
    double l = 1.0;
    Conoid z(r1, r2, l);

    // Act
    Conoid z2(3.0, 1.0, 1.0);

    // Assert
    EXPECT_TRUE(z != z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Is_Equal_To_Itself) {
    // Arrange
    Conoid z(26.0, 14.0, 5.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_getr1) {
    // Arrange
    double r1 = 2.0;
    double r2 = 3.0;
    double l = 1.0;

    // Act
    Conoid z(r1, r2, l);

    // Assert
    EXPECT_EQ(2.0, z.getr1());
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_getr2) {
    // Arrange
    double r1 = 2.0;
    double r2 = 3.0;
    double l = 1.0;

    // Act
    Conoid z(r1, r2, l);

    // Assert
    EXPECT_EQ(3.0, z.getr2());
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_getl) {
    // Arrange
    double r1 = 2.0;
    double r2 = 3.0;
    double l = 1.0;

    // Act
    Conoid z(r1, r2, l);

    // Assert
    EXPECT_EQ(1.0, z.getl());
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_getS) {
    // Arrange
    Conoid z(1.0, 1.0, 1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Assert_Create_with_neg_r1) {
    // Arrange
    double r1 = -2.0;

    // Assert
    EXPECT_ANY_THROW(Conoid z(r1, 0, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Assert_Create_with_neg_r2) {
    // Arrange
    double r2 = -2.0;

    // Assert
    EXPECT_ANY_THROW(Conoid z(0, r2, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Assert_Create_with_neg_l) {
    // Arrange
    double l = -2.0;

    // Assert
    EXPECT_ANY_THROW(Conoid z(1.0, 0.2, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_Create_Conoid) {
    // Arrange
    double r1 = 2.0;
    double r2 = 3.0;
    double l = 1.0;

    // Assert
    EXPECT_NO_THROW(Conoid z(r1, r2, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_setr1) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Act
    z.setr1(2.0);

    // Assert
    EXPECT_EQ(2.0, z.getr1());
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_setr2) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Act
    z.setr2(2.0);

    // Assert
    EXPECT_EQ(2.0, z.getr2());
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Assert_setr_with_negative_r1) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setr1(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Assert_setr_with_negative_r2) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setr2(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_setS) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Assert_setS_with_negative_S) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Assert_setl_with_negative_l) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setl(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_setl) {
    // Arrang
    Conoid z(0.2, 0.3, 0.1);

    // Act
    z.setl(2.0);

    // Assert
    EXPECT_EQ(2.0, z.getl());
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_CalculateS) {
    // Arrang
    Conoid z(1.0, 1.0, 1.0);

    // Act
    double s = z.CalculateS();
    double s1 = 2 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Conoid_Can_CalculateS_2) {
    // Arrang
    Conoid z(1.5, 1.5, 1.5);

    // Act
    double s = z.CalculateS();
    double s1 = M_PI * 3 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}
