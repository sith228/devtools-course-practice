// Copyright 2017 Karev Boris

#include <gtest/gtest.h>

#include <string>

#include "include/triangle.h"

TEST(Triangle_test, Can_create_via_constructor) {
    double point1_coordx = 10.11;
    double point1_coordy = 10.11;
    double point2_coordx = 12.14;
    double point2_coordy = 12.14;
    double point3_coordx = 0;
    double point3_coordy = 5.31;

    Triangle t(point1_coordx, point1_coordy,
        point2_coordx, point2_coordy,
        point3_coordx, point3_coordy);

    EXPECT_EQ(point1_coordx, t.Get_coordX_point(1));
    EXPECT_EQ(point1_coordy, t.Get_coordY_point(1));
    EXPECT_EQ(point2_coordx, t.Get_coordX_point(2));
    EXPECT_EQ(point2_coordy, t.Get_coordY_point(2));
    EXPECT_EQ(point3_coordx, t.Get_coordX_point(3));
    EXPECT_EQ(point3_coordy, t.Get_coordY_point(3));
}

TEST(Triangle_test, Constructor_throw_exception) {
    double point1_coordx = 10.11;
    double point1_coordy = 10.11;
    double point2_coordx = 12.14;
    double point2_coordy = 12.14;
    double point3_coordx = 10.11;
    double point3_coordy = 10.11;

    EXPECT_THROW(Triangle t(point1_coordx, point1_coordy, point2_coordx,
        point2_coordy, point3_coordx, point3_coordy), std::string);
}

TEST(Triangle_test, Can_create_via_copying) {
    double point1_coordx = 10.11;
    double point1_coordy = 10.11;
    double point2_coordx = 12.14;
    double point2_coordy = 12.14;
    double point3_coordx = 0;
    double point3_coordy = 5.31;

    Triangle t(point1_coordx, point1_coordy, point2_coordx, point2_coordy,
        point3_coordx, point3_coordy);
    Triangle copy_t = t;

    EXPECT_EQ(copy_t, t);
}

TEST(Triangle_test, Can_create_via_copy_constructor) {
    double point1_coordx = 10.11;
    double point1_coordy = 10.11;
    double point2_coordx = 12.14;
    double point2_coordy = 12.14;
    double point3_coordx = 0;
    double point3_coordy = 5.31;

    Triangle t(point1_coordx, point1_coordy, point2_coordx, point2_coordy,
        point3_coordx, point3_coordy);
    Triangle copy_t(t);

    EXPECT_EQ(copy_t, t);
}

TEST(Triangle_test, Can_create_via_default_constructor) {
    Triangle t1;
    Triangle t2(0, 0, 0, 1, 1, 0);

    EXPECT_EQ(t1, t2);
}

TEST(Triangle_test, Can_calculate_square) {
    Triangle t;

    double sq = t.Calculate_square();

    EXPECT_NEAR(0.5, sq, 0.001);
}

TEST(Triangle_test, Can_calculate_perimeter) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double pr = t.Calculate_perimeter();

    EXPECT_EQ(12, pr);
}

TEST(Triangle_test, Can_calculate_medianX) {
    Triangle t(0, 0, 0, 3, 3, 0);

    double x = t.Get_coordX_median();

    EXPECT_EQ(1, x);
}

TEST(Triangle_test, Can_calculate_medianY) {
    Triangle t(0, 0, 0, 3, 3, 0);

    double y = t.Get_coordY_median();

    EXPECT_EQ(1, y);
}

TEST(Triangle_test, Equal_triangle_are_equal) {
    Triangle t1(0, 0, 0, 3, 4, 0);
    Triangle t2(0, 0, 0, 3, 4, 0);

    EXPECT_EQ(t1, t2);
}

TEST(Triangle_test, Different_trieangle_not_equal) {
    Triangle t1(0, 0, 0, 3, 4, 0);
    Triangle t2(0, 0, 0, 3.1, 4, 0);

    EXPECT_TRUE(t1 != t2);
}

TEST(Triangle_test, Can_set_coordX) {
    Triangle t;
    double point_coordx = 10.11;

    t.Set_coordX_point(point_coordx, 1);

    EXPECT_EQ(point_coordx, t.Get_coordX_point(1));
}

TEST(Triangle_test, Set_coordX_throw_exception_uncorrect_number) {
    Triangle t;
    double point_coordx = 10.11;

    EXPECT_THROW(t.Set_coordX_point(point_coordx, 0), std::string);
}

TEST(Triangle_test, Set_coordX_throw_exception_uncorrect_coord) {
    Triangle t(0, 0, 0, 1, 1, 0);
    double point_coordx = 1;

    EXPECT_THROW(t.Set_coordX_point(point_coordx, 1), std::string);
}

TEST(Triangle_test, Can_set_coordY) {
    Triangle t;
    double point_coordy = 10.11;

    t.Set_coordY_point(point_coordy, 1);

    EXPECT_EQ(point_coordy, t.Get_coordY_point(1));
}

TEST(Triangle_test, Set_coordY_throw_exception_uncorrect_number) {
    Triangle t;
    double point_coordy = 10.11;

    EXPECT_THROW(t.Set_coordY_point(point_coordy, 0), std::string);
}

TEST(Triangle_test, Set_coordY_throw_exception_uncorrect_coord) {
    Triangle t(0, 0, 0, 1, 1, 0);
    double point_coordy = 1;

    EXPECT_THROW(t.Set_coordY_point(point_coordy, 1), std::string);
}

TEST(Triangle_test, Can_get_coordX) {
    Triangle t(0, 0, 1, 3, 4, 0);

    t.Get_coordX_point(1);

    EXPECT_EQ(0, t.Get_coordX_point(1));
}

TEST(Triangle_test, Get_coordX_throw_exception) {
    Triangle t;

    EXPECT_THROW(t.Get_coordX_point(0), std::string);
}

TEST(Triangle_test, Can_get_coordY) {
    Triangle t(0, 0, 1, 3, 4, 5);

    t.Get_coordY_point(1);

    EXPECT_EQ(0, t.Get_coordY_point(1));
}

TEST(Triangle_test, Get_coordY_throw_exception) {
    Triangle t;

    EXPECT_THROW(t.Get_coordY_point(0), std::string);
}

TEST(Triangle_test, Can_calculate_side1) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double side = t.Calculate_side(1);

    EXPECT_EQ(5, side);
}

TEST(Triangle_test, Can_calculate_side2) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double side = t.Calculate_side(2);

    EXPECT_EQ(4, side);
}

TEST(Triangle_test, Can_calculate_side3) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double side = t.Calculate_side(3);

    EXPECT_EQ(3, side);
}

TEST(Triangle_test, Calculate_side_throw_exception) {
    Triangle t;

    EXPECT_THROW(t.Calculate_side(0), std::string);
}

TEST(Triangle_test, Can_calculate_corner1) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double corner = t.Calculate_corner(1);

    EXPECT_NEAR(1.57, corner, 0.001);
}

TEST(Triangle_test, Can_calculate_corner2) {
    Triangle t(4, 0, 0, 0, 0, 3);

    double corner = t.Calculate_corner(2);

    EXPECT_NEAR(1.57, corner, 0.001);
}

TEST(Triangle_test, Can_calculate_corner3) {
    Triangle t(0, 3, 4, 0, 0, 0);

    double corner = t.Calculate_corner(3);

    EXPECT_NEAR(1.57, corner, 0.001);
}

TEST(Triangle_test, Calculate_corner_throw_exception) {
    Triangle t;

    EXPECT_THROW(t.Calculate_corner(0), std::string);
}
