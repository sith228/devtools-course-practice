// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/calculator.h"

TEST(AreaOfThreeDimensionalFiguresTest, Can_assert_calc_cone) {
    // Arrange
    double r = -2.0;
    double l = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cone(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Can_assert_calc_cone_2) {
    // Arrange
    double r = 2.0;
    double l = -1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cone(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Can_assert_calc_cone_3) {
    // Arrange
    double r = 2.0;
    double l = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cone(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_cone) {
    // Arrang
    Calculator z;
    
    // Act
    double s = z.Calculate_Cone(1.0, 1.0);
    double s1 = M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_cone_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cone(1.5, 1.5);
    double s1 = M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}


TEST(AreaOfThreeDimensionalFiguresTest, Calc_conoid) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Conoid(1.0, 1.0, 1.0);
    double s1 = 2 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_conoid_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Conoid(1.5, 1.5, 1.5);
    double s1 = M_PI * 3 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_cube) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cube(1.0);
    double s1 = 6.0;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_cube_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cube(1.5);
    double s1 = 6 * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_cylinder) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cylinder(1.0, 1.0);
    double s1 = 2 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_cylinder_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cylinder(1.5, 1.5);
    double s1 = 2 * M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_parallelepiped) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Parallelepiped(1.0, 1.0, 1.0);
    double s1 = 6.0;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_parallelepiped_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Parallelepiped(1.5, 1.5, 1.5);
    double s1 = 3 * 2 * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_prism) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Prism(1.0, 1.0, 1.0, 1.0);
    double s1 = 3 + sqrt(3) / 2;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_prism_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Prism(2.0, 2.0, 2.0, 1.5);
    double s1 = 2 * 1.5 * 3 + 2 * sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_pyramid) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Pyramid(1.0, 1.0, 1.0);
    double s1 = 1.0 + sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_pyramid_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Pyramid(2.0, 2.0, 1.5);
    double s1 = 4 + 2 * sqrt(5);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_sphere) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Sphere(1.0);
    double s1 = 4 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_sphere_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Sphere(1.5);
    double s1 = 4 * M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_tetrahedron) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Tetrahedron(1.0, 1.0, 1.0, 1.0);
    double s1 = sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_tetrahedron_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Tetrahedron(2.0, 3.0, 4.0, 5.0);
    double heron_abc = sqrt(4.5* 2.5* 1.5 *0.5);
    double heron_al = sqrt(6 * 4);
    double heron_bl = sqrt(6.5 * 3.5 * 1.5 * 1.5);
    double heron_cl = sqrt(7 * 3 * 4);

    double s1 = heron_abc + heron_al + heron_bl + heron_cl;

    // Assert
    EXPECT_EQ(s1, s);
}
