// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>

#include <stdlib.h>
#include <math.h>
#include <string>

#include "include/newton-method.h"

class newton_methodTest : public ::testing::Test {
 protected:
    newton_method nMet;  
};

float f1(float x) {
    return (x*x-1);
}
float f2(float x) {
    return 2 * x;
}
float f3(float x) {
    return 2;
}

TEST_F(newton_methodTest, Can_set_conditions) {
    ASSERT_NO_THROW(nMet.setAB(0.0, 1.0));
    ASSERT_NO_THROW(nMet.setAccuracy(0.01));
}

TEST_F(newton_methodTest, Can_recognize_not_monotone_function) {
    nMet.setAB(-1.0, 1.0);
    nMet.setAccuracy(0.01);
    ASSERT_ANY_THROW(nMet.FindRoot(f1, f2, f3));
}

TEST_F(newton_methodTest, Can_recognize_not_monotone_function2) {
    nMet.setAB(-1.0, 3.0);
    nMet.setAccuracy(0.01);
    ASSERT_ANY_THROW(nMet.FindRoot(f1, f2, f3));
}

TEST_F(newton_methodTest, Can_recognize_not_monotone_function3) {
    nMet.setAB(-3.0, 1.0);
    nMet.setAccuracy(0.01);
    ASSERT_ANY_THROW(nMet.FindRoot(f1, f2, f3));
}

TEST_F(newton_methodTest, Can_recognize_monotone_function) {
    nMet.setAB(1.0, 0.0);
    nMet.setAccuracy(0.01);
    ASSERT_NO_THROW(nMet.FindRoot(f1, f2, f3));
}

TEST_F(newton_methodTest, Can_find_root) {
    nMet.setAB(0.0, 2.0);
    nMet.setAccuracy(0.01);
    ASSERT_FLOAT_EQ(nMet.FindRoot(f1, f2, f3), 1);
}

TEST_F(newton_methodTest, Can_find_root2) {
    nMet.setAB(-2.0, 0.0);
    nMet.setAccuracy(0.01);
    ASSERT_FLOAT_EQ(nMet.FindRoot(f1, f2, f3), -1);
}

TEST_F(newton_methodTest, There_isnot_root) {
    nMet.setAB(9.0, 3.0);
    nMet.setAccuracy(0.01);
    ASSERT_ANY_THROW(nMet.FindRoot(f1, f2, f3));
}

TEST_F(newton_methodTest, point_throw) {
    nMet.setAB(9.0, 9.0);
    nMet.setAccuracy(0.01);
    ASSERT_ANY_THROW(nMet.FindRoot(f1, f2, f3));
}


