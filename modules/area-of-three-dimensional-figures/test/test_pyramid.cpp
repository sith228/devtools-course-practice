// Copyright 2017 Kulygina Julia

#include <gtest/gtest.h>
#include "include/three-dimensional-figures.h"

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_Copy_Pyramid) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double l = 1.0;
    Pyramid z(a, b, l);

    // Assert
    EXPECT_NO_THROW(Pyramid z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_Copy_Pyramid_bool) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double l = 5.0;
    Pyramid z(a, b, l);

    //Act
    Pyramid z2(z);

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_comparation_Pyramid) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double l = 1.0;
    Pyramid z(a, b, l);

    //Act
    Pyramid z2(3.0, 1.0, 1.0);

    // Assert
    EXPECT_TRUE(z != z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Is_Equal_To_Itself) {
    // Arrange
    Pyramid z(26.0, 14.0, 5.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_Create_get_a) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double l = 1.0;

    // Act
    Pyramid z(a, b, l);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_Create_get_b) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double l = 1.0;

    // Act
    Pyramid z(a, b, l);

    // Assert
    EXPECT_EQ(3.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_Create_get_l) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double l = 1.0;

    // Act
    Pyramid z(a, b, l);

    // Assert
    EXPECT_EQ(1.0, z.get_l());
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_Create_getS) {
    // Arrange
    Pyramid z(1.0, 1.0, 1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Assert_Create_with_neg_a) {
    // Arrange
    double a = -2.0;

    // Assert
    EXPECT_ANY_THROW(Pyramid z(a, 0, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Assert_Create_with_neg_b) {
    // Arrange
    double b = -2.0;

    // Assert
    EXPECT_ANY_THROW(Pyramid z(0, b, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Assert_Create_with_neg_l) {
    // Arrange
    double l = -2.0;

    // Assert
    EXPECT_ANY_THROW(Pyramid z(1.0, 0.2, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_Create_Pyramid) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double l = 1.0;

    // Assert
    EXPECT_NO_THROW(Pyramid z(a, b, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_set_a) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Act
    z.set_a(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_set_b) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Act
    z.set_b(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Assert_setr_with_negative_a) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.set_a(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Assert_setr_with_negative_b) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.set_b(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_setS) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Assert_setS_with_negative_S) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}
TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Assert_setl_with_negative_l) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Assert
    EXPECT_ANY_THROW(z.set_l(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_set_l) {
    // Arrang
    Pyramid z(0.2, 0.3, 0.1);

    // Act
    z.set_l(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_l());
}

TEST(AreaOfThreeDimensionalFiguresTest, Pyramid_Can_CalculateS) {
    // Arrang
    Pyramid z(1.0, 1.0, 1.0);

    // Act
    double s = z.CalculateS();
    double s1 = 1.0 + sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}
