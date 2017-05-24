// Copyright 2017 Dmitry Dryakhlov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Get_Real) {
    double re = 2.0, im = 4.0;
    ComplexNumber z(re, im);
    double re_control = z.getRe();
    EXPECT_EQ(re, re_control);
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Get_Im) {
    double re = 2.0, im = 4.0;
    ComplexNumber z(re, im);
    double im_control = z.getIm();
    EXPECT_EQ(im, im_control);
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Set_Re) {
    double re = 2.0, im = 4.0;
    double re_set = 3.0;
    ComplexNumber z(re, im);
    z.setRe(re_set);
    double re_control = z.getRe();
    EXPECT_EQ(re_set, re_control);
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Set_Im) {
    double re = 2.0, im = 4.0;
    double im_set = 3.0;
    ComplexNumber z(re, im);
    z.setIm(im_set);
    double im_control = z.getIm();
    EXPECT_EQ(im_set, im_control);
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Add_Complex) {
    double re_1 = 2.0, im_1 = 4.0;
    double re_2 = 3.0, im_2 = 6.0;
    ComplexNumber z_1(re_1, im_1);
    ComplexNumber z_2(re_2, im_2);
    ComplexNumber z_result(5.0, 10.0);
    ComplexNumber z_sum = z_1 + z_2;
    EXPECT_EQ(z_sum, z_result);
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Sub_Complex) {
    double re_1 = 2.0, im_1 = 4.0;
    double re_2 = 3.0, im_2 = 6.0;
    ComplexNumber z_1(re_1, im_1);
    ComplexNumber z_2(re_2, im_2);
    ComplexNumber z_result(-1.0, -2.0);
    ComplexNumber z_sum = z_1 - z_2;
    EXPECT_EQ(z_sum, z_result);
}
