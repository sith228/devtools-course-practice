// Copyright Kildishev Maxim 2017

#include <gtest/gtest.h>
#include "include/dichotomy.h"

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Function_Work) {
    Dichotomy obj;
    EXPECT_NO_THROW(obj.findMin(1, 0, 0, -1, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Choose_Incorrect_Borders) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(1, 0, 0, 10, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Choose_Too_Close_Values) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(1, 0, 0, 0.5, 0.5, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Throw_When_Function_Is_Not_Unimodal) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(0, 1, 0, -1, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, findMin_LBorder_Func_Is_Correct) {
    Dichotomy obj;
    EXPECT_EQ(obj.findMin(1, 0, 0, 0, 1, 0.01), 0.00390625);
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, findMin_RBorder_Func_Is_Correct) {
    Dichotomy obj;
    EXPECT_EQ(obj.findMin(1, 0, 0, -1, 0, 0.01), -0.00390625);
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, findMin_Is_Correct) {
    Dichotomy obj;
    EXPECT_EQ(obj.findMin(1, 0, 0, -1, 1, 0.01), 0);
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Throw_When_Eps_Is_Zero) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(1, 0, 0, -1, 1, 0));
}
