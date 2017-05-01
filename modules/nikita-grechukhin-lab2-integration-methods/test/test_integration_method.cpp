// Copyright 2017 Grechukhin Nikita

#include <gtest/gtest.h>

#include "include/integration_methods.h"
#include "include/function_parser.h"

TEST(INTEGRATION_METHOD, can_integrate_simple_function_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.rectangle_method("x", 0, 1, 50);
    double expected = 0.5;
    EXPECT_EQ(expected, actual);
}

TEST(INTEGRATION_METHOD, can_integrate_const_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.rectangle_method("2", 0, 2, 50);
    double expected = 4;
    EXPECT_EQ(expected, actual);
}

TEST(INTEGRATION_METHOD, can_integrate_function_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.rectangle_method("x*x*x*x", 0, 1, 50);
    double expected = 0.2;

    bool is_correct = (actual - 1e-3 < expected && expected < actual + 1e-3);
    EXPECT_EQ(true, is_correct);
}

TEST(INTEGRATION_METHOD, can_integrate_function_with_cos_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.rectangle_method("x*x + 4*cos(x)", 0, 1, 50);
    double expected = 3.6992;

    bool is_correct = (actual - 1e-3 < expected && expected < actual + 1e-3);
    EXPECT_EQ(true, is_correct);
}


TEST(INTEGRATION_METHOD, can_integrate_simple_function_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.trapezoid_method("x", 0, 1, 50);
    double expected = 0.5;
    EXPECT_EQ(expected, actual);
}

TEST(INTEGRATION_METHOD, can_integrate_const_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.trapezoid_method("5", 1, 3, 50);
    double expected = 10;
    EXPECT_EQ(expected, actual);
}

TEST(INTEGRATION_METHOD, can_integrate_function_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.trapezoid_method("x*x*x", 1, 4, 150);
    double expected = (0.25)*(255);

    bool is_correct = (actual - 1e-2 < expected && expected < actual + 1e-2);
    EXPECT_EQ(true, is_correct);
}

TEST(INTEGRATION_METHOD, can_integrate_function_with_sin_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.trapezoid_method("x*sin(x)", 1, 4, 150);
    double expected = 1.5566;

    bool is_correct = (actual - 1e-2 < expected && expected < actual + 1e-2);
    EXPECT_EQ(true, is_correct);
}

TEST(INTEGRATION_METHOD, can_integrate_simple_function_by_simpson_method) {
    IntegrationMethod im;
    double actual = im.simpson_method("x", 0, 1, 1e-3);
    double expected = 0.5;
    EXPECT_EQ(expected, actual);
}

TEST(INTEGRATION_METHOD, can_integrate_const_function_by_simpson_method) {
    IntegrationMethod im;
    double actual = im.simpson_method("50", 2, 4, 1e-3);
    double expected = 100;
    EXPECT_EQ(expected, actual);
}

TEST(INTEGRATION_METHOD, can_integrate_function_by_simpson_method) {
    IntegrationMethod im;
    double actual = im.simpson_method("x+x*x+3*x*x*x", 2, 4, 1e-3);
    double expected = 204.67;

    bool is_correct = (actual - 1e-2 < expected && expected < actual + 1e-2);
    EXPECT_EQ(true, is_correct);
}

TEST(INTEGRATION_METHOD, can_integrate_function_with_cos_by_simpson_method) {
    IntegrationMethod im;
    double actual =
        im.simpson_method("x+x*x+3*x*x*x + x*cos(10*x)", 3, 5, 1e-3);
    double expected = 448.84;

    bool is_correct = (actual - 1e-2 < expected && expected < actual + 1e-2);
    EXPECT_EQ(true, is_correct);
}
