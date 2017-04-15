// Copyright 2017 Kuchkov Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kuchkov_Ivan_ComplexNumberTest, check_create_by_default)
{
    ComplexNumber z;

    EXPECT_DOUBLE_EQ(0.0, z.getRe());
    EXPECT_DOUBLE_EQ(0.0, z.getIm());
}

TEST(Kuchkov_Ivan_ComplexNumberTest, can_create_non_zero_number) {

    double re = 3.1415;
    double im = 2.71828;

    ComplexNumber z(re, im);

    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Kuchkov_Ivan_ComplexNumberTest, check_copy_constructor) {

    double re = 3.1415;
    double im = 2.71828;

    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);

    ASSERT_TRUE(z1 == z2);
}