// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/tetrahedron.h"

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Copy_Tetrahedron) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;
    Tetrahedron z(a, b, c, l);

    // Assert
    EXPECT_NO_THROW(Tetrahedron z2(z));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Copy_Tetrahedron_bool) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;
    Tetrahedron z(a, b, c, l);

    // Act
    Tetrahedron z2(z);

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_comparation) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;
    Tetrahedron z(a, b, c, l);

    // Act
    Tetrahedron z2(3.0, 1.0, 1.0, 2.0);

    // Assert
    EXPECT_TRUE(z != z2);
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Is_Equal_To_Itself) {
    // Arrange
    Tetrahedron z(26.0, 14.0, 5.0, 13.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Create_get_a) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;

    // Act
    Tetrahedron z(a, b, c, l);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Create_get_b) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;

    // Act
    Tetrahedron z(a, b, c, l);

    // Assert
    EXPECT_EQ(3.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Create_get_c) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;

    // Act
    Tetrahedron z(a, b, c, l);

    // Assert
    EXPECT_EQ(1.0, z.get_c());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Create_get_l) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;

    // Act
    Tetrahedron z(a, b, c, l);

    // Assert
    EXPECT_EQ(5.0, z.get_l());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Create_getS) {
    // Arrange
    Tetrahedron z(1.0, 1.0, 1.0, 1.0);

    // Act
    z.setS(3.0);

    // Assert
    EXPECT_EQ(3.0, z.getS());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_Create_with_neg_a) {
    // Arrange
    double a = -2.0;

    // Assert
    EXPECT_ANY_THROW(Tetrahedron z(a, 0, 1.0, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_Create_with_neg_b) {
    // Arrange
    double b = -2.0;

    // Assert
    EXPECT_ANY_THROW(Tetrahedron z(0, b, 1.0, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_Create_with_neg_c) {
    // Arrange
    double c = -2.0;

    // Assert
    EXPECT_ANY_THROW(Tetrahedron z(1.0, 0.2, c, 1.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_Create_with_neg_l) {
    // Arrange
    double l = -2.0;

    // Assert
    EXPECT_ANY_THROW(Tetrahedron z(1.0, 0.2, 1.0, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_Create_Tetrahedron) {
    // Arrange
    double a = 2.0;
    double b = 3.0;
    double c = 1.0;
    double l = 5.0;

    // Assert
    EXPECT_NO_THROW(Tetrahedron z(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_set_a) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Act
    z.set_a(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_a());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_set_b) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Act
    z.set_b(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_b());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_set_with_neg_a) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.set_a(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_set_with_neg_b) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.set_b(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_setS) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_NO_THROW(z.setS(2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_set_with_neg_S) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.setS(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_set_with_neg_c) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.set_c(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Assert_set_with_neg_l) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Assert
    EXPECT_ANY_THROW(z.set_l(-2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_set_c) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Act
    z.set_c(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_c());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_set_l) {
    // Arrang
    Tetrahedron z(0.2, 0.3, 0.1, 0.5);

    // Act
    z.set_l(2.0);

    // Assert
    EXPECT_EQ(2.0, z.get_l());
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_CalculateS) {
    // Arrang
    Tetrahedron z(1.0, 1.0, 1.0, 1);

    // Act
    double s = z.CalculateS();
    double s1 = sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Tetrahedron_Can_CalculateS_1) {
    // Arrang
    Tetrahedron z(2.0, 3.0, 4.0, 5.0);

    // Act
    double s = z.CalculateS();
    double heron_abc = sqrt(4.5* 2.5* 1.5 *0.5);
    double heron_al = sqrt(6* 4);
    double heron_bl = sqrt(6.5 * 3.5 * 1.5 * 1.5);
    double heron_cl = sqrt(7 * 3 * 4);

    double s1 = heron_abc + heron_al + heron_bl + heron_cl;

    // Assert
    EXPECT_EQ(s1, s);
}
