// Copyright 2017 Kuchkov Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kuchkov_Ivan_ComplexNumberTest, check_create_number_by_default) {
    ComplexNumber z;

    EXPECT_DOUBLE_EQ(0.0, z.getRe());
    EXPECT_DOUBLE_EQ(0.0, z.getIm());
}

TEST(Kuchkov_Ivan_ComplexNumberTest, check_create_non_zero_number) {

    double re = 3.1415;
    double im = 2.71828;

    ComplexNumber z(re, im);

    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Kuchkov_Ivan_ComplexNumberTest, check_is_comparison_different_number_ok){

    double re1 = 3.1415;
    double im1 = 2.71828;

    double re2 = 3.14;
    double im2 = 2.7;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ASSERT_FALSE(z1 == z2);
}

TEST(Kuchkov_Ivan_ComplexNumberTest, check_is_copy_constructor_correct){

    double re = 3.1415;
    double im = 2.71828;

    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);

    ASSERT_TRUE(z1 == z2);
}

TEST(Kuchkov_Ivan_ComplexNumberTest, check_is_assignment_operator_correct){

    double re = 3.1415;
    double im = 2.71828;

    ComplexNumber z1(re, im);
    ComplexNumber z2(0.0, 0.0);

    z2 = z1;

    ASSERT_TRUE(z1 == z2);
}