// Copyright Kildishev Maxim 2017

#include <gtest/gtest.h>
#include "include/dichotomy.h"

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Function_Work) {
    Dichotomy obj;
    EXPECT_NO_THROW(obj.findMin(1, 0, 0, -1, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Choose_Incorrect_Left_Border) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(1, 0, 0, -0.5, -1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Choose_Incorrect_Right_Border) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(1, 0, 0, 1, 0.5, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Choose_Close_Values) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(1, 0, 0, 0.5, 0.5555555, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Throw_When_Function_Is_Zero) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(0, 1, 0, -1, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Throw_When_Function_Args_Higher_Then_INTMAX) {
         Dichotomy obj;
         EXPECT_ANY_THROW(obj.findMin(-1, 999999999 + 1, 0, -1, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests,
     Throw_When_Function_Args_Lower_Then_INTMIN) {
         Dichotomy obj;
         EXPECT_ANY_THROW(obj.findMin(-9999999999, 1, 0, -1, 1, 0.01));
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, findMin_Is_Correct) {
    Dichotomy obj;
    EXPECT_EQ(obj.findMin(1, 0, 0, -1, 1, 0.01), 0);
}

TEST(Kildishev_Maxim_Dichotomy_Method_Tests, Throw_When_Eps_Is_Zero) {
    Dichotomy obj;
    EXPECT_ANY_THROW(obj.findMin(1, 0, 0, -1, 1, 0));
}
