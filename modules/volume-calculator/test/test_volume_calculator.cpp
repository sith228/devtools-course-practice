// Copyright 2017 Nazarov Aleksandr

#include <gtest/gtest.h>

#include "include/volume_calculator.h"

TEST(volume_test, can_get_right_cube_volume) {
    // Arrange
    double cube_rib = 25;
    // Act
    double right_cube_volume = cube_rib * cube_rib * cube_rib;
    // Assert
    EXPECT_EQ(Volume::Cube(cube_rib), right_cube_volume);
}

TEST(volume_test, cant_get_cube_volume_with_incorrect_rib) {
    // Arrange
    double cube_rib = -1;
    // Assert
    ASSERT_ANY_THROW(Volume::Cube(cube_rib));
}

TEST(volume_test, can_get_right_cone_volume) {
    // Arrange
    double cone_radius = 10, cone_height = 10;
    // Act
    double right_volume = (1 / 3)*M_PI*pow(cone_radius, 2)*cone_height;
    // Assert
    EXPECT_EQ(Volume::Cone(cone_height, cone_radius), right_volume);
}

TEST(volume_test, cant_get_cone_volume_with_uncorrect_variable) {
    // Arrange
    double uncorrect_number = -2;
    double correct_number = 10;
    // Assert
    ASSERT_ANY_THROW(Volume::Cone(uncorrect_number, correct_number));
    ASSERT_ANY_THROW(Volume::Cone(correct_number, uncorrect_number));
    ASSERT_ANY_THROW(Volume::Cone(uncorrect_number, uncorrect_number));
}

TEST(volume_test, can_get_right_cylinder_volume) {
    // Arrange
    double cylinder_radius = 10, cylinder_height = 10;
    // Act
    double right_volume = M_PI*pow(cylinder_radius, 2)*cylinder_height;
    // Assert
    EXPECT_EQ(Volume::Cylinder(cylinder_height, cylinder_radius), right_volume);
}

TEST(volume_test, cant_get_cylinder_volume_with_uncorrect_variable) {
    // Arrange
    double wrong_number = -2;
    double right_number = 10;
    // Assert
    ASSERT_ANY_THROW(Volume::Cylinder(wrong_number, right_number));
    ASSERT_ANY_THROW(Volume::Cylinder(right_number, wrong_number));
    ASSERT_ANY_THROW(Volume::Cylinder(wrong_number, wrong_number));
}

TEST(volume_test, can_get_right_dodecahedron_volume) {
    // Arrange
    double dodecahedron_rib = 10;
    // Act
    double right_volume = (pow(dodecahedron_rib, 3)*(15 + 7 * sqrt(5))) / 4;
    // Assert
    EXPECT_EQ(Volume::Dodecahedron(dodecahedron_rib), right_volume);
}

TEST(volume_test, cant_get_dodecahedron_volume_with_uncorrect_rib) {
    // Arrange
    double dodecahedron_rib = -10;
    // Assert
    ASSERT_ANY_THROW(Volume::Dodecahedron(dodecahedron_rib));
}

TEST(volume_test, can_get_right_ellipsoid_volume) {
    // Arrange
    double a = 4, b = 4, c = 4;
    // Act
    double right_volume = (4 / 3) * M_PI * a * b * c;
    // Assert
    EXPECT_EQ(Volume::Ellipsoid(a, b, c), right_volume);
}

TEST(volume_test, cant_get_ellipsoid_volume_with_uncorrect_ribs) {
    // Arrange
    double c_rib = 10;
    double unc_rib = -10;
    // Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(unc_rib, c_rib, c_rib));
    ASSERT_ANY_THROW(Volume::Ellipsoid(c_rib, unc_rib, c_rib));
    ASSERT_ANY_THROW(Volume::Ellipsoid(c_rib, c_rib, unc_rib));
    ASSERT_ANY_THROW(Volume::Ellipsoid(unc_rib, unc_rib, c_rib));
    ASSERT_ANY_THROW(Volume::Ellipsoid(c_rib, unc_rib, unc_rib));
    ASSERT_ANY_THROW(Volume::Ellipsoid(unc_rib, c_rib, unc_rib));
    ASSERT_ANY_THROW(Volume::Ellipsoid(unc_rib, unc_rib, unc_rib));
}

TEST(volume_test, can_get_right_frustum_volume) {
    // Arrange
    double radius_of_first_base = 10;
    double radius_of_second_base = 5;
    double height = 15;
    // Act
    double right_volume = (1 / 3)*M_PI*height*(pow(radius_of_first_base, 2)
        + radius_of_first_base*radius_of_second_base
        + pow(radius_of_second_base, 2));
    // Assert
    EXPECT_EQ(Volume::Frustum(radius_of_first_base,
        radius_of_second_base,
        height),
        right_volume);
}

