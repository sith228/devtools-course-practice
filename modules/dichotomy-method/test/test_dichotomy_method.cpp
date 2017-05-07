+// Copyright Kildishev Maxim 2017

#include <gtest/gtest.h>
#include "include/dichotomy.h"

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Throw_When_Choose_Incorrect_Borders) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.FindMin(1, 0, 0, 10, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Throw_When_Choose_Too_Close_Values) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.FindMin(1, 0, 0, 0.5, 0.5, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Throw_When_Function_Is_Not_Unimodal) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.FindMin(0, 1, 0, -1, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Findmin_L_Border_Func_Is_Correct) {
    Dichotomy obj;
    EXPECT_EQ(obj.FindMin(1, 0, 0, 0, 1, 0.01), 0.00390625);
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Findmin_R_Border_Func_Is_Correct) {
    Dichotomy obj;
    EXPECT_EQ(obj.FindMin(1, 0, 0, -1, 0, 0.01), -0.00390625);
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Findmin_Is_Correct) {
    Dichotomy obj;
    EXPECT_EQ(obj.FindMin(1, 0, 0, -1, 1, 0.01), 0);
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Throw_When_Eps_Is_Zero) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.FindMin(1, 0, 0, -1, 1, 0));
}