TEST(volume_test, cant_get_frustum_volume_with_uncorrect_radius_and_height) {
    // Arrange
    double c_num = 10;
    double un_num = -10;
    // Assert
    ASSERT_ANY_THROW(Volume::Frustum(un_num, c_num, c_num));
    ASSERT_ANY_THROW(Volume::Frustum(c_num, un_num, c_num));
    ASSERT_ANY_THROW(Volume::Frustum(c_num, c_num, un_num));
    ASSERT_ANY_THROW(Volume::Frustum(un_num, un_num, c_num));
    ASSERT_ANY_THROW(Volume::Frustum(c_num, un_num, un_num));
    ASSERT_ANY_THROW(Volume::Frustum(un_num, c_num, un_num));
    ASSERT_ANY_THROW(Volume::Frustum(un_num, un_num, un_num));
}

TEST(volume_test, can_get_right_paraboloid_volume) {
    // Arrange
    double radius = 10, height = 5;
    // Act
    double right_value = (1 / 2)*M_PI*pow(radius, 2)*height;
    // Assert
    EXPECT_EQ(Volume::Paraboloid(height, radius), right_value);
}

TEST(volume_test, cant_get_paraboloid_volume_with_uncorrect_radius_and_height) {
    // Arrange
    double correct_number = 10;
    double uncorrect_number = -10;
    // Assert
    ASSERT_ANY_THROW(Volume::Paraboloid(uncorrect_number, correct_number));
    ASSERT_ANY_THROW(Volume::Paraboloid(correct_number, uncorrect_number));
    ASSERT_ANY_THROW(Volume::Paraboloid(uncorrect_number, uncorrect_number));
}

TEST(volume_test, can_get_right_parallelepiped_volume_with_base_area_and_h) {
    // Arrange
    double a_base_rib = 5, b_base_rib = 10, height = 20;
    double base_area = a_base_rib * b_base_rib;
    // Act
    double right_volume = base_area * height;
    // Assert
    EXPECT_EQ(Volume::Parallelepiped(a_base_rib, b_base_rib, height), 
        right_volume);
    EXPECT_EQ(Volume::Parallelepiped(base_area, height), right_volume);
}

TEST(volume_test, cant_get_parallelepiped_volume_with_uncorrect_variables) {
    // Arrange
    double un_num = -10;
    double c_num = 10;
    // Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(un_num, c_num, c_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, un_num, c_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, c_num, un_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(un_num, un_num, c_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, un_num, un_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(un_num, c_num, un_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(un_num, un_num, un_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(un_num, c_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, un_num));
    ASSERT_ANY_THROW(Volume::Parallelepiped(un_num, un_num));
}

TEST(volume_test, can_get_right_parallelepiped_volume_with_ribs_and_angle) {
    // Arrange
    double a = 5, b = 10, c = 15;
    double argument_of_sin = M_PI/4;
    // Act
    double right_volume = a*b*c*sin(argument_of_sin);
    // Assert
    EXPECT_EQ(Volume::Parallelepiped(a, b, c, argument_of_sin), right_volume);
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_uncorrect_var) {
    // Arrange
    double un_rib = -10, un_sin = -M_PI / 4;
    double c_rib = 10, c_sin = M_PI / 4;
    // Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(un_rib, un_rib, un_rib, c_sin));
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, c_rib, c_rib, un_sin));
}

TEST(volume_test, can_get_right_pyramid_volume) {
    // Arrange
    double a_base_rib_of_base_triangle = 5;
    double height_of_base_triangle = 10;
    double height_of_pyramid = 20;
    double base_area = ((double)1 / 2) *
        a_base_rib_of_base_triangle * height_of_base_triangle;
    // Act
    double right_volume = (1 / 3)*base_area*height_of_pyramid;
    // Assert
    EXPECT_EQ(Volume::Pyramid(a_base_rib_of_base_triangle, 
                              height_of_base_triangle, 
                              height_of_pyramid), right_volume);
    EXPECT_EQ(Volume::Pyramid(base_area, height_of_pyramid), right_volume);
}

TEST(volume_test, cant_get_pyramid_volume_with_uncorrect_rib_and_height) {
    // Arrange
    double un_num = -10;
    // Assert
    ASSERT_ANY_THROW(Volume::Pyramid(un_num, un_num, un_num));
    ASSERT_ANY_THROW(Volume::Pyramid(un_num, un_num));
}

TEST(volume_test, can_get_right_rectangular_parallelepiped_volume) {
    // Arrange
    double a = 4, b = 6, c = 10;
    // Act
    double right_volume = a * b * c;
    // Assert
    EXPECT_EQ(Volume::RectangularParallelepiped(a, b, c), right_volume);
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_uncorrect_ribs) {
    // Arrange
    double c_rib = 10;
    double un_rib = -10;
    // Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(un_rib, c_rib, c_rib));
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(c_rib, un_rib, c_rib));
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(c_rib, c_rib, un_rib));
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(un_rib, un_rib, c_rib));
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(c_rib, un_rib, un_rib));
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(un_rib, c_rib, un_rib));
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(un_rib, un_rib, un_rib));
}

TEST(volume_test, can_get_right_sphere_volume) {
    // Arrange
    double radius = 10;
    // Act
    double right_volume = (4 / 3)*M_PI*pow(radius, 3);
    // Assert
    EXPECT_EQ(Volume::Sphere(radius), right_volume);
}

TEST(volume_test, cant_get_sphere_volume_with_uncorrect_radius) {
    // Arrange
    double radius = -100;
    // Assert
    ASSERT_ANY_THROW(Volume::Sphere(radius));
}
